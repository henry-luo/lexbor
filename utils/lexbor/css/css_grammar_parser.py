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
                    self._print_token_context(10)  # Print surrounding tokens for context
                    print(f"Skipping this token and continuing...")
                    self._advance()  # Force advance
                    stuck_count = 0
            else:
                stuck_count = 0
                last_position = self.current

            if iterations % 1000 == 0:
                print(f"Parsing... processed {iterations} iterations, current position: {self.current}/{len(self.tokens)}")
                print(f"Current token: {self._current().type} at line {self._current().line}, column {self._current().column}")
                self._print_token_context(5)  # Print surrounding tokens

            # Skip whitespace, comments, newlines
            if self._check(TokenType.COMMENT) or self._check(TokenType.WHITESPACE) or self._check(TokenType.NEWLINE):
                self._advance()
                continue

            # Parse a rule if we encounter an opening angle bracket
            if self._check(TokenType.OPEN_ANGLE):
                try:
                    rule = self._parse_rule()
                    rules.append(rule)
                    self.rule_count += 1
                    if self.rule_count % 5 == 0:
                        print(f"Parsed {self.rule_count} rules so far")
                except Exception as e:
                    print(f"Error parsing rule: {str(e)}")
                    print("Current token context:")
                    self._print_token_context(10)
                    
                    # Try to recover by skipping to the next rule
                    print("Attempting to recover from rule parsing error...")
                    self._recover_to_next_rule()
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

    def _print_token_context(self, context_size=5):
        """Print surrounding tokens for better debugging context"""
        start = max(0, self.current - context_size)
        end = min(len(self.tokens), self.current + context_size + 1)
        
        print(f"Token context (current position: {self.current}):")
        for i in range(start, end):
            token = self.tokens[i]
            pointer = "-> " if i == self.current else "   "
            value_display = repr(token.value) if token.type in [TokenType.IDENTIFIER, TokenType.STRING] else token.value
            print(f"{pointer}{i}: {token.type.name} '{value_display}' at line {token.line}, col {token.column}")

    def _recover_to_next_rule(self):
        """Skip ahead to the next rule definition"""
        print("Skipping ahead to find the next rule definition...")
        
        # Start from current position and look for a rule start
        start_pos = self.current
        max_lookahead = 1000
        
        for i in range(max_lookahead):
            if self._is_at_end():
                print("Reached end of file while recovering")
                return
                
            # If we find a potential rule start
            if self._check(TokenType.OPEN_ANGLE) and self._check_rule_start():
                print(f"Found a new rule start at position {self.current}")
                return
                
            self._advance()
            
        print(f"Could not find next rule start after skipping {max_lookahead} tokens")

    def _parse_rule(self):
        """Parse a CSS grammar rule that may span multiple lines"""
        print(f"Parsing rule at token position {self.current}")
        self._consume(TokenType.OPEN_ANGLE, "Expected '<' for rule name")

        # Parse the rule name and constraints
        try:
            name_and_constraints = self._extract_rule_name_and_constraints()
            name = name_and_constraints['name']
            constraints = name_and_constraints['constraints']
            
            print(f"Rule name: '{name}', constraints: {constraints}")
            
            # Now ensure we've reached the end of the rule name
            if not self._check(TokenType.EQUALS):
                print(f"WARNING: Expected '=' after rule name, found {self._current().type} '{self._current().value}'")
                self._print_token_context(5)
                
                # Try to recover - look ahead for an equals sign
                self._skip_until_equals_or_rule_start()

            self._skip_whitespace()

            # Make sure we've found an equals sign after the rule name
            self._consume(TokenType.EQUALS, "Expected '=' after rule name")

            self._skip_whitespace()

            print(f"Parsing value for rule '{name}'")
            
            # Parse the entire rule value, which may be a complex expression spanning multiple lines
            value = self._parse_multiline_expression()
            
            # Make sure we skip any trailing whitespace after a rule
            self._skip_whitespace()
            
            print(f"Completed parsing rule: '{name}'")

            return Rule(name=name, value=value)
        except Exception as e:
            print(f"Exception in _parse_rule: {str(e)}")
            raise
    
    def _skip_until_equals_or_rule_start(self):
        """Skip tokens until we find an equals sign or the start of a new rule"""
        print("Looking ahead for equals sign...")
        max_lookahead = 50
        saved_position = self.current
        
        for i in range(max_lookahead):
            if self._is_at_end():
                break
                
            if self._check(TokenType.EQUALS):
                print(f"Found equals sign {i} tokens ahead")
                return
                
            # If we find what looks like a new rule start, go back to saved position
            if i > 0 and self._check(TokenType.OPEN_ANGLE) and self._check_rule_start():
                print(f"Found new rule start {i} tokens ahead, reverting to original position")
                self.current = saved_position
                return
                
            self._advance()
            
        # If we didn't find anything useful, go back to starting position
        print("Could not find equals sign or new rule start, reverting to original position")
        self.current = saved_position
    
    def _extract_rule_name_and_constraints(self):
        """Extract the rule name and any constraints from within angle brackets"""
        print(f"Extracting rule name and constraints at position {self.current}")
        name_parts = []
        constraints = {}
        found_constraint = False
        
        start_pos = self.current
        
        # Process tokens until we reach the closing angle bracket
        while not self._check(TokenType.CLOSE_ANGLE) and not self._is_at_end():
            current_token = self._current()
            next_token = self._peek_next()
            
            print(f"  Processing token: {current_token.type} '{current_token.value}'")
            
            # If we find whitespace, skip it but preserve one space in the name
            if self._check(TokenType.WHITESPACE):
                if not found_constraint and name_parts and not name_parts[-1].endswith(' '):
                    name_parts.append(' ')
                self._advance()
                continue
            
            # If we find an identifier followed by equals, it's a constraint
            if (self._check(TokenType.IDENTIFIER) and 
                next_token.type == TokenType.EQUALS):
                
                found_constraint = True
                constraint_name = self._advance().value  # Consume the identifier
                print(f"  Found constraint name: {constraint_name}")
                
                self._consume(TokenType.EQUALS, "Expected '=' after constraint name")
                
                # Handle negative numbers
                negate = False
                if self._check(TokenType.IDENTIFIER) and self._current().value == "-":
                    negate = True
                    self._advance()
                
                if self._check(TokenType.NUMBER):
                    constraint_value = float(self._advance().value)
                    if negate:
                        constraint_value = -constraint_value
                    constraints[constraint_name] = constraint_value
                    print(f"  Set numeric constraint: {constraint_name}={constraint_value}")
                elif self._check(TokenType.IDENTIFIER) or self._check(TokenType.STRING):
                    constraint_value = self._advance().value
                    constraints[constraint_name] = constraint_value
                    print(f"  Set string constraint: {constraint_name}={constraint_value}")
                else:
                    print(f"  WARNING: Expected number or string for constraint value, found {self._current().type}")
                    constraint_value = "ERROR"
                    constraints[constraint_name] = constraint_value
            else:
                # If we haven't found any constraints yet, this is part of the name
                if not found_constraint:
                    name_parts.append(self._current().value)
                else:
                    print(f"  WARNING: Unexpected token in constraints: {self._current().type} '{self._current().value}'")
                self._advance()
        
        self._consume(TokenType.CLOSE_ANGLE, "Expected '>' to close rule name")
        name = ''.join(name_parts).strip()
        
        print(f"Extracted rule name: '{name}' with constraints: {constraints}")
        return {'name': name, 'constraints': constraints}

    def _skip_whitespace(self):
        """Skip whitespace, comments, and newline tokens"""
        while (not self._is_at_end() and 
              (self._check(TokenType.WHITESPACE) or 
               self._check(TokenType.COMMENT) or 
               self._check(TokenType.NEWLINE))):
            self._advance()

    def _skip_multiline_whitespace(self):
        """
        Skip whitespace even across multiple lines, but be careful about rule boundaries.
        This is essential for handling multi-line grammar definitions.
        """
        max_iterations = 100
        iterations = 0
        
        while iterations < max_iterations and not self._is_at_end():
            if self._match([TokenType.WHITESPACE, TokenType.COMMENT]):
                iterations += 1
                continue
                
            if self._match([TokenType.NEWLINE]):
                # After a newline, check if the next non-whitespace is a new rule start
                position = self.current
                while (position < len(self.tokens) and 
                       (self.tokens[position].type == TokenType.WHITESPACE or
                        self.tokens[position].type == TokenType.COMMENT)):
                    position += 1
                    
                # If we see a new rule start, stop skipping
                if position < len(self.tokens) and self._check_token_at(TokenType.OPEN_ANGLE, position):
                    if self._check_rule_start_at(position):
                        break
                
                iterations += 1
                continue
                
            break
            
        if iterations >= max_iterations:
            print(f"WARNING: Possible infinite loop in _skip_multiline_whitespace")

    def _check_rule_start(self):
        """Check if we're at what appears to be the start of a new rule definition"""
        if not self._check(TokenType.OPEN_ANGLE):
            return False
            
        # Look ahead to see if this is likely a rule start
        position = self.current + 1
        found_close = False
        
        # Look for the closing angle bracket
        while position < len(self.tokens) and not found_close:
            if self.tokens[position].type == TokenType.CLOSE_ANGLE:
                found_close = True
                break
            position += 1
            
        if not found_close:
            return False
            
        # After the closing angle, look for an equals sign
        position += 1
        while position < len(self.tokens):
            if self.tokens[position].type == TokenType.WHITESPACE or self.tokens[position].type == TokenType.NEWLINE:
                position += 1
                continue
                
            # If we find an equals sign, this is likely a rule definition
            return self.tokens[position].type == TokenType.EQUALS
            
        return False

    def _check_rule_start_at(self, position):
        """Check if the given position appears to be a rule start"""
        if position >= len(self.tokens) or self.tokens[position].type != TokenType.OPEN_ANGLE:
            return False
            
        # Similar logic as _check_rule_start but starting at the given position
        pos = position + 1
        found_close = False
        
        while pos < len(self.tokens) and not found_close:
            if self.tokens[pos].type == TokenType.CLOSE_ANGLE:
                found_close = True
                break
            pos += 1
            
        if not found_close:
            return False
            
        pos += 1
        while pos < len(self.tokens):
            if self.tokens[pos].type == TokenType.WHITESPACE or self.tokens[pos].type == TokenType.NEWLINE:
                pos += 1
                continue
                
            return self.tokens[pos].type == TokenType.EQUALS
            
        return False

    def _check_token_at(self, token_type, position):
        """Check if the token at the given position is of the specified type"""
        if position >= len(self.tokens):
            return False
        return self.tokens[position].type == token_type

    def _parse_multiline_expression(self):
        """Parse a potentially multi-line expression that may include operators"""
        print(f"Parsing multiline expression at position {self.current}")
        
        # First parse a single expression
        left = self._parse_expression()
        
        # Skip any whitespace including newlines
        self._skip_multiline_whitespace()
        
        # Check if we have a list of values with an operator
        if (not self._is_at_end() and 
            (self._check(TokenType.PIPE) or 
             self._check(TokenType.DOUBLE_PIPE) or 
             self._check(TokenType.DOUBLE_AMPERSAND))):
            
            operator = self._current().value
            self._advance()  # Consume the operator
            
            values = [left]
            
            # Keep parsing expressions in the list
            while not self._is_at_end():
                self._skip_multiline_whitespace()
                
                # Break if we hit a rule boundary
                if self._is_at_end() or (self._check(TokenType.OPEN_ANGLE) and self._check_rule_start()):
                    break
                    
                # Parse the next value in the list
                next_expr = self._parse_expression()
                values.append(next_expr)
                
                # Skip whitespace after this value
                self._skip_multiline_whitespace()
                
                # If there's no more of the same operator, we're done with this list
                if not self._check(TokenType.PIPE if operator == '|' else
                                 TokenType.DOUBLE_PIPE if operator == '||' else 
                                 TokenType.DOUBLE_AMPERSAND):
                    break
                    
                # Consume the operator
                self._advance()
            
            print(f"Created value list with {len(values)} items and operator '{operator}'")
            return ValueList(values=values, operator=operator)
            
        return left

    def _parse_expression(self):
        """Parse a standard expression (a term or combination)"""
        print(f"Parsing expression at position {self.current}")
        
        # Create a simple literal or reference as a base
        term = self._parse_term()
        
        return term

    def _parse_term(self):
        """Parse a basic term (reference, literal, etc.)"""
        if self._check(TokenType.IDENTIFIER):
            value = Literal(value=self._advance().value)
            return value
        elif self._check(TokenType.STRING):
            value = Literal(value=self._advance().value)
            return value
        elif self._check(TokenType.NUMBER):
            value = Literal(value=self._advance().value)
            return value
        elif self._check(TokenType.OPEN_ANGLE):
            # This is a reference to another rule
            return self._parse_reference()
        else:
            # For debugging and recovery
            current = self._current()
            print(f"Warning: Unexpected token in term: {current.type} '{current.value}'")
            
            # Return a placeholder
            self._advance()  # Skip the problematic token
            return Literal(value="ERROR")

    def _parse_reference(self):
        """Parse a reference to another rule"""
        self._consume(TokenType.OPEN_ANGLE, "Expected '<' to start reference")
        
        name_parts = []
        constraints = {}
        
        # This flag helps distinguish between the rule name and constraints
        reading_name = True
        
        # Parse the reference content
        while not self._check(TokenType.CLOSE_ANGLE) and not self._is_at_end():
            # Skip any whitespace
            if self._match([TokenType.WHITESPACE]):
                continue
                
            # Check for constraints like min=0 or max=100
            if self._check(TokenType.IDENTIFIER) and self._peek_next().type == TokenType.EQUALS:
                reading_name = False  # We're now reading constraints
                
                constraint_name = self._advance().value
                self._consume(TokenType.EQUALS, "Expected '=' after constraint name")
                
                # Handle negative numbers in constraints
                negate = False
                if self._match([TokenType.IDENTIFIER]) and self._previous().value == "-":
                    negate = True
                    
                constraint_value = float(self._advance().value)
                
                if negate:
                    constraint_value = -constraint_value
                    
                constraints[constraint_name] = constraint_value
                
            elif reading_name:
                # Still reading the rule name part
                name_parts.append(self._current().value)
                self._advance()
                
            else:
                # Unexpected token within constraints
                print(f"Warning: Unexpected token in reference constraints: {self._current().type}")
                self._advance()
                
        self._consume(TokenType.CLOSE_ANGLE, "Expected '>' to close reference")
        name = ''.join(name_parts)
        print(f"Parsed reference to rule: {name} with constraints: {constraints}")
        
        return Reference(name=name, constraints=constraints)

    def _is_at_end(self):
        """Check if we've reached the end of the token stream"""
        return self.current >= len(self.tokens) or self._current().type == TokenType.EOF

    def _current(self):
        """Return the current token"""
        if self.current >= len(self.tokens):
            return self.tokens[-1]  # Return EOF token if we're past the end
        return self.tokens[self.current]

    def _previous(self):
        """Return the previous token"""
        if self.current <= 0:
            return self.tokens[0]  # Return first token if we're at the beginning
        return self.tokens[self.current - 1]
        
    def _advance(self):
        """Move to the next token and return the previous one"""
        prev = self._current()
        if not self._is_at_end():
            self.current += 1
        return prev
        
    def _check(self, type):
        """Check if the current token is of the given type"""
        if self._is_at_end():
            return False
        return self._current().type == type
        
    def _peek_next(self):
        """Return the next token without consuming it"""
        if self.current + 1 >= len(self.tokens):
            return self.tokens[-1]  # Return EOF token if we're past the end
        return self.tokens[self.current + 1]
        
    def _match(self, types):
        """Check if the current token matches any of the given types and advance if true"""
        for type in types:
            if self._check(type):
                self._advance()
                return True
        return False

    def _consume(self, type, message):
        """Modified consume method with better error reporting"""
        if self._check(type):
            return self._advance()
        
        token = self._current()
        error_msg = f"{message} at line {token.line}, column {token.column}"
        print(f"ERROR: {error_msg}")
        print(f"Expected {type.name}, but found {token.type.name} '{token.value}'")
        self._print_token_context(5)
        raise SyntaxError(error_msg)


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

        from json_to_grammar import convert_json_to_grammar
        grammar_text = convert_json_to_grammar("./grammar.json", "./grammar.output.txt")
        print(f"Grammar text generated successfully, saving to grammar.output.txt")
        print("Processing complete!")
    except Exception as e:
        print(f"Error during processing: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)
