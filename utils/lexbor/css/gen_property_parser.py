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
    
    # Check if we have repetition patterns like {2,4}
    repetition_pattern = re.compile(r'(.*?)(?:\s*\{(\d+)(?:,\s*(\d+))?\})')
    repetition_match = repetition_pattern.search(values_part)
    
    if repetition_match:
        base_value = repetition_match.group(1).strip()
        min_repeat = int(repetition_match.group(2))
        max_repeat = int(repetition_match.group(3)) if repetition_match.group(3) else min_repeat
        
        # Add as a special repeat indicator
        values.append(f"REPEAT:{base_value}:{min_repeat}:{max_repeat}")
    
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
    
    # Handle references to other definitions
    elif '<' in values_part and '>' in values_part:
        # Extract referenced types
        for match in re.finditer(r'<([^>]+)>', values_part):
            values.append(f"<{match.group(1)}>")
        
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
    
    # Define parser functions for various CSS value types
    value_parsers = {
        "color": {
            "type": "color",
            "func": "lxb_css_property_state_color_handler",
            "var": "(lxb_css_value_color_t *)&value",
            "value_type": "color"
        },
        "color-handler": {
            "type": "color",
            "func": "lxb_css_property_state_color_handler",
            "var": "(lxb_css_value_color_t *)&value",
            "value_type": "color"
        },
        "length": {
            "type": "length",
            "func": "lxb_css_property_state_length",
            "var": "&value.length",
            "value_type": "length"
        },
        "length-percentage": {
            "type": "length_percentage",
            "func": "lxb_css_property_state_length_percentage",
            "var": "(lxb_css_value_length_percentage_t *)&value",
            "value_type": "length_percentage"
        },
        "percentage": {
            "type": "percentage",
            "func": "lxb_css_property_state_percentage",
            "var": "&value.percentage",
            "value_type": "percentage"
        },
        "image": {
            "type": "image",
            "func": "lxb_css_property_state_image",
            "var": "(lxb_css_value_image_t *)&value",
            "value_type": "image"
        },
        "number": {
            "type": "number",
            "func": "lxb_css_property_state_number",
            "var": "&value.number",
            "value_type": "number"
        },
        "integer": {
            "type": "integer",
            "func": "lxb_css_property_state_integer",
            "var": "&value.integer",
            "value_type": "integer"
        },
        "angle": {
            "type": "angle",
            "func": "lxb_css_property_state_angle",
            "var": "&value.angle",
            "value_type": "angle"
        },
        "time": {
            "type": "time",
            "func": "lxb_css_property_state_time",
            "var": "&value.time",
            "value_type": "time"
        },
        "frequency": {
            "type": "frequency",
            "func": "lxb_css_property_state_frequency",
            "var": "&value.frequency",
            "value_type": "frequency"
        },
        "string": {
            "type": "string",
            "func": "lxb_css_property_state_string",
            "var": "(lxb_css_value_string_t *)&value",
            "value_type": "string"
        },
        "url": {
            "type": "url",
            "func": "lxb_css_property_state_url",
            "var": "(lxb_css_value_url_t *)&value",
            "value_type": "url"
        },
    }

    # Handle pipe-separated values (alternatives)
    alternatives = []
    if "|" in repeat_value and not (is_reference):
        alternatives = [alt.strip() for alt in repeat_value.split("|")]
        is_reference = False
    
    # Set default parser details
    parser_details = {
        "type": "unknown",
        "func": None, 
        "var": "value",
        "value_type": "unknown"
    }
    
    # Get parser details based on reference type
    if is_reference:
        ref_type = repeat_value[1:-1]
        if ref_type in value_parsers:
            parser_details = value_parsers[ref_type]
    
    # Generate the repetition parsing code
    code = f"""static bool
lxb_css_property_state_{c_name}_repeat(lxb_css_parser_t *parser,
                                     const lxb_css_syntax_token_t *token,
                                     lxb_css_rule_declaration_t *declar)
{{
    bool res;
    int count = 0;
    lxb_status_t status;
    lxb_css_value_type_t type;
    const lxb_css_syntax_token_t *current_token;
"""

    # Add specific variable declarations based on the value type
    if parser_details["type"] != "unknown":
        code += f"    lxb_css_value_{parser_details['value_type']}_t value;\n"
    
    code += """    
    /* Storage for repeated values would be allocated here */
    /* We're just tracking if we can successfully parse the expected pattern */
    
    current_token = token;
    
    while (current_token != NULL) {
        /* Try to parse the repeated value */
"""
    
    # Generate parsing logic based on the repetition value
    if is_reference and parser_details["func"]:
        # Reference value with known parser
        code += f"""        res = {parser_details["func"]}(parser, current_token, {parser_details["var"]}, &status);
        if (res) {{
            count++;
            
            /* In a real implementation, we would store the value here */
            
            current_token = lxb_css_syntax_parser_token(parser);
"""
    elif alternatives:
        # Alternative values
        code += """        if (current_token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
            lexbor_str_t *str = lxb_css_syntax_token_ident(current_token);
            bool matched = false;
            
            /* Check against all possible alternative values */
"""
        for alt in alternatives:
            code += f"""            if (lxb_css_parser_check_keyword(str->data, str->length, "{alt}")) {{
                matched = true;
            }}
"""
        code += """            
            if (matched) {
                count++;
                
                /* Consume the token */
                lxb_css_syntax_parser_consume(parser);
                current_token = lxb_css_syntax_parser_token(parser);
"""
    else:
        # Literal value or unknown reference
        code += """        if (current_token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
            lexbor_str_t *str = lxb_css_syntax_token_ident(current_token);
            
            /* Check if it matches our expected value */
"""
        # If it's a literal value, match directly
        if not is_reference:
            code += f"""            if (lxb_css_parser_check_keyword(str->data, str->length, "{repeat_value}")) {{
                count++;
                
                /* Consume the token */
                lxb_css_syntax_parser_consume(parser);
                current_token = lxb_css_syntax_parser_token(parser);
"""
        else:
            # For unknown reference types, try to match based on name
            code += f"""            /* Unknown reference type: {repeat_value} */
            /* This is a placeholder for proper parsing logic */
            type = lxb_css_value_by_name(str->data, str->length);
            if (type != LXB_CSS_VALUE__UNDEF) {{
                count++;
                
                /* Consume the token */
                lxb_css_syntax_parser_consume(parser);
                current_token = lxb_css_syntax_parser_token(parser);
"""
    
    # Common code for comma handling (for all value types)
    if comma_separated:
        code += f"""            
            /* Check for comma separator */
            if (count < {max_repeat if max_repeat > 0 else 999} && current_token != NULL) {{
                if (current_token->type != LXB_CSS_SYNTAX_TOKEN_COMMA) {{
                    break; /* No comma, end of sequence */
                }}
                
                /* Consume the comma */
                lxb_css_syntax_parser_consume(parser);
                current_token = lxb_css_syntax_parser_token(parser);
            }}
            
            continue;
        }}
"""
    else:
        code += """            
            continue;
        }
"""
    
    code += """        /* If we get here, we couldn't parse another value of the expected type */
        break;
    }
    
    /* Check if we have the minimum number of values */
    if (count < """ + str(min_repeat) + """) {
        return false;
    }
    
    /* Check if we've exceeded the maximum (if specified) */
    if (""" + str(max_repeat) + """ > 0 && count > """ + str(max_repeat) + """) {
        return false;
    }
    
    /* Successfully parsed the repeating pattern */
    declar->u.""" + c_name + """->type = LXB_CSS_VALUE__COMPLEX;
    /* In a real implementation, we would store all the parsed values */
    
    return true;
}"""
    
    return code

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
                break;

            default:
                return lxb_css_parser_failed(parser);
        }

        lxb_css_syntax_parser_consume(parser);
        return lxb_css_parser_success(parser);
    }

    res = lxb_css_property_state_length_percentage(parser, token,
                                                 (lxb_css_value_length_percentage_t *)declar->u.user);
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
                break;

            default:
                return lxb_css_parser_failed(parser);
        }

        lxb_css_syntax_parser_consume(parser);
        return lxb_css_parser_success(parser);
    }

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
        /* Local. */
"""
        # Add cases for each value
        for value in values:
            # Skip special value types like <color>
            if value.startswith("<") and value.endswith(">"):
                continue
            
            if value == "auto":
                enum_value = f"LXB_CSS_VALUE_AUTO"
            else:
                value_c = value.upper().replace('-', '_')
                enum_value = f"LXB_CSS_{c_name.upper()}_{value_c}"
            
            func += f"        case {enum_value}:\n"
        
        func += f"""            declar->u.{c_name}->type = type;
            break;

        default:
            return lxb_css_parser_failed(parser);
    }}

    lxb_css_syntax_parser_consume(parser);

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
                
            /* Add property-specific cases here */
            default:
                break;
        }
    }
    
    /* Additional property-specific parsing logic should be implemented here */
    
    return lxb_css_parser_failed(parser);
}"""
    
    return func

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <css_property_name>")
        sys.exit(1)
    
    property_name = sys.argv[1]
    
    property_name, values_part = load_grammar_rule(property_name)
    if not property_name:
        sys.exit(1)
    
    values = parse_values(values_part)
    if not values:
        print(f"Warning: No values found for property '{property_name}'")
    
    function = generate_c_function(property_name, values)
    print(function)

if __name__ == "__main__":
    main()