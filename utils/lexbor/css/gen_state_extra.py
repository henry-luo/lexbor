#!/usr/bin/env python3

import sys, os, datetime

# Add the directory to the Python path
ABS_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.append("{}/../lexbor/".format(ABS_PATH))

# Import the CSS property definitions
from names_extra import additional_styles, color_values

def create_c_identifier(property_name):
    """Convert CSS property name to a C identifier"""
    return property_name.replace("-", "_")

def generate_function_header(property_name):
    """Generate the function header for a property parser"""
    c_prop = create_c_identifier(property_name)
    return f"""
lxb_css_parser_state_f
lxb_css_property_state_{c_prop}(lxb_css_parser_t *parser, lxb_css_syntax_token_t *token,
                      void *ctx, lxb_css_syntax_token_t **out_token)
{{"""

def generate_property_init(property_name):
    """Generate property initialization code"""
    c_prop = create_c_identifier(property_name)
    return f"""    lxb_css_property_{c_prop}_t *property = lxb_css_parser_create_property_placeholder(parser, offsetof(lxb_css_property_t, {c_prop}));
    if (property == NULL) {{
        return lxb_css_parser_memory_fail(parser);
    }}"""

def generate_token_handling():
    """Generate basic token handling code"""
    return """
    lxb_css_syntax_token_t *ident;
    const lxb_char_t *name;
    size_t length;

    if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
        ident = token;
        name = lxb_css_syntax_token_ident_data(ident);
        length = lxb_css_syntax_token_ident_length(ident);"""

def generate_value_parsing(property_name, values):
    """Generate value parsing code for specific values"""
    c_prop = create_c_identifier(property_name)
    prop_upper = c_prop.upper()
    code = []
    
    # Handle specific known values
    for i, value in enumerate(values):
        if value.startswith('_'):
            continue  # Skip special values like _length
            
        value_upper = value.replace("-", "_").upper()
        condition = "if" if i == 0 else "else if"
        
        code.append(f"""        {condition} (lxb_css_property_state_eq(name, length, "{value}", {len(value)})) {{
            property->type = LXB_CSS_{prop_upper}_{value_upper};
        }}""")
    
    # Handle special value types
    special_handlers = {
        "_length": f"""        else if (lxb_css_property_state_parse_length(parser, ident, &property->u.length)) {{
            property->type = LXB_CSS_{prop_upper}__LENGTH;
        }}""",
        "_percentage": f"""        else if (lxb_css_property_state_parse_percentage(parser, ident, &property->u.percentage)) {{
            property->type = LXB_CSS_{prop_upper}__PERCENTAGE;
        }}""",
        "_number": f"""        else if (lxb_css_property_state_parse_number(parser, ident, &property->u.number)) {{
            property->type = LXB_CSS_{prop_upper}__NUMBER;
        }}""",
        "_integer": f"""        else if (lxb_css_property_state_parse_integer(parser, ident, &property->u.integer)) {{
            property->type = LXB_CSS_{prop_upper}__INTEGER;
        }}""",
        "_time": f"""        else if (lxb_css_property_state_parse_time(parser, ident, &property->u.time)) {{
            property->type = LXB_CSS_{prop_upper}__TIME;
        }}""",
        "_angle": f"""        else if (lxb_css_property_state_parse_angle(parser, ident, &property->u.angle)) {{
            property->type = LXB_CSS_{prop_upper}__ANGLE;
        }}"""
    }
    
    # Add special handlers for values that need them
    for special_type, handler_code in special_handlers.items():
        if special_type in values:
            code.append(handler_code)
    
    # Add color handling if the property accepts color values
    if any(color in values for color in color_values) or "_color" in values:
        code.append(f"""        else if (lxb_css_property_state_parse_color(parser, ident, &property->color)) {{
            property->type = LXB_CSS_{prop_upper}_COLOR;
        }}""")
    
    # Error handling for invalid values
    code.append("""        else {
            lxb_css_parser_warning(parser, LXB_CSS_PARSER_WARNING_PROPERTY_INVALID_VALUE, token);
            lxb_css_parser_destroy_property_placeholder(parser);
            return lxb_css_parser_state_element_skip_to_semicolonp;
        }
    }
    else {
        lxb_css_parser_warning(parser, LXB_CSS_PARSER_WARNING_PROPERTY_INVALID_VALUE, token);
        lxb_css_parser_destroy_property_placeholder(parser);
        return lxb_css_parser_state_element_skip_to_semicolonp;
    }""")
    
    return "\n".join(code)

def generate_function_footer():
    """Generate the function footer"""
    return """
    *out_token = lxb_css_parser_token_consume(parser);
    return lxb_css_parser_state_element_return_to_parent;
}"""

def generate_property_parser(property_name, property_def):
    """Generate a complete parser function for a property"""
    function_parts = [
        generate_function_header(property_name),
        generate_property_init(property_name)
    ]
    
    # Only add value parsing if the property has values
    if property_def["values"]:
        function_parts.extend([
            generate_token_handling(),
            generate_value_parsing(property_name, property_def["values"])
        ])
    
    function_parts.append(generate_function_footer())
    return "\n".join(function_parts)

def generate_state_extra_c():
    """Generate the complete state_extra.c file"""
    file_content = [
        "/*",
        " * Generated by utils/lexbor/css/gen_state_extra.py",
        f" * Date: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}",
        " * Do not edit manually!",
        " */",
        "",
        "#include \"lexbor/css/parser.h\"",
        "#include \"lexbor/css/property.h\"",
        "#include \"lexbor/css/property/state.h\"",
        "#include \"lexbor/css/property/init.h\"",
        ""
    ]
    
    # Generate parser functions for each property
    for prop_name, prop_def in additional_styles.items():
        file_content.append(generate_property_parser(prop_name, prop_def))
        file_content.append("")  # Add a blank line between functions
    
    return "\n".join(file_content)

def main():
    # Determine output location
    output_dir = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(ABS_PATH))), 
                             "source", "lexbor", "css", "property")
    os.makedirs(output_dir, exist_ok=True)
    
    output_file = os.path.join(output_dir, "state_extra.c")
    
    # Generate and write the code
    code = generate_state_extra_c()
    with open(output_file, 'w') as f:
        f.write(code)
    
    print(f"Successfully generated {output_file} with {len(additional_styles)} CSS property parsers")

if __name__ == "__main__":
    main()
