#!/usr/bin/env python3
"""
Generate C header file for CSS properties from names_extra.py
This script imports the additional CSS properties from names_extra.py and generates
the struct declarations and function prototypes for each property.
Output is written to property_extra.h by default.
"""

import os
import sys
import re
from names_extra import additional_styles

# Find and append run script dir to module search path
ABS_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.append(f"{ABS_PATH}/../lexbor/")

# Helper function to convert property name to C function name format
def to_c_func_name(property_name):
    return property_name.replace('-', '_')

# Helper function to convert property name to C struct name format
def to_c_struct_name(property_name):
    return f"lxb_css_property_{to_c_func_name(property_name)}_t"

# Generate struct declaration for a property based on its value types
def generate_property_struct(prop_name, prop_data):
    c_func_name = to_c_func_name(prop_name)
    c_struct_name = to_c_struct_name(prop_name)
    
    values = prop_data.get("values", [])
    
    # Determine struct fields based on property type
    if "color" in prop_name:
        fields = "    lxb_css_value_color_t color;"
    elif "_length" in values and "_percentage" in values:
        fields = "    lxb_css_value_length_percentage_t value;"
    elif "radius" in prop_name:
        # Border radius properties have multiple values
        fields = """    lxb_css_value_length_percentage_t top_left;
    lxb_css_value_length_percentage_t top_right;
    lxb_css_value_length_percentage_t bottom_right;
    lxb_css_value_length_percentage_t bottom_left;"""
    elif any(box in prop_name for box in ["margin", "padding"]):
        fields = """    lxb_css_value_length_percentage_t top;
    lxb_css_value_length_percentage_t right;
    lxb_css_value_length_percentage_t bottom;
    lxb_css_value_length_percentage_t left;"""
    else:
        # Default case for simple properties
        fields = "    lxb_css_value_type_t type;"
    
    struct_decl = f"""
typedef struct {{
{fields}
}}
{c_struct_name};
"""
    return struct_decl

# Generate function prototypes for a property
def generate_property_prototypes(prop_name):
    c_func_name = to_c_func_name(prop_name)
    
    create_proto = f"""
LXB_API void *
lxb_css_property_{c_func_name}_create(lxb_css_memory_t *memory);"""
    
    destroy_proto = f"""
LXB_API void *
lxb_css_property_{c_func_name}_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);"""
    
    serialize_proto = f"""
LXB_API lxb_status_t
lxb_css_property_{c_func_name}_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);"""
    
    return create_proto + destroy_proto + serialize_proto

# Generate file header with include guards
def generate_file_header():
    return """/*
 * Copyright (C) 2023 Alexander Borisov
 *
 * Author: Alexander Borisov <borisov@lexbor.com>
 */

#ifndef LEXBOR_CSS_PROPERTY_EXTRA_H
#define LEXBOR_CSS_PROPERTY_EXTRA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lexbor/core/str.h"
#include "lexbor/css/css.h"
// #include "lexbor/css/property.h"
#include "lexbor/css/value.h"

/* Struct definitions */
"""

# Generate file footer with closing include guards
def generate_file_footer():
    return """
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LEXBOR_CSS_PROPERTY_EXTRA_H */
"""

# Main function to generate the header file
def main():
    # Default output file is property_extra.h in the include directory
    default_output_file = os.path.join(os.path.dirname(ABS_PATH), '..', '..', 'source', 'lexbor', 'css', 'property_extra.h')
    
    # Use command line argument if provided, otherwise use default
    output_file = sys.argv[1] if len(sys.argv) > 1 else default_output_file
    
    with open(output_file, 'w') as f:
        # Write header with include guards
        f.write(generate_file_header())
        
        # Write struct definitions
        f.write("\n/* Struct definitions */\n")
        for prop_name, prop_data in additional_styles.items():
            f.write(generate_property_struct(prop_name, prop_data))
        
        # Write function prototypes
        f.write("\n/* Function prototypes */\n")
        for prop_name in additional_styles.keys():
            f.write(generate_property_prototypes(prop_name))
        
        # Write footer with closing include guard
        f.write(generate_file_footer())
    
    print(f"Generated header file written to {output_file}")

if __name__ == "__main__":
    main()
