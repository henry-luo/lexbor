#!/usr/bin/env python3

import sys, os, datetime

# Add the directory to the Python path
ABS_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.append("{}/../lexbor/".format(ABS_PATH))

# Import the CSS property definitions
from names_extra import additional_styles

def create_c_identifier(property_name):
    """Convert CSS property name to a C identifier"""
    return property_name.replace("-", "_")

def generate_function_declaration(property_name):
    """Generate the function declaration for a property parser"""
    c_prop = create_c_identifier(property_name)
    return f"LXB_API bool lxb_css_property_state_{c_prop}(lxb_css_parser_t *parser, lxb_css_syntax_token_t *token, void *ctx);"

def generate_state_extra_h():
    """Generate the complete state_extra.h file"""
    file_content = ["\n"]
    
    # Generate function declarations for each property
    for prop_name in additional_styles.keys():
        file_content.append(generate_function_declaration(prop_name))
    
    return "\n".join(file_content)

def gen_state_h():
    # Determine output location
    output_dir = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(ABS_PATH))), 
                             "source", "lexbor", "css", "property")
    os.makedirs(output_dir, exist_ok=True)
    
    output_file = os.path.join(output_dir, "state_extra.h")
    
    # Generate and write the code
    code = generate_state_extra_h()
    with open(output_file, 'a') as f:
        f.write(code)
    
    print(f"Successfully generated {output_file} with {len(additional_styles)} CSS property function declarations")

if __name__ == "__main__":
    gen_state_h()
