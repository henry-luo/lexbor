#!/usr/bin/env node

const fs = require('fs');
const path = require('path');
const { spawn, execSync } = require('child_process');

// Import the grammar
const grammar = require('./grammar');

// Set up Tree-sitter parser
async function setupParser() {
  const Parser = require('tree-sitter');
  
  // Create directory for tree-sitter grammar if it doesn't exist
  const grammarDir = path.join(__dirname, 'tree-sitter-css-grammar');
  if (!fs.existsSync(grammarDir)) {
    fs.mkdirSync(grammarDir, { recursive: true });
  }
  
  // Copy grammar.js file to the tree-sitter directory
  fs.writeFileSync(
    path.join(grammarDir, 'grammar.js'),
    fs.readFileSync(path.join(__dirname, 'grammar.js'), 'utf8')
  );
  
  // Create package.json
  const packageJson = {
    name: 'tree-sitter-css-grammar',
    version: '0.1.0',
    description: 'CSS Grammar parser',
    main: 'bindings/node',
    dependencies: {
      nan: '^2.14.0'
    },
    devDependencies: {
      'tree-sitter-cli': '^0.20.0'
    }
  };
  
  fs.writeFileSync(
    path.join(grammarDir, 'package.json'),
    JSON.stringify(packageJson, null, 2)
  );
  
  // Install dependencies and generate parser
  console.log('Installing dependencies and generating parser...');
  execSync('npm install', { cwd: grammarDir, stdio: 'inherit' });
  execSync('npx tree-sitter generate', { cwd: grammarDir, stdio: 'inherit' });
  
  // Load the parser
  const language = await Parser.Language.load(path.join(grammarDir, 'build/Release/tree_sitter_css_grammar_binding.node'));
  
  const parser = new Parser();
  parser.setLanguage(language);
  
  return parser;
}

