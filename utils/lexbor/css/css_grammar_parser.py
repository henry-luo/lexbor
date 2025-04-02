import re
import json
from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Union, Optional, Any
import sys


class TokenType(Enum):
    IDENTIFIER = 'IDENTIFIER'
    EQUALS = 'EQUALS'
    PIPE = 'PIPE'
    DOUBLE_PIPE = 'DOUBLE_PIPE'
    DOUBLE_AMPERSAND = 'DOUBLE_AMPERSAND'
    COMMA = 'COMMA'
    OPEN_BRACKET = 'OPEN_BRACKET'
    CLOSE_BRACKET = 'CLOSE_BRACKET'
    OPEN_PAREN = 'OPEN_PAREN'
    CLOSE_PAREN = 'CLOSE_PAREN'
    OPEN_ANGLE = 'OPEN_ANGLE'
    CLOSE_ANGLE = 'CLOSE_ANGLE'
    HASH = 'HASH'
    QUESTION = 'QUESTION'
    PLUS = 'PLUS'
    ASTERISK = 'ASTERISK'
    SLASH = 'SLASH'
    CARET = 'CARET'
    STRING = 'STRING'
    NUMBER = 'NUMBER'
    OPEN_BRACE = 'OPEN_BRACE'
    CLOSE_BRACE = 'CLOSE_BRACE'
    NEWLINE = 'NEWLINE'
    COMMENT = 'COMMENT'
    WHITESPACE = 'WHITESPACE'
    EOF = 'EOF'


@dataclass
class Token:
    type: TokenType
    value: str
    line: int
    column: int


@dataclass
class Node:
    def to_dict(self) -> Dict:
        result = {"type": self.__class__.__name__}
        for key, value in vars(self).items():
            if isinstance(value, Node):
                result[key] = value.to_dict()
            elif isinstance(value, list):
                result[key] = [item.to_dict() if isinstance(item, Node) else item for item in value]
            elif isinstance(value, dict):
                result[key] = {k: v.to_dict() if isinstance(v, Node) else v for k, v in value.items()}
            else:
                result[key] = value
        return result


@dataclass
class Rule(Node):
    name: str
    value: Any


@dataclass
class ValueList(Node):
    values: List[Any]
    operator: str


@dataclass
class Reference(Node):
    name: str
    constraints: Dict[str, Any] = field(default_factory=dict)


@dataclass
class Optional(Node):
    value: Any


@dataclass
class Repetition(Node):
    value: Any
    min_occurrences: int
    max_occurrences: Union[int, None] = None
    separator: Union[str, None] = None


@dataclass
class Group(Node):
    value: Any


@dataclass
class Literal(Node):
    value: str


@dataclass
class Function(Node):
    name: str
    arguments: List[Any]


@dataclass
class Directive(Node):
    name: str
    value: Any = None


