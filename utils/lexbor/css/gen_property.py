#!/usr/bin/env python3
"""
Generate C functions for CSS properties from names_extra.py
This script imports the additional CSS properties from names_extra.py and generates
the create, destroy, and serialize C functions for each property.
Output is written to property_extra.c by default.
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

# Determine serialization approach based on property values and initial
def determine_serialization_approach(prop_name, prop_data):
    values = prop_data.get("values", [])
    initial = prop_data.get("initial", "")
    
    # Check if it's a color property
    if "color" in prop_name:
        return "color"
    
    # Check if it's a length/percentage property
    if "_length" in values and "_percentage" in values:
        return "length_percentage"
    
    # Check if it's a simple type property (most common case)
    if initial and ".type = " in initial:
        return "type"
    
    # Complex properties with multiple fields
    if "radius" in prop_name or "margin" in prop_name or "padding" in prop_name:
        return "box"
    
    # Composite properties like border, transition, animation
    if prop_name in ["border-image", "transition", "animation", "columns", "column-rule"]:
        return "composite"
    
    # Default to type-based serialization
    return "type"

# Generate all three functions for a property
def generate_property_functions(prop_name):
    c_func_name = to_c_func_name(prop_name)
    c_struct_name = to_c_struct_name(prop_name)
    serialization = determine_serialization_approach(prop_name, additional_styles[prop_name])
    
    create_func = f"""
/* {prop_name}. */

LXB_API void *
lxb_css_property_{c_func_name}_create(lxb_css_memory_t *memory)
{{
    return lexbor_mraw_calloc(memory->mraw, sizeof({c_struct_name}));
}}
"""
    
    destroy_func = f"""
LXB_API void *
lxb_css_property_{c_func_name}_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}}
"""
    
    # Generate serialization function based on the determined approach
    if serialization == "color":
        serialize_func = f"""
LXB_API lxb_status_t
lxb_css_property_{c_func_name}_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{{
    return lxb_css_value_color_serialize(style, cb, ctx);
}}
"""
    elif serialization == "length_percentage":
        serialize_func = f"""
LXB_API lxb_status_t
lxb_css_property_{c_func_name}_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}}
"""
    elif serialization == "box" and "radius" in prop_name:
        serialize_func = f"""
LXB_API lxb_status_t
lxb_css_property_{c_func_name}_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{{
    lxb_status_t status;
    const {c_struct_name} *br = style;
    
    static const lexbor_str_t str_ws = lexbor_str(" ");

    /* First value */
    status = lxb_css_value_length_percentage_sr(&br->top_left, cb, ctx);
    if (status != LXB_STATUS_OK) {{
        return status;
    }}

    if (br->top_right.type == LXB_CSS_VALUE__UNDEF) {{
        return LXB_STATUS_OK;
    }}

    /* Second value */
    lexbor_serialize_write(cb, str_ws.data, str_ws.length, ctx, status);

    status = lxb_css_value_length_percentage_sr(&br->top_right, cb, ctx);
    if (status != LXB_STATUS_OK) {{
        return status;
    }}

    /* Add more values based on property */
    /* ... */

    return LXB_STATUS_OK;
}}
"""
    elif serialization == "composite":
        serialize_func = f"""
LXB_API lxb_status_t
lxb_css_property_{c_func_name}_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{{
    bool ws_print;
    lxb_status_t status;
    const {c_struct_name} *comp = style;
    
    static const lexbor_str_t str_ws = lexbor_str(" ");

    ws_print = false;

    /* Serialize each component with space between them */
    /* Component serialization depends on property structure */
    /* ... */

    return LXB_STATUS_OK;
}}
"""
    else:  # Default type-based serialization
        serialize_func = f"""
LXB_API lxb_status_t
lxb_css_property_{c_func_name}_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{{
    const {c_struct_name} *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}}
"""
    
    return create_func + destroy_func + serialize_func

# Main function to generate code for all properties
def generate_all_property_functions():
    output = []
    
    for prop_name in additional_styles.keys():
        output.append(generate_property_functions(prop_name))
    
    return ''.join(output)

# Generate file header
def generate_file_header():
    return """/*
 * Copyright (C) 2023 Alexander Borisov
 *
 * Author: Alexander Borisov <borisov@lexbor.com>
 */

#include "lexbor/css/css.h"
#include "lexbor/css/property.h"
#include "lexbor/css/parser.h"
#include "lexbor/css/stylesheet.h"
#include "lexbor/css/property/state.h"
#include "lexbor/css/property/res.h"
#include "lexbor/core/serialize.h"
#include "lexbor/core/conv.h"

"""

# Main script execution
def gen_property_c():
    # Default output file is property_extra.c in the source directory
    default_output_file = os.path.join(os.path.dirname(ABS_PATH), '..', '..', 'source', 'lexbor', 'css', 'property_extra.c')
    
    # Use command line argument if provided, otherwise use default
    output_file = sys.argv[1] if len(sys.argv) > 1 else default_output_file
    
    with open(output_file, 'a') as f:
        # f.write(generate_file_header())
        f.write(generate_all_property_functions())
    
    print(f"Generated code written to {output_file}")

if __name__ == "__main__":
    gen_property_c()