// Convert Tree-sitter nodes to AST
function parseToAst(node, sourceCode) {
  if (node.type === 'rule_definition') {
    const nameNode = node.child(0);
    const exprNode = node.child(2);
    return {
      type: 'rule',
      name: sourceCode.slice(nameNode.startIndex + 1, nameNode.endIndex - 1), // Remove <>
      expression: parseToAst(exprNode, sourceCode)
    };
  }
  else if (node.type === 'alternation') {
    const left = node.child(0);
    const right = node.child(2);
    return {
      type: 'alternation',
      expressions: [
        parseToAst(left, sourceCode),
        parseToAst(right, sourceCode)
      ]
    };
  }
  else if (node.type === 'combinatorial') {
    const left = node.child(0);
    const right = node.child(2);
    return {
      type: 'combinatorial',
      expressions: [
        parseToAst(left, sourceCode),
        parseToAst(right, sourceCode)
      ]
    };
  }
  else if (node.type === 'sequence') {
    const expressions = [];
    for (let i = 0; i < node.childCount; i++) {
      expressions.push(parseToAst(node.child(i), sourceCode));
    }
    return {
      type: 'sequence',
      expressions
    };
  }
  else if (node.type === 'literal') {
    return {
      type: 'literal',
      value: sourceCode.slice(node.startIndex, node.endIndex)
    };
  }
  else if (node.type === 'reference') {
    let nameNode = null;
    let permissionNode = null;
    
    for (let i = 0; i < node.childCount; i++) {
      const child = node.child(i);
      if (child.type === 'name') {
        nameNode = child;
      }
      if (child.type === 'permission') {
        permissionNode = child;
      }
    }
    
    if (!nameNode) {
      // If field name isn't found, the second child should be the name (after '<')
      nameNode = node.child(1);
    }
    
    const result = {
      type: 'reference',
      name: sourceCode.slice(nameNode.startIndex, nameNode.endIndex),
    };
    
    // Add constraints
    const constraints = {};
    for (let i = 0; i < node.childCount; i++) {
      const child = node.child(i);
      if (child.type === 'constraint_name') {
        const key = sourceCode.slice(child.startIndex, child.endIndex);
        const valueNode = node.child(i + 2);
        const value = sourceCode.slice(valueNode.startIndex, valueNode.endIndex);
        constraints[key] = value.includes('.') ? parseFloat(value) : parseInt(value);
      }
    }
    
    if (Object.keys(constraints).length > 0) {
      result.constraints = constraints;
    }
    
    // Add permissions
    if (permissionNode) {
      result.permissions = [sourceCode.slice(permissionNode.startIndex, permissionNode.endIndex)];
    }
    
    return result;
  }
  else if (node.type === 'group') {
    const inner = node.child(1);
    return {
      type: 'grouping',
      expression: parseToAst(inner, sourceCode)
    };
  }
  else if (node.type === 'repetition') {
    const atom = node.child(0);
    const operator = node.child(1);
    
    if (operator.type === '*') {
      return {
        type: 'zero_or_more',
        expression: parseToAst(atom, sourceCode)
      };
    }
    else if (operator.type === '+') {
      return {
        type: 'one_or_more',
        expression: parseToAst(atom, sourceCode)
      };
    }
    else if (operator.type === '#') {
      return {
        type: 'one_or_more_comma',
        expression: parseToAst(atom, sourceCode)
      };
    }
    else {
      let minNode = null;
      let maxNode = null;
      
      for (let i = 0; i < node.childCount; i++) {
        const child = node.child(i);
        if (child.type === 'min') {
          minNode = child;
        }
        if (child.type === 'max') {
          maxNode = child;
        }
      }
      
      const min = parseInt(sourceCode.slice(minNode.startIndex, minNode.endIndex));
      let max = min;
      
      if (maxNode) {
        max = parseInt(sourceCode.slice(maxNode.startIndex, maxNode.endIndex));
      }
      
      return {
        type: 'repetition',
        expression: parseToAst(atom, sourceCode),
        min: min,
        max: max
      };
    }
  }
  else if (node.type === 'optional') {
    const atom = node.child(0);
    return {
      type: 'optional',
      expression: parseToAst(atom, sourceCode)
    };
  }
  else if (node.type === 'source_file') {
    const rules = {};
    
    for (let i = 0; i < node.childCount; i++) {
      const child = node.child(i);
      if (child.type === 'rule_definition') {
        const rule = parseToAst(child, sourceCode);
        rules[rule.name] = rule.expression;
      }
    }
    
    return {
      type: 'grammar',
      rules: rules
    };
  }
  else {
    // For other node types, just return children
    if (node.childCount === 1) {
      return parseToAst(node.child(0), sourceCode);
    }
    
    const children = [];
    for (let i = 0; i < node.childCount; i++) {
      children.push(parseToAst(node.child(i), sourceCode));
    }
    
    return {
      type: node.type,
      children: children
    };
  }
}

async function main() {
  // Define file paths
  const grammarFile = path.join(__dirname, 'grammar.txt');
  const outputFile = path.join(__dirname, 'grammar.json');
  
  // Ensure the grammar file exists
  if (!fs.existsSync(grammarFile)) {
    console.error(`Error: Grammar file not found at ${grammarFile}`);
    process.exit(1);
  }
  
  try {
    console.log(`Parsing grammar from ${grammarFile}...`);
    const parser = await setupParser();
    
    // Read the grammar file
    const sourceCode = fs.readFileSync(grammarFile, 'utf8');
    
    // Parse the file
    const tree = parser.parse(sourceCode);
    
    // Convert to AST
    const ast = parseToAst(tree.rootNode, sourceCode);
    
    // Write to JSON file
    fs.writeFileSync(outputFile, JSON.stringify(ast, null, 2));
    
    console.log(`Successfully parsed grammar. AST saved to ${outputFile}`);
    console.log(`Found ${Object.keys(ast.rules).length} rules in the grammar.`);
    
    // Print some statistics about the grammar
    const ruleTypes = {};
    for (const ruleName in ast.rules) {
      const ruleType = ast.rules[ruleName]?.type || 'unknown';
      ruleTypes[ruleType] = (ruleTypes[ruleType] || 0) + 1;
    }
    
    console.log("\nRule expression types:");
    for (const ruleType in ruleTypes) {
      console.log(`  ${ruleType}: ${ruleTypes[ruleType]}`);
    }
    
  } catch (error) {
    console.error('Error processing grammar:', error);
    process.exit(1);
  }
}

main();