class Lexer:
    def __init__(self, text: str):
        self.text = text
        self.position = 0
        self.line = 1
        self.column = 1
        self.tokens = []
        self.last_progress = 0

    def tokenize(self) -> List[Token]:
        print(f"Starting tokenization of {len(self.text)} characters...")
        while self.position < len(self.text):
            progress = int(self.position / len(self.text) * 100)
            if progress >= self.last_progress + 5:
                print(f"Tokenizing: {progress}% complete - at line {self.line}")
                self.last_progress = progress

            current_char = self.text[self.position]

            if current_char == '/' and self.peek(1) == '*':
                self._consume_comment()
                continue

            if current_char.isspace():
                if current_char == '\n':
                    self.tokens.append(Token(TokenType.NEWLINE, '\n', self.line, self.column))
                    self.position += 1
                    self.line += 1
                    self.column = 1
                else:
                    self.tokens.append(Token(TokenType.WHITESPACE, current_char, self.line, self.column))
                    self.position += 1
                    self.column += 1
                continue

            if current_char.isalpha() or current_char == '-' or current_char == '_':
                self._consume_identifier()
                continue

            if current_char.isdigit() or (current_char == '.' and self.peek(1).isdigit()):
                self._consume_number()
                continue

            if current_char in ['"', "'"]:
                self._consume_string()
                continue

            if current_char == '<':
                self.tokens.append(Token(TokenType.OPEN_ANGLE, '<', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '>':
                self.tokens.append(Token(TokenType.CLOSE_ANGLE, '>', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '=':
                self.tokens.append(Token(TokenType.EQUALS, '=', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '|':
                if self.peek(1) == '|':
                    self.tokens.append(Token(TokenType.DOUBLE_PIPE, '||', self.line, self.column))
                    self.position += 2
                    self.column += 2
                else:
                    self.tokens.append(Token(TokenType.PIPE, '|', self.line, self.column))
                    self.position += 1
                    self.column += 1
            elif current_char == '&' and self.peek(1) == '&':
                self.tokens.append(Token(TokenType.DOUBLE_AMPERSAND, '&&', self.line, self.column))
                self.position += 2
                self.column += 2
            elif current_char == '[':
                self.tokens.append(Token(TokenType.OPEN_BRACKET, '[', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == ']':
                self.tokens.append(Token(TokenType.CLOSE_BRACKET, ']', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '(':
                self.tokens.append(Token(TokenType.OPEN_PAREN, '(', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == ')':
                self.tokens.append(Token(TokenType.CLOSE_PAREN, ')', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '{':
                self.tokens.append(Token(TokenType.OPEN_BRACE, '{', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '}':
                self.tokens.append(Token(TokenType.CLOSE_BRACE, '}', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == ',':
                self.tokens.append(Token(TokenType.COMMA, ',', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '#':
                self.tokens.append(Token(TokenType.HASH, '#', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '?':
                self.tokens.append(Token(TokenType.QUESTION, '?', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '+':
                self.tokens.append(Token(TokenType.PLUS, '+', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '*':
                self.tokens.append(Token(TokenType.ASTERISK, '*', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '/':
                self.tokens.append(Token(TokenType.SLASH, '/', self.line, self.column))
                self.position += 1
                self.column += 1
            elif current_char == '^':
                self.tokens.append(Token(TokenType.CARET, '^', self.line, self.column))
                self.position += 1
                self.column += 1
            else:
                self.position += 1
                self.column += 1

        self.tokens.append(Token(TokenType.EOF, "", self.line, self.column))
        print(f"Tokenization complete: {len(self.tokens)} tokens generated")
        return self.tokens

    def peek(self, offset=1):
        if self.position + offset < len(self.text):
            return self.text[self.position + offset]
        return ''

    def _consume_comment(self):
        start_line = self.line
        start_column = self.column
        content = ""

        self.position += 2
        self.column += 2

        while self.position < len(self.text):
            if self.text[self.position] == '*' and self.peek(1) == '/':
                self.position += 2
                self.column += 2
                break

            if self.text[self.position] == '\n':
                content += self.text[self.position]
                self.position += 1
                self.line += 1
                self.column = 1
            else:
                content += self.text[self.position]
                self.position += 1
                self.column += 1

        self.tokens.append(Token(TokenType.COMMENT, content, start_line, start_column))

    def _consume_identifier(self):
        start = self.position
        start_line = self.line
        start_column = self.column

        while (self.position < len(self.text) and 
               (self.text[self.position].isalnum() or 
                self.text[self.position] in '-_')):
            self.position += 1
            self.column += 1

        value = self.text[start:self.position]
        self.tokens.append(Token(TokenType.IDENTIFIER, value, start_line, start_column))

    def _consume_number(self):
        start = self.position
        start_line = self.line
        start_column = self.column

        if self.text[self.position] == '.':
            self.position += 1
            self.column += 1

        while self.position < len(self.text) and self.text[self.position].isdigit():
            self.position += 1
            self.column += 1

        if self.position < len(self.text) and self.text[self.position] == '.':
            self.position += 1
            self.column += 1
            while self.position < len(self.text) and self.text[self.position].isdigit():
                self.position += 1
                self.column += 1

        value = self.text[start:self.position]
        self.tokens.append(Token(TokenType.NUMBER, value, start_line, start_column))

    def _consume_string(self):
        start = self.position
        start_line = self.line
        start_column = self.column
        quote = self.text[self.position]

        self.position += 1
        self.column += 1

        while (self.position < len(self.text) and 
               self.text[self.position] != quote):
            if self.text[self.position] == '\n':
                self.line += 1
                self.column = 1
            else:
                self.column += 1
            self.position += 1

        if self.position < len(self.text):
            self.position += 1
            self.column += 1

        value = self.text[start:self.position]
        self.tokens.append(Token(TokenType.STRING, value, start_line, start_column))


class Parser:
    def __init__(self, tokens):
        self.tokens = tokens
        self.current = 0
        self.rule_count = 0

    def parse(self):
        print(f"Starting to parse {len(self.tokens)} tokens...")
        rules = []

        # Safety mechanism to prevent infinite loops
        max_iterations = len(self.tokens) * 2
        iterations = 0
        last_position = -1  # Track last position to detect when we're stuck
        stuck_count = 0     # Count how many iterations we've been stuck

        while not self._is_at_end() and iterations < max_iterations:
            iterations += 1
            
            # Detect if we're stuck in the same position
            if self.current == last_position:
                stuck_count += 1
                if stuck_count > 5:  # If we're stuck for too many iterations
                    print(f"WARNING: Parser appears to be stuck at position {self.current}, token: {self._current().type}")
                    print(f"Skipping this token and continuing...")
                    self._advance()  # Force advance
                    stuck_count = 0
            else:
                stuck_count = 0
                last_position = self.current

            if iterations % 1000 == 0:
                print(f"Parsing... processed {iterations} iterations, current position: {self.current}/{len(self.tokens)}")
                print(f"Current token: {self._current().type} at line {self._current().line}, column {self._current().column}")

            # Skip whitespace, comments, newlines
            if self._check(TokenType.COMMENT) or self._check(TokenType.WHITESPACE) or self._check(TokenType.NEWLINE):
                self._advance()
                continue

            # Parse a rule if we encounter an opening angle bracket
            if self._check(TokenType.OPEN_ANGLE):
                rule = self._parse_rule()
                rules.append(rule)
                self.rule_count += 1
                if self.rule_count % 5 == 0:
                    print(f"Parsed {self.rule_count} rules so far")
            else:
                # If we're not at a rule start and not at whitespace, skip this token
                print(f"Unexpected token outside rule definition: {self._current().type} at line {self._current().line}, column {self._current().column}")
                self._advance()

        if iterations >= max_iterations:
            print("WARNING: Maximum iteration count reached. Possible infinite loop detected.")
            print(f"Current token: {self._current().type} at line {self._current().line}, column {self._current().column}")
            print("Parser will return what it has parsed so far.")
            
        print(f"Parsing complete: {len(rules)} rules found")
        return rules

    def _parse_rule(self):
        """Parse a CSS grammar rule that may span multiple lines"""
        print(f"Parsing rule at token position {self.current}")
        self._consume(TokenType.OPEN_ANGLE, "Expected '<' for rule name")

        name_tokens = []
        while not self._check(TokenType.CLOSE_ANGLE) and not self._is_at_end():
            name_tokens.append(self._current().value)
            self._advance()

        name = ''.join(name_tokens)
        self._consume(TokenType.CLOSE_ANGLE, "Expected '>' to close rule name")
        print(f"Rule name: {name}")

        self._skip_whitespace()

        self._consume(TokenType.EQUALS, "Expected '=' after rule name")

        self._skip_whitespace()

        print(f"Parsing value for rule {name}")
        value = self._parse_expression()
        
        # Make sure we skip any trailing whitespace after a rule
        self._skip_whitespace()
        
        print(f"Completed parsing rule: {name}")

        return Rule(name=name, value=value)

    def _parse_expression(self):
        """Parse a value expression, which could be a list of alternatives or a single value"""
        print(f"Parsing expression at position {self.current}, token: {self._current().type}")
        
        try:
            left = self._parse_term()
            
            # Skip whitespace after parsing a term
            self._skip_whitespace()
    
            if self._match([TokenType.PIPE, TokenType.DOUBLE_PIPE, TokenType.DOUBLE_AMPERSAND]):
                operator = self._previous().value
                values = [left]
                
                # Skip whitespace after the operator
                self._skip_whitespace()
    
                max_iterations = 1000
                iterations = 0
    
                while iterations < max_iterations:
                    iterations += 1
                    
                    # Exit conditions - special handling for the end of an expression
                    if self._is_at_end() or self._check(TokenType.EOF):
                        break
                    
                    # Check for tokens that would indicate the end of the current expression
                    # This includes closing brackets, parentheses, or the start of a new rule
                    if self._check(TokenType.CLOSE_BRACKET) or self._check(TokenType.CLOSE_PAREN):
                        break
                    
                    # Handle line breaks within expressions
                    if self._check(TokenType.NEWLINE):
                        # Skip newlines that don't end the current rule
                        next_pos = self.current + 1
                        while (next_pos < len(self.tokens) and
                              (self.tokens[next_pos].type == TokenType.WHITESPACE or 
                               self.tokens[next_pos].type == TokenType.COMMENT or
                               self.tokens[next_pos].type == TokenType.NEWLINE)):
                            next_pos += 1
                        
                        # If we see a new rule start (<...>), this newline ends the current rule
                        if next_pos < len(self.tokens):
                            if self.tokens[next_pos].type == TokenType.OPEN_ANGLE:
                                break
                            # If we see a closing bracket or similar, this might end the expression
                            elif (self.tokens[next_pos].type == TokenType.CLOSE_BRACKET or
                                  self.tokens[next_pos].type == TokenType.CLOSE_PAREN):
                                break
                        
                        # Otherwise, treat newline as whitespace and continue
                        self._advance()
                        self._skip_whitespace()
                        continue
                    
                    # Exit conditions for operators - if we don't see the proper operator, stop
                    if ((operator == '|' and not self._check(TokenType.PIPE)) or
                        (operator == '||' and not self._check(TokenType.DOUBLE_PIPE)) or
                        (operator == '&&' and not self._check(TokenType.DOUBLE_AMPERSAND))):
                        break
    
                    # Consume the operator
                    if operator == '|':
                        self._consume(TokenType.PIPE, "Expected '|'")
                    elif operator == '||':
                        self._consume(TokenType.DOUBLE_PIPE, "Expected '||'")
                    else:
                        self._consume(TokenType.DOUBLE_AMPERSAND, "Expected '&&'")
                        
                    self._skip_whitespace()
                    values.append(self._parse_term())
                    self._skip_whitespace()  # Skip whitespace after each term
    
                if iterations >= max_iterations:
                    print(f"WARNING: Possible infinite loop in _parse_expression with operator {operator}")
                    
                return ValueList(values=values, operator=operator)
            
            return left
        except Exception as e:
            print(f"Error in _parse_expression: {str(e)}")
            raise

    def _parse_term(self):
        """Parse a term which could be a reference, literal, function, etc."""
        print(f"Parsing term at position {self.current}, token: {self._current().type}")
        
        if self._match([TokenType.OPEN_ANGLE]):
            return self._parse_reference()
        elif self._match([TokenType.OPEN_BRACKET]):
            return self._parse_optional()
        elif self._match([TokenType.OPEN_PAREN]):
            return self._parse_group()
        elif self._match([TokenType.IDENTIFIER, TokenType.STRING, TokenType.NUMBER]):
            value = Literal(value=self._previous().value)
            
            # Check for repetition markers
            if self._match([TokenType.QUESTION]):
                return Optional(value=value)
            elif self._match([TokenType.PLUS]):
                return Repetition(value=value, min_occurrences=1, max_occurrences=None)
            elif self._match([TokenType.ASTERISK]):
                return Repetition(value=value, min_occurrences=0, max_occurrences=None)
            elif self._match([TokenType.HASH]):
                return Repetition(value=value, min_occurrences=1, max_occurrences=None, separator=',')
            elif self._match([TokenType.OPEN_BRACE]):
                return self._parse_count_repetition(value)
            elif self._match([TokenType.CARET]):
                return self._parse_directive(value)
                
            return value
        else:
            token = self._current()
            print(f"Unexpected token: {token.type}, value: '{token.value}' at line {token.line}, column {token.column}")
            self._error(f"Unexpected token: {token.type}")
            
    def _parse_reference(self):
        """Parse a reference to another rule: <rule-name>"""
        print(f"Parsing reference at position {self.current}")
        
        name_parts = []
        constraints = {}
        
        # Build the reference name
        while not self._check(TokenType.CLOSE_ANGLE) and not self._is_at_end():
            if self._match([TokenType.WHITESPACE]):
                continue
                
            # Check for constraints like min=0 or max=100
            if self._check(TokenType.IDENTIFIER) and self._peek_next().type == TokenType.EQUALS:
                constraint_name = self._consume(TokenType.IDENTIFIER, "").value
                self._consume(TokenType.EQUALS, "Expected '=' after constraint name")
                constraint_value = self._consume(TokenType.NUMBER, "Expected number value for constraint").value
                constraints[constraint_name] = float(constraint_value)
            else:
                name_parts.append(self._current().value)
                self._advance()
                
        self._consume(TokenType.CLOSE_ANGLE, "Expected '>' to close reference")
        name = ''.join(name_parts)
        print(f"Parsed reference to rule: {name} with constraints: {constraints}")
        
        return Reference(name=name, constraints=constraints)

    def _parse_optional(self):
        """Parse an optional group [...] that may span multiple lines and contain complex nested structures"""
        print(f"Parsing optional group at position {self.current}")
        
        # Track nesting level of brackets to handle nested structures
        bracket_level = 1  # We've already consumed the opening bracket
        expression_tokens = []
        start_position = self.current
        
        # First, collect all tokens until we find the matching closing bracket
        max_iterations = 10000  # Safety mechanism
        iterations = 0
        
        # Keep track of positions for debugging
        line_nums = []
        col_nums = []
        
        print(f"Searching for matching closing bracket for optional group...")
        
        # Skip any whitespace immediately inside the opening bracket
        self._skip_whitespace()
        
        try:
            # Parse the content inside the bracket as an expression
            value = self._parse_expression()
            
            # Look for the closing bracket
            self._skip_whitespace()
            if self._match([TokenType.CLOSE_BRACKET]):
                # Check for ? after brackets (which would be redundant but allowed)
                self._match([TokenType.QUESTION])
                return Optional(value=value)
            else:
                print(f"ERROR: Missing closing bracket for optional group, current token: {self._current().type} '{self._current().value}' at line {self._current().line}")
                # Try to recover by returning what we have so far
                return Optional(value=value)
                
        except Exception as e:
            print(f"Error while parsing optional group: {str(e)}")
            # Try to recover by skipping to the closing bracket or the next rule
            self._recover_from_error()
            # Create a dummy literal for recovery
            return Optional(value=Literal(value="ERROR"))

    def _parse_group(self):
        """Parse a group (...)"""
        value = self._parse_expression()
        self._consume(TokenType.CLOSE_PAREN, "Expected ')' to close group")
        return Group(value=value)
        
    def _parse_count_repetition(self, value):
        """Parse repetition with count {n} or {n,m}"""
        min_count = int(self._consume(TokenType.NUMBER, "Expected number for repetition count").value)
        max_count = min_count
        
        if self._match([TokenType.COMMA]):
            if self._match([TokenType.NUMBER]):
                max_count = int(self._previous().value)
            else:
                max_count = None  # Unbounded
                
        self._consume(TokenType.CLOSE_BRACE, "Expected '}' to close repetition")
        return Repetition(value=value, min_occurrences=min_count, max_occurrences=max_count)
        
    def _parse_directive(self, value):
        """Parse a directive like ^WS or ^SORT"""
        directive_name = self._consume(TokenType.IDENTIFIER, "Expected identifier after '^'").value
        return Directive(name=directive_name, value=value)

    def _skip_whitespace(self):
        """Skip whitespace, comments, and handle newlines correctly"""
        max_iterations = 1000
        iterations = 0
        
        while iterations < max_iterations and not self._is_at_end():
            # Handle whitespace and comments
            if self._match([TokenType.WHITESPACE, TokenType.COMMENT]):
                iterations += 1
                continue
                
            # For newlines, we need to be more careful
            if self._check(TokenType.NEWLINE):
                # Need to look ahead to determine if this newline is part of whitespace
                # or if it signals the end of a rule/structure
                
                # Check ahead for a new rule start or structure end
                next_pos = self.current + 1
                while (next_pos < len(self.tokens) and
                      (self.tokens[next_pos].type == TokenType.WHITESPACE or 
                       self.tokens[next_pos].type == TokenType.COMMENT)):
                    next_pos += 1
                    
                # If the next non-whitespace token is a new rule start or structure end,
                # don't consume this newline - it's a separator, not whitespace
                if next_pos < len(self.tokens):
                    token_type = self.tokens[next_pos].type
                    if (token_type == TokenType.OPEN_ANGLE or 
                        token_type == TokenType.CLOSE_BRACKET or 
                        token_type == TokenType.CLOSE_PAREN):
                        break
                
                # Otherwise, it's just whitespace within a multi-line rule
                self._advance()  # Consume the newline
                iterations += 1
                continue
                
            # If we got here, we've found a non-whitespace token
            break
            
        if iterations >= max_iterations:
            print(f"WARNING: Possible infinite loop in _skip_whitespace")

    def _recover_from_error(self):
        """Attempt to recover from a parsing error by finding a safe point to continue"""
        print("Attempting to recover from parsing error...")
        
        # Strategy: Skip tokens until we find the end of the current rule or structure
        recovery_tokens = [TokenType.CLOSE_BRACKET, TokenType.CLOSE_PAREN, TokenType.NEWLINE]
        
        # Skip until we find a recovery point
        while not self._is_at_end():
            if any(self._check(type) for type in recovery_tokens):
                self._advance()  # Consume the recovery token
                print(f"Recovered at token: {self._previous().type}")
                break
            
            # Also try to recover by finding the start of the next rule
            next_pos = self.current + 1
            found_rule_start = False
            while next_pos < len(self.tokens):
                if self.tokens[next_pos].type == TokenType.OPEN_ANGLE:
                    found_rule_start = True
                    break
                next_pos += 1
                
            if found_rule_start:
                self.current = next_pos - 1  # Position just before the rule start
                print(f"Recovered by finding next rule at position {next_pos}")
                break
                
            self._advance()
            
        print(f"Recovery complete, now at token: {self._current().type} at position {self.current}")

    def _advance(self):
        if not self._is_at_end():
            self.current += 1
        return self._previous()

    def _is_at_end(self):
        return self._current().type == TokenType.EOF

    def _current(self):
        return self.tokens[self.current]

    def _previous(self):
        return self.tokens[self.current - 1]

    def _peek_next(self):
        if self.current + 1 >= len(self.tokens):
            return self.tokens[-1]
        return self.tokens[self.current + 1]

    def _check(self, type):
        if self._is_at_end():
            return False
        return self._current().type == type

    def _match(self, types):
        for type in types:
            if self._check(type):
                self._advance()
                return True
        return False

    def _consume(self, type, message):
        if self._check(type):
            return self._advance()
        self._error(message)

    def _error(self, message):
        token = self._current()
        raise SyntaxError(f"{message} at line {token.line}, column {token.column}")


def parse_css_grammar(file_path):
    print(f"Opening file: {file_path}")
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
            print(f"File read successfully: {len(content)} characters")

        lexer = Lexer(content)
        tokens = lexer.tokenize()

        parser = Parser(tokens)
        ast = parser.parse()

        return ast
    except Exception as e:
        print(f"ERROR in parse_css_grammar: {str(e)}")
        raise


def save_ast_to_json(ast, output_path):
    ast_dict = [node.to_dict() for node in ast]

    with open(output_path, 'w', encoding='utf-8') as f:
        json.dump(ast_dict, f, indent=2)

    print(f"AST saved to {output_path}")


if __name__ == "__main__":
    if len(sys.argv) > 1:
        file_path = sys.argv[1]
    else:
        file_path = "/Users/henryluo/Projects/lexbor/utils/lexbor/css/grammar.txt"

    output_path = file_path.rsplit('.', 1)[0] + '.json'

    print(f"Starting CSS grammar parser for file: {file_path}")
    try:
        ast = parse_css_grammar(file_path)
        print(f"AST generated successfully, saving to {output_path}")
        save_ast_to_json(ast, output_path)
        print("Processing complete!")
    except Exception as e:
        print(f"Error during processing: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)
