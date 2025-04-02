#!/usr/bin/env node

const fs = require('fs');
const path = require('path');
const { spawn, execSync } = require('child_process');

// Convert Tree-sitter nodes to AST
function parseToAst(node, sourceCode) {
  // Add null check at the beginning
  if (!node) {
    console.warn('Encountered null node during parsing');
    return { type: 'unknown' };
  }
  
  // Ensure node has a type property
  if (typeof node.type !== 'string') {
    console.warn(`Node missing type property: ${JSON.stringify(node).substring(0, 100)}...`);
    return { type: 'unknown', raw: node };
  }

  if (node.type === 'rule_definition') {
    // Find child nodes by type instead of fixed position
    let nameNode = null;
    let exprNode = null;
    
    // Debugging: log all children
    console.log(`Rule definition has ${node.childCount} children`);
    for (let i = 0; i < node.childCount; i++) {
      const child = node.child(i);
      console.log(`  Child ${i}: ${child ? child.type : 'null'}`);
      
      if (child) {
        if (child.type === 'rule_name') {
          nameNode = child;
        } else if (child.type === 'expression') {
          exprNode = child;
        }
      }
    }
    
    // Fallback: try fixed positions if type matching failed
    if (!nameNode && node.childCount > 0) nameNode = node.child(0);
    if (!exprNode && node.childCount > 1) exprNode = node.child(1);
    
    // Add null checks for child nodes
    if (!nameNode || !exprNode) {
      console.warn(`Missing required child nodes in rule_definition: ${nameNode ? 'has name' : 'no name'}, ${exprNode ? 'has expr' : 'no expr'}`);
      
      // Create a partial rule with available information
      const result = { type: 'rule' };
      if (nameNode) {
        let ruleName = sourceCode.slice(nameNode.startIndex, nameNode.endIndex);
        // Remove angle brackets if present
        ruleName = ruleName.replace(/^<|>$/g, '');
        result.name = ruleName;
      }
      return result;
    }
    
    // Extract rule name - handle both with and without angle brackets
    let ruleName = sourceCode.slice(nameNode.startIndex, nameNode.endIndex);
    // Remove angle brackets if present
    ruleName = ruleName.replace(/^<|>$/g, '');
    
    return {
      type: 'rule',
      name: ruleName,
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
      if (child && child.type === 'rule_definition') {
        const rule = parseToAst(child, sourceCode);
        if (rule && rule.type === 'rule' && rule.name) {
          rules[rule.name] = rule.expression || { type: 'unknown' };
        }
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

// Parse the S-expression output from tree-sitter into a node structure
function parseSExpression(sexp) {
  // Add safety check for empty input
  if (!sexp || typeof sexp !== 'string') {
    console.error('Invalid S-expression input:', sexp);
    return null;
  }
  
  // Strip ANSI color codes which tree-sitter CLI might include
  sexp = sexp.replace(/\x1B\[\d+m/g, '');
  
  // Extract node type and range info from the S-expression
  const match = sexp.match(/\((\w+)(?:\s+\[(\d+), (\d+)\] - \[(\d+), (\d+)\])?/);
  
  if (!match) {
    console.warn(`Failed to parse S-expression: ${sexp.substring(0, 100)}...`);
    return null;
  }
  
  const nodeType = match[1];
  const startPos = match[2] ? parseInt(match[2]) : 0;
  const startCol = match[3] ? parseInt(match[3]) : 0;
  const endPos = match[4] ? parseInt(match[4]) : 0;
  const endCol = match[5] ? parseInt(match[5]) : 0;
  
  // Build a structure that mimics tree-sitter's Node API
  const node = {
    type: nodeType,
    startIndex: startPos,
    endIndex: endPos,
    children: [],
    
    child: function(index) {
      return this.children[index] || null;
    },
    
    get childCount() {
      return this.children.length;
    }
  };
  
  // Find child nodes by parsing nested S-expressions
  // Use a more robust parsing approach
  try {
    let depth = 0;
    let start = -1;
    let inString = false;
    let escapeNext = false;
    
    for (let i = 0; i < sexp.length; i++) {
      // Handle string literals properly
      if (sexp[i] === '"' && !escapeNext) {
        inString = !inString;
      } else if (sexp[i] === '\\' && inString) {
        escapeNext = true;
        continue;
      }
      
      escapeNext = false;
      
      // Only count parentheses outside of strings
      if (!inString) {
        if (sexp[i] === '(') {
          depth++;
          if (depth === 2) {
            start = i;
          }
        } else if (sexp[i] === ')') {
          if (depth === 2 && start !== -1) {
            const childSexp = sexp.substring(start, i + 1);
            const childNode = parseSExpression(childSexp);
            if (childNode) {
              node.children.push(childNode);
            }
            start = -1;
          }
          depth--;
        }
      }
    }
  } catch (error) {
    console.error('Error parsing S-expression children:', error);
  }
  
  return node;
}

// Add a debug function to print node structure
function debugNode(node, indent = 0) {
  if (!node) return;
  
  const spacing = ' '.repeat(indent * 2);
  console.log(`${spacing}Node: ${node.type} [${node.startIndex}:${node.endIndex}]`);
  
  for (let i = 0; i < node.childCount; i++) {
    const child = node.child(i);
    if (child) {
      debugNode(child, indent + 1);
    }
  }
}

async function invokeParser() {
  return {
    parse: function(sourceCode, grammarFilePath) {
      // Use the provided grammar file path or default to grammar.txt
      const tempFile = grammarFilePath || path.join(__dirname, 'grammar.txt');
      
      // Save the grammar content to the file
      fs.writeFileSync(tempFile, sourceCode);
      
      try {
        console.log('Invoking tree-sitter parse command...');
        console.log(`Using grammar file: ${path.basename(tempFile)}`);
        
        // Try to use the grammar.js to generate the parser first
        try {
          console.log('Attempting to generate parser from grammar.js...');
          execSync('npx tree-sitter generate', {
            cwd: __dirname,
            stdio: 'inherit'
          });
        } catch (genError) {
          console.warn('Warning: Could not generate parser from grammar.js:', genError.message);
        }
        
        // Get the S-expression output from tree-sitter CLI
        let sexpOutput;
        try {
          sexpOutput = execSync(`npx tree-sitter parse "${tempFile}"`, {
            cwd: __dirname,
            encoding: 'utf8'
          });
        } catch (parseError) {
          console.error('Tree-sitter parse command failed:', parseError.message);
          console.log('Trying alternative approach...');
          
          // Try with a different approach - parse using the grammar.js directly
          sexpOutput = execSync(`npx tree-sitter parse "${tempFile}" --quiet`, {
            cwd: __dirname,
            encoding: 'utf8'
          });
        }
        
        if (!sexpOutput || sexpOutput.trim().length === 0) {
          console.error('Tree-sitter returned empty output');
          throw new Error('Empty parser output');
        }
        
        console.log(`Tree-sitter output length: ${sexpOutput.length} bytes`);
        console.log(`First 100 chars: ${sexpOutput.substring(0, 100)}...`);
        
        // Convert S-expression to a node structure
        const rootNode = parseSExpression(sexpOutput);
        
        if (!rootNode) {
          console.error('Failed to parse S-expression into node structure');
          throw new Error('S-expression parsing failed');
        }
        
        console.log('Root node structure:');
        debugNode(rootNode, 0);
        
        return {
          rootNode: rootNode
        };
      } catch (error) {
        console.error('Error running tree-sitter parse command:', error);
        throw error;
      }
    }
  };
}

async function main() {
  // Use command line args if provided, otherwise use defaults
  const args = process.argv.slice(2);
  const grammarFile = args[0] || path.join(__dirname, 'grammar.test.txt');
  const outputFile = args[1] || path.join(__dirname, 'grammar.output.json');
  
  // Check if we should use the grammar.js file directly
  const useGrammarJs = args.includes('--use-grammar-js');
  
  // Try to locate the grammar file - check multiple options
  const possibleFiles = [
    grammarFile,
    path.join(__dirname, 'grammar.test.txt'),
    path.join(__dirname, 'grammar.txt'),
    path.join(__dirname, 'grammar.js')
  ];
  
  let actualGrammarFile = null;
  
  for (const file of possibleFiles) {
    if (fs.existsSync(file)) {
      actualGrammarFile = file;
      break;
    }
  }
  
  if (!actualGrammarFile) {
    console.error(`Error: No grammar file found. Checked: ${possibleFiles.join(', ')}`);
    process.exit(1);
  }
  
  console.log(`Found grammar file: ${actualGrammarFile}`);
  
  try {
    console.log(`Parsing grammar from ${actualGrammarFile}...`);
    const parser = await invokeParser();
    
    // Read the grammar file
    const sourceCode = fs.readFileSync(actualGrammarFile, 'utf8');
    console.log(`Grammar file loaded: ${sourceCode.length} bytes`);
    console.log(`First 100 chars: ${sourceCode.substring(0, 100)}...`);
    
    // Parse the file
    const tree = parser.parse(sourceCode, actualGrammarFile);
    
    if (!tree || !tree.rootNode) {
      throw new Error('Parser returned null or invalid tree');
    }
    
    console.log(`Tree parsed successfully. Root node type: ${tree.rootNode.type}`);
    console.log(`Child count: ${tree.rootNode.childCount}`);
    
    // Convert to AST with detailed logging
    console.log('Converting tree to AST...');
    let ast;
    try {
      ast = parseToAst(tree.rootNode, sourceCode);
      console.log('AST conversion completed');
    } catch (astError) {
      console.error('Error during AST conversion:', astError);
      throw astError;
    }
    
    // Write to JSON file
    fs.writeFileSync(outputFile, JSON.stringify(ast, null, 2));
    
    console.log(`Successfully parsed grammar. AST saved to ${outputFile}`);
    
    // Additional safety check for rules
    if (ast && ast.rules) {
      const ruleCount = Object.keys(ast.rules).length;
      console.log(`Found ${ruleCount} rules in the grammar.`);
      
      if (ruleCount === 0) {
        console.warn('WARNING: No rules were found in the parsed grammar!');
        console.warn('This likely means the tree-sitter parser did not recognize rule definitions.');
        console.warn('Check if your grammar file format matches what the parser expects.');
      } else {
        // Print some statistics about the grammar
        const ruleTypes = {};
        for (const ruleName in ast.rules) {
          if (!ast.rules[ruleName]) continue;
          const ruleType = ast.rules[ruleName]?.type || 'unknown';
          ruleTypes[ruleType] = (ruleTypes[ruleType] || 0) + 1;
        }
        
        console.log("\nRule expression types:");
        for (const ruleType in ruleTypes) {
          console.log(`  ${ruleType}: ${ruleTypes[ruleType]}`);
        }
      }
    } else {
      console.warn('No rules found in parsed grammar');
    }
    
  } catch (error) {
    console.error('Error processing grammar:', error);
    console.error('Stack trace:', error.stack);
    process.exit(1);
  }
}

main();
