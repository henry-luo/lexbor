import sys
import os
import unittest
from css_grammar_parser import Lexer, Parser, TokenType, parse_css_grammar # generate_grammar_text

class CSSGrammarParserTest(unittest.TestCase):
    """Test cases for the CSS Grammar Parser"""
    
    def test_lexer_basic(self):
        """Test that the lexer properly tokenizes simple inputs"""
        text = "<rule> = value1 | value2"
        lexer = Lexer(text)
        tokens = lexer.tokenize()
        
        # Check that we have the expected tokens
        token_types = [token.type for token in tokens]
        expected_types = [
            TokenType.OPEN_ANGLE, TokenType.IDENTIFIER, TokenType.CLOSE_ANGLE,
            TokenType.WHITESPACE, TokenType.EQUALS, TokenType.WHITESPACE,
            TokenType.IDENTIFIER, TokenType.WHITESPACE, TokenType.PIPE,
            TokenType.WHITESPACE, TokenType.IDENTIFIER, TokenType.EOF
        ]
        
        self.assertEqual(token_types, expected_types)
    
    def test_lexer_complex(self):
        """Test that the lexer handles complex constructs"""
        text = "<complex> = [ <length> || <percentage> ]{1,4} && <color>/1"
        lexer = Lexer(text)
        tokens = lexer.tokenize()
        
        # Check that the lexer identifies all special characters
        self.assertIn(TokenType.OPEN_BRACKET, [t.type for t in tokens])
        self.assertIn(TokenType.DOUBLE_PIPE, [t.type for t in tokens])
        self.assertIn(TokenType.CLOSE_BRACKET, [t.type for t in tokens])
        self.assertIn(TokenType.OPEN_BRACE, [t.type for t in tokens])
        self.assertIn(TokenType.DOUBLE_AMPERSAND, [t.type for t in tokens])
        self.assertIn(TokenType.SLASH, [t.type for t in tokens])
    
    def test_parser_simple_rule(self):
        """Test parsing a simple rule"""
        text = "<rule> = value"
        lexer = Lexer(text)
        tokens = lexer.tokenize()
        
        parser = Parser(tokens)
        rules = parser.parse()
        
        self.assertEqual(len(rules), 1)
        self.assertEqual(rules[0].name, "rule")
        self.assertEqual(rules[0].value.value, "value")
    
    def test_parser_value_list(self):
        """Test parsing a rule with value list (OR operator)"""
        text = "<options> = option1 | option2 | option3"
        lexer = Lexer(text)
        tokens = lexer.tokenize()
        
        parser = Parser(tokens)
        rules = parser.parse()
        
        self.assertEqual(len(rules), 1)
        self.assertEqual(rules[0].name, "options")
        self.assertEqual(len(rules[0].value.values), 3)
        self.assertEqual(rules[0].value.operator, "|")
    
    def test_parser_reference(self):
        """Test parsing a rule with references to other rules"""
        text = "<combined> = <rule1> | <rule2>"
        lexer = Lexer(text)
        tokens = lexer.tokenize()
        
        parser = Parser(tokens)
        rules = parser.parse()
        
        self.assertEqual(len(rules), 1)
        self.assertEqual(rules[0].name, "combined")
        self.assertEqual(rules[0].value.values[0].name, "rule1")
        self.assertEqual(rules[0].value.values[1].name, "rule2")
    
    def test_parser_constraints(self):
        """Test parsing references with constraints"""
        text = "<constrained> = <value min=0 max=100>"
        lexer = Lexer(text)
        tokens = lexer.tokenize()
        
        parser = Parser(tokens)
        rules = parser.parse()
        
        self.assertEqual(len(rules), 1)
        self.assertEqual(rules[0].name, "constrained")
        self.assertEqual(rules[0].value.name, "value")
        self.assertEqual(rules[0].value.constraints["min"], 0)
        self.assertEqual(rules[0].value.constraints["max"], 100)
    
    def test_multiline_rule(self):
        """Test parsing a multi-line rule"""
        text = """<multi-line> = line1 |
                  line2 |
                  line3"""
        lexer = Lexer(text)
        tokens = lexer.tokenize()
        
        parser = Parser(tokens)
        rules = parser.parse()
        
        self.assertEqual(len(rules), 1)
        self.assertEqual(rules[0].name, "multi-line")
        self.assertEqual(len(rules[0].value.values), 3)
    
#     def test_small_grammar_file(self):
#         """Test parsing a small but complete grammar file"""
#         text = """<global> = initial | inherit | unset | revert
# <length> = <number> <units> | 0
# <units> = px | em | rem
# <color> = <hex-color> | <named-color>
# <hex-color> = #[<hex>{3} | <hex>{6}]
# <named-color> = red | green | blue | black | white"""
        
#         lexer = Lexer(text)
#         tokens = lexer.tokenize()
        
#         parser = Parser(tokens)
#         rules = parser.parse()
        
#         self.assertEqual(len(rules), 6)
#         # Check that all rule names were extracted correctly
#         rule_names = [rule.name for rule in rules]
#         expected_names = ["global", "length", "units", "color", "hex-color", "named-color"]
#         self.assertEqual(set(rule_names), set(expected_names))
        
#         # Test the grammar text generation
#         from tempfile import NamedTemporaryFile
#         with NamedTemporaryFile(suffix='.txt', delete=False) as temp:
#             generate_grammar_text(rules, temp.name)
#             with open(temp.name, 'r') as f:
#                 generated_text = f.read()
            
#             # Check that each rule is represented in the output
#             for name in expected_names:
#                 self.assertIn(f"<{name}>", generated_text)
        
#         os.unlink(temp.name)  # Clean up the temporary file


if __name__ == "__main__":
    # Check if -v flag was passed
    if '-v' in sys.argv or '--verbose' in sys.argv:
        verbosity = 2
    else:
        verbosity = 1
    
    # Load all tests from the CSSGrammarParserTest class
    suite = unittest.TestLoader().loadTestsFromTestCase(CSSGrammarParserTest)
    
    # Run the tests with the specified verbosity and capture the result
    result = unittest.TextTestRunner(verbosity=verbosity).run(suite)
    
    # Print a summary of the test results
    print("\n=== TEST SUMMARY ===")
    print(f"Ran {result.testsRun} tests in total")
    print(f"Successful tests: {result.testsRun - len(result.errors) - len(result.failures)}")
    print(f"Failed tests: {len(result.failures)}")
    print(f"Errors: {len(result.errors)}")
    if hasattr(result, 'skipped'):
        print(f"Skipped tests: {len(result.skipped)}")
    
    # Set exit code based on test results
    sys.exit(len(result.failures) > 0 or len(result.errors) > 0)
