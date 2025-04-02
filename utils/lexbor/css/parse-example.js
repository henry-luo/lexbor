const fs = require('fs');
const path = require('path');
const Parser = require('tree-sitter');
const CSS_Grammar = require('./tree-sitter-css_grammar');

// Initialize the parser with your grammar
const parser = new Parser();
parser.setLanguage(CSS_Grammar);

// Example usage - provide a file to parse
function parseFile(filePath) {
  try {
    const content = fs.readFileSync(filePath, 'utf8');
    const tree = parser.parse(content);
    console.log('Parsing successful!');
    console.log(tree.rootNode.toString());
    return tree;
  } catch (error) {
    console.error('Error parsing file:', error);
    return null;
  }
}

// Parse an example file or input from command line
const examplePath = process.argv[2] || path.join(__dirname, 'example.txt');
if (fs.existsSync(examplePath)) {
  console.log(`Parsing file: ${examplePath}`);
  parseFile(examplePath);
} else {
  console.error(`File not found: ${examplePath}`);
  console.log('Please provide a valid file path as an argument.');
}
