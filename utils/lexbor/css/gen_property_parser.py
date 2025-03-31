#!/usr/bin/env python3

import sys
import re
import os

# Hardcoded grammar file path
GRAMMAR_FILE = "grammar.txt"

def load_grammar_rule(property_name):
    """Load the grammar rule for a specific CSS property."""
    with open(GRAMMAR_FILE, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('//') or line.startswith('/*'):
                continue
                
            match = re.match(r'<([^>]+)>\s*=\s*(.*)', line)
            if match and match.group(1) == property_name:
                return match.group(1), match.group(2)
    
    print(f"Error: Property '{property_name}' not found in grammar file")
    return None, None

def parse_values(values_part):
    """Parse the values part of the grammar rule."""
    values = []
    
    # Check if we have # notation for comma-separated repeating values
    if '#' in values_part:
        parts = values_part.split('#')
        base_value = parts[0].strip()
        # Add as a special comma-separated repeat indicator (min=1, no explicit max)
        values.append(f"REPEAT_COMMA:{base_value}:1:0")
        return values
    
    # Define regex patterns for extracting complex grammar patterns
    # Pattern for references with possible attributes: <name attr=val ...>
    ref_pattern = re.compile(r'<([^>]+?)(?:\s+([^>]+))?>')
    
    # Pattern for repetition: {min,max} or {exact}
    repetition_pattern = re.compile(r'\{(\d+)(?:,\s*(\d+))?\}')
    
    # Check for complex patterns with both references, attributes and repetition
    complex_pattern = re.compile(r'(<[^>]+>)(?:\s*\{(\d+)(?:,\s*(\d+))?\})')
    complex_match = complex_pattern.search(values_part)
    
    if complex_match:
        # Extract the reference part including any attributes
        reference = complex_match.group(1)
        min_repeat = int(complex_match.group(2))
        max_repeat = int(complex_match.group(3)) if complex_match.group(3) else min_repeat
        
        # Add as a special repeat indicator with the complete reference
        values.append(f"REPEAT:{reference}:{min_repeat}:{max_repeat}")
        return values
    
    # Check for ? suffix (optional - appears 0 or 1 times)
    if values_part.endswith('?'):
        base_value = values_part[:-1].strip()
        values.append(f"REPEAT:{base_value}:0:1")
        return values
    
    # Check for * suffix (appears 0 or more times)
    if values_part.endswith('*'):
        base_value = values_part[:-1].strip()
        values.append(f"REPEAT:{base_value}:0:0")
        return values
    
    # Check for + suffix (appears 1 or more times)
    if values_part.endswith('+'):
        base_value = values_part[:-1].strip()
        values.append(f"REPEAT:{base_value}:1:0")
        return values
    
    # Check if we have repetition patterns like {2,4} for simple values
    repetition_match = re.search(r'([^{]+)\s*\{(\d+)(?:,\s*(\d+))?\}', values_part)
    
    if repetition_match:
        base_value = repetition_match.group(1).strip()
        min_repeat = int(repetition_match.group(2))
        max_repeat = int(repetition_match.group(3)) if repetition_match.group(3) else min_repeat
        
        # Add as a special repeat indicator
        values.append(f"REPEAT:{base_value}:{min_repeat}:{max_repeat}")
        return values
    
    # Handle || pattern (options where at least one must be present, in any order)
    elif '||' in values_part:
        values.append("PATTERN:||")
        for value in values_part.split('||'):
            value = value.strip()
            if value:
                values.append(value)
    
    # Handle simple pipe-separated values (mutually exclusive options)
    elif '|' in values_part and '{' not in values_part:
        values.append("PATTERN:|")
        for value in values_part.split('|'):
            value = value.strip()
            if value:
                values.append(value)
    
    # Handle references to other definitions, including those with attributes
    elif '<' in values_part and '>' in values_part:
        # Extract referenced types with any attributes they have
        for match in re.finditer(r'<([^>]+)>', values_part):
            values.append(match.group(0))  # Add the complete reference including any attributes
        
        # Also extract literal values if present
        for value in re.findall(r'\b([a-z-]+)\b', values_part):
            if value not in ('min', 'max') and not value.startswith('<'):
                values.append(value)
    
    return values

def property_name_to_c_name(name):
    """Convert property-name to property_name."""
    return name.replace('-', '_')

def determine_property_type(property_name, values):
    """Determine the property value type and suitable parsing approach."""
    # Check for special patterns first
    for value in values:
        if value.startswith("PATTERN:") or value.startswith("REPEAT:") or value.startswith("REPEAT_COMMA:"):
            return "complex", None
    
    # Common property types that can use existing parsing functions
    specialized_types = {
        "color": ["<color>", "<color-handler>"],
        "length": ["<length>"],
        "length_percentage": ["<length-percentage>"],
        "number": ["<number>"],
        "integer": ["<integer>"],
        "angle": ["<angle>"],
    }
    
    # Custom mapping for properties with known parsing functions
    known_properties = {
        "width": "width",
        "height": "width",  # reuses width handler
        "min-width": "width",
        "min-height": "width",
        "max-width": "max_width",
        "max-height": "max_width",
        "margin-top": "margin_top",
        "margin-right": "margin_right",
        "margin-bottom": "margin_bottom",
        "margin-left": "margin_left",
        "padding-top": "padding_top",
        "padding-right": "padding_right",
        "padding-bottom": "padding_bottom",
        "padding-left": "padding_left",
        "background-color": "background_color",
        "border-top-color": "border_top_color",
        "border-right-color": "border_right_color",
        "border-bottom-color": "border_bottom_color",
        "border-left-color": "border_left_color",
    }
    
    if property_name in known_properties:
        return "known", known_properties[property_name]
    
    # Check if this property matches a specialized type
    for type_name, type_indicators in specialized_types.items():
        for indicator in type_indicators:
            if indicator in values:
                return type_name, None
    
    # Default to enum for properties with fixed values
    return "enum", None

def generate_repetition_parser(property_name, c_name, repeat_value, min_repeat, max_repeat, comma_separated=False):
    """Generate C code for parsing a repeating pattern."""
    
    # Determine if the repeated value is a reference or a literal
    is_reference = repeat_value.startswith("<") and repeat_value.endswith(">")
    
    # Extract reference type and attributes if present
    ref_type = None
    ref_attributes = {}
    
    if is_reference:
        # Extract the reference type and any attributes
        content = repeat_value[1:-1]  # Remove < >
        parts = re.split(r'\s+(?=\w+=)', content)
        
        if parts:
            ref_type = parts[0]
            
            # Parse any attributes
            for i in range(1, len(parts)):
                attr_match = re.match(r'(\w+)=(.+)', parts[i])
                if attr_match:
                    attr_name = attr_match.group(1)
                    attr_value = attr_match.group(2)
                    ref_attributes[attr_name] = attr_value
    
    # Generate the function name for this repetition parser
    func_name = f"lxb_css_property_state_{c_name}_repeat"
    
    # Start building the function
    func = f"""bool
{func_name}(lxb_css_parser_t *parser,
        const lxb_css_syntax_token_t *token, void *ctx)
{{
    bool status;
    size_t count = 0;
    lxb_css_rule_declaration_t *declar = ctx;
    lxb_css_syntax_token_t *saved_token;
    lxb_css_parser_state_t *saved_state;"""
    
    # For comma-separated lists, we need to track the commas
    if comma_separated:
        func += """
    bool need_comma = false;
    """
    
    # Create a function to parse a single instance of the repeated value
    func += """
    /* Save current parser state */
    saved_token = lxb_css_syntax_parser_token(parser);
    saved_state = lxb_css_parser_state(parser);
    
    /* Attempt to parse the repetition pattern */
    while (true) {
        /* Stop if we've reached the maximum allowed repetitions */"""
    
    if max_repeat > 0:
        func += f"""
        if (count >= {max_repeat}) {{
            break;
        }}
        """
    
    # Handle comma-separated repetition
    if comma_separated:
        func += """
        /* For comma-separated lists, check for comma between values */
        if (need_comma) {
            if (token->type != LXB_CSS_SYNTAX_TOKEN_COMMA) {
                break;
            }
            
            /* Consume the comma and look for next value */
            lxb_css_syntax_parser_consume(parser);
            token = lxb_css_syntax_parser_token(parser);
            need_comma = false;
            continue;
        }
        """
    
    # Parse the actual value based on its type
    func += """
        /* Try to parse the value */
        """
    
    if is_reference:
        if ref_type == "color":
            func += """
        status = lxb_css_property_state_color_handler(parser, token,
                                       (lxb_css_value_color_t *)&declar->u.""" + c_name + """->values[count],
                                       NULL);
        """
        elif ref_type == "length" or ref_type == "length-percentage":
            func += """
        status = lxb_css_property_state_length_percentage(parser, token,
                                    (lxb_css_value_length_percentage_t *)&declar->u.""" + c_name + """->values[count]);
        """
        elif ref_type == "number":
            func += """
        status = lxb_css_property_state_number(parser, token, 
                                &declar->u.""" + c_name + """->values[count].number);
        if (status) {
            declar->u.""" + c_name + """->values[count].type = LXB_CSS_VALUE__NUMBER;
        }
        """
        elif ref_type == "integer":
            func += """
        status = lxb_css_property_state_integer(parser, token, 
                                &declar->u.""" + c_name + """->values[count].integer);
        if (status) {
            declar->u.""" + c_name + """->values[count].type = LXB_CSS_VALUE__INTEGER;
        }
        """
        else:
            # Generic reference handler for other types
            func += """
        /* Handle reference type: """ + ref_type + """ */
        /* This is a placeholder - implement specific parsing logic based on the reference type */
        status = false;
        """
    else:
        # Literal value
        func += """
        /* Check for literal value */
        if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
            lxb_css_value_type_t type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
                                                            lxb_css_syntax_token_ident(token)->length);
            if (type != LXB_CSS_VALUE_UNDEF) {
                declar->u.""" + c_name + """->values[count].type = type;
                lxb_css_syntax_parser_consume(parser);
                status = true;
            } else {
                status = false;
            }
        } else {
            status = false;
        }
        """
    
    # After parsing attempt, check if successful
    func += """
        if (!status) {
            break;
        }
        
        count++;
        token = lxb_css_syntax_parser_token(parser);
        """
    
    # For comma-separated values, flag that we need a comma next
    if comma_separated:
        func += """
        need_comma = true;
        """
    
    # Close the loop
    func += """
    }
    
    /* Check if we've met the minimum repetition requirement */"""
    
    if min_repeat > 0:
        func += f"""
    if (count < {min_repeat}) {{
        /* Restore original parser state */
        lxb_css_parser_state_set(parser, saved_state);
        lxb_css_syntax_parser_token_set(parser, saved_token);
        return false;
    }}
    """
    else:
        func += """
    /* Allow zero repetitions, so success even if count is 0 */
    """
    
    # Update property structure with the number of values parsed
    func += """
    /* Update property structure with the number of values */
    declar->u.""" + c_name + """->count = count;
    declar->u.""" + c_name + """->type = LXB_CSS_VALUE__LIST;
    
    return true;
}"""
    
    return func

def generate_c_function(property_name, values):
    """Generate a C parsing function for a CSS property."""
    c_name = property_name_to_c_name(property_name)
    property_type, known_handler = determine_property_type(property_name, values)
    
    # Extract repetition pattern if present
    repetition_pattern = next((v for v in values if v.startswith("REPEAT:") or v.startswith("REPEAT_COMMA:")), None)
    repetition_func = ""
    if repetition_pattern:
        parts = repetition_pattern.split(":")
        repeat_type = parts[0]  # REPEAT or REPEAT_COMMA
        repeat_value = parts[1]
        min_repeat = int(parts[2])
        max_repeat = int(parts[3]) if len(parts) > 3 and parts[3] != '0' else 0
        
        comma_separated = repeat_type == "REPEAT_COMMA"
        repetition_func = generate_repetition_parser(property_name, c_name, repeat_value, min_repeat, max_repeat, comma_separated)
    
    # Create the function header
    func = f"""bool
lxb_css_property_state_{c_name}(lxb_css_parser_t *parser,
                             const lxb_css_syntax_token_t *token, void *ctx)
{{"""
    
    # For known properties, we can refer to existing implementations
    if property_type == "known" and known_handler:
        if known_handler == c_name:
            func = f"""/* This property already has a parser implementation in state.c */
/* Reference existing function: lxb_css_property_state_{c_name} */"""
            return func
        else:
            func += f"""
    /* Reuse existing parser implementation */
    return lxb_css_property_state_{known_handler}(parser, token, ctx);
}}"""
            return func
    
    # Handle complex patterns with || or repetition
    if property_type == "complex":
        pattern_type = next((v for v in values if v.startswith("PATTERN:") or v.startswith("REPEAT:") or v.startswith("REPEAT_COMMA:")), None)
        if pattern_type and (pattern_type.startswith("REPEAT:") or pattern_type.startswith("REPEAT_COMMA:")):
            func = repetition_func + "\n\n" + func + """
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    /* Handle global values first */
    if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
        type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
                                    lxb_css_syntax_token_ident(token)->length);
        switch (type) {
            /* Global. */
            case LXB_CSS_VALUE_INITIAL:
            case LXB_CSS_VALUE_INHERIT:
            case LXB_CSS_VALUE_UNSET:
            case LXB_CSS_VALUE_REVERT:
                declar->u.""" + c_name + """->type = type;
                lxb_css_syntax_parser_consume(parser);
                return lxb_css_parser_success(parser);
            default:
                break;
        }
    }

    /* Try to parse the repeating pattern */
    if (lxb_css_property_state_""" + c_name + """_repeat(parser, token, declar)) {
        return lxb_css_parser_success(parser);
    }

    return lxb_css_parser_failed(parser);
}"""
        elif pattern_type and pattern_type.startswith("PATTERN:||"):
            func += f"""
    /* This property uses a complex '||' pattern that requires custom handling */
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;
    bool at_least_one_matched = false;

    /* Handle global values first */
    if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {{
        type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
                                    lxb_css_syntax_token_ident(token)->length);
        switch (type) {{
            /* Global. */
            case LXB_CSS_VALUE_INITIAL:
            case LXB_CSS_VALUE_INHERIT:
            case LXB_CSS_VALUE_UNSET:
            case LXB_CSS_VALUE_REVERT:
                declar->u.{c_name}->type = type;
                lxb_css_syntax_parser_consume(parser);
                return lxb_css_parser_success(parser);
            default:
                break;
        }}
    }}

    /* For || pattern, we need to match each component in any order */
    /* Implementation would require tracking which components have been matched */
    /* This is a placeholder for a more complex implementation */
    if (!at_least_one_matched) {{
        return lxb_css_parser_failed(parser);
    }}

    return lxb_css_parser_success(parser);
}}"""
        else:
            func += """
    /* This property has a complex value type and requires custom handling */
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
        type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
                                     lxb_css_syntax_token_ident(token)->length);
        switch (type) {
            /* Global. */
            case LXB_CSS_VALUE_INITIAL:
            case LXB_CSS_VALUE_INHERIT:
            case LXB_CSS_VALUE_UNSET:
            case LXB_CSS_VALUE_REVERT:
                declar->u.""" + c_name + """->type = type;
                
                lxb_css_syntax_parser_consume(parser);
                return lxb_css_parser_success(parser);
                
            /* Property-specific values would be here */
            default:
                break;
        }
    }
    
    return lxb_css_parser_failed(parser);
}"""
        return func
    
    # Handle different property types
    if property_type == "color":
        func += """
    bool res;
    lxb_status_t status;
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    res = lxb_css_property_state_color_handler(parser, token,
                                  (lxb_css_value_color_t *)declar->u.""" + c_name + """,
                                  &status);
    if (!res) {
        return lxb_css_parser_failed(parser);
    }

    return lxb_css_parser_success(parser);
}"""
    elif property_type == "length_percentage":
        func += """
    bool res;
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    res = lxb_css_property_state_length_percentage(parser, token,
                                                 (lxb_css_value_length_percentage_t *)declar->u.""" + c_name + """);
    if (!res) {
        return lxb_css_parser_failed(parser);
    }

    return lxb_css_parser_success(parser);
}"""
    elif property_type == "length":
        func += """
    bool res;
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    res = lxb_css_property_state_length(parser, token, &declar->u.""" + c_name + """->length);
    if (res) {
        declar->u.""" + c_name + """->type = LXB_CSS_VALUE__LENGTH;
        return lxb_css_parser_success(parser);
    }

    return lxb_css_parser_failed(parser);
}"""
    elif property_type == "number":
        func += """
    bool res;
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    res = lxb_css_property_state_number(parser, token, &declar->u.""" + c_name + """->number);
    if (res) {
        declar->u.""" + c_name + """->type = LXB_CSS_VALUE__NUMBER;
        return lxb_css_parser_success(parser);
    }

    return lxb_css_parser_failed(parser);
}"""
    elif property_type == "integer":
        func += """
    bool res;
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    res = lxb_css_property_state_integer(parser, token, &declar->u.""" + c_name + """->integer);
    if (res) {
        declar->u.""" + c_name + """->type = LXB_CSS_VALUE__INTEGER;
        return lxb_css_parser_success(parser);
    }

    return lxb_css_parser_failed(parser);
}"""
    elif property_type == "angle":
        func += """
    bool res;
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    res = lxb_css_property_state_angle(parser, token, &declar->u.""" + c_name + """->angle);
    if (res) {
        declar->u.""" + c_name + """->type = LXB_CSS_VALUE__ANGLE;
        return lxb_css_parser_success(parser);
    }

    return lxb_css_parser_failed(parser);
}"""
    elif property_type == "enum":
        func += """
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    if (token->type != LXB_CSS_SYNTAX_TOKEN_IDENT) {
        return lxb_css_parser_failed(parser);
    }

    type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
                                 lxb_css_syntax_token_ident(token)->length);
    switch (type) {
        /* Global. */
        case LXB_CSS_VALUE_INITIAL:
        case LXB_CSS_VALUE_INHERIT:
        case LXB_CSS_VALUE_UNSET:
        case LXB_CSS_VALUE_REVERT:
            declar->u.""" + c_name + """->type = type;
            break;

        default:
            return lxb_css_parser_failed(parser);
    }

    lxb_css_syntax_parser_consume(parser);
    return lxb_css_parser_success(parser);
}"""
    else:
        func += """
    /* This property has a complex value type and requires custom handling */
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
        type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
                                     lxb_css_syntax_token_ident(token)->length);
        switch (type) {
            /* Global. */
            case LXB_CSS_VALUE_INITIAL:
            case LXB_CSS_VALUE_INHERIT:
            case LXB_CSS_VALUE_UNSET:
            case LXB_CSS_VALUE_REVERT:
                declar->u.""" + c_name + """->type = type;
                
                lxb_css_syntax_parser_consume(parser);
                return lxb_css_parser_success(parser);
                
            /* Property-specific values would be here */
            default:
                break;
        }
    }
    
    return lxb_css_parser_failed(parser);
}"""
    
    return func

def main():
    # Use absolute path derived from the script location for better reliability
    script_dir = os.path.dirname(os.path.abspath(__file__))
    output_path = os.path.normpath(os.path.join(script_dir, "../../../source/lexbor/css/property/state_new.c"))
    
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <css_property_name>|all")
        sys.exit(1)
    
    # Create header content for the C file
    c_header = """/*
 * Copyright (C) 2018-2023 Alexander Borisov
 *
 * Author: Alexander Borisov <borisov@lexbor.com>
 */

#include "lexbor/property/state.h"
#include "lexbor/css/syntax/parser.h"
#include "lexbor/css/syntax/state.h"
#include "lexbor/css/value.h"

/* Auto-generated code for CSS property parsers */

"""
    
    # Initialize the output content with the header
    output_content = c_header
    
    # Process one property or all properties
    if sys.argv[1].lower() == "all":
        # Process all properties defined in the grammar file
        processed_count = 0
        with open(GRAMMAR_FILE, 'r') as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith('//') or line.startswith('/*'):
                    continue
                    
                match = re.match(r'<([^>]+)>\s*=\s*(.*)', line)
                if match:
                    property_name = match.group(1)
                    values_part = match.group(2)
                    
                    try:
                        # Skip common types definitions, only process actual CSS properties
                        if property_name in ["color", "length", "angle", "number", "integer"]:
                            continue
                        
                        values = parse_values(values_part)
                        function = generate_c_function(property_name, values)
                        
                        # Add the function to the output with a separator for readability
                        output_content += f"\n/* Property: {property_name} */\n"
                        output_content += function + "\n\n"
                        processed_count += 1
                    except Exception as e:
                        print(f"Error processing property '{property_name}': {str(e)}")
        
        print(f"Successfully processed {processed_count} properties.")
    else:
        # Process single property
        property_name = sys.argv[1]
        
        property_name, values_part = load_grammar_rule(property_name)
        if not property_name:
            sys.exit(1)
        
        values = parse_values(values_part)
        if not values:
            print(f"Warning: No values found for property '{property_name}'")
        
        function = generate_c_function(property_name, values)
        
        # Add the function to the output
        output_content += f"/* Property: {property_name} */\n"
        output_content += function
    
    # Ensure the output directory exists
    output_dir = os.path.dirname(output_path)
    try:
        os.makedirs(output_dir, exist_ok=True)
        print(f"Output directory ensured: {output_dir}")
    except Exception as e:
        print(f"Error creating output directory: {str(e)}")
        sys.exit(1)
    
    # Write the output to file
    try:
        with open(output_path, 'w') as f:
            f.write(output_content)
        print(f"Successfully wrote CSS property parser code to: {output_path}")
    except Exception as e:
        print(f"Error writing to output file: {str(e)}")
        sys.exit(1)

if __name__ == "__main__":
    main()