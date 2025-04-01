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

# Helper function to determine appropriate field type based on value types
def determine_field_type(value_types):
    if "_color" in value_types:
        return "lxb_css_value_color_t"
    elif "_length" in value_types and "_percentage" in value_types:
        return "lxb_css_value_length_percentage_t"
    elif "_length" in value_types:
        return "lxb_css_value_length_t"
    elif "_percentage" in value_types:
        return "lxb_css_value_percentage_t"
    elif "_number" in value_types:
        return "lxb_css_value_number_t"
    elif "_string" in value_types:
        return "lxb_css_value_string_t"
    elif "_url" in value_types:
        return "lxb_css_value_url_t"
    elif "_integer" in value_types:
        return "lxb_css_value_integer_t"
    else:
        return "lxb_css_value_type_t"

# Helper function to determine field type based on initial value
def determine_field_type_from_initial(initial_value):
    """Determines the C struct field type from an initial value"""
    if isinstance(initial_value, dict):
        value_type = initial_value.get("type", "")
        if "color" in value_type:
            return "lxb_css_value_color_t"
        elif "length" in value_type and "percentage" in value_type:
            return "lxb_css_value_length_percentage_t"
        elif "length" in value_type:
            return "lxb_css_value_length_t"
        elif "percentage" in value_type:
            return "lxb_css_value_percentage_t"
        elif "number" in value_type:
            return "lxb_css_value_number_t"
        elif "string" in value_type:
            return "lxb_css_value_string_t"
        elif "url" in value_type:
            return "lxb_css_value_url_t"
        elif "integer" in value_type:
            return "lxb_css_value_integer_t"
        elif "angle" in value_type:
            return "lxb_css_value_angle_t"
        elif "time" in value_type:
            return "lxb_css_value_time_t"
        elif "frequency" in value_type:
            return "lxb_css_value_frequency_t"
        elif "ident" in value_type:
            return "lxb_css_value_ident_t"
        else:
            return "lxb_css_value_type_t"
    elif isinstance(initial_value, str):
        if initial_value.startswith("#") or initial_value in ["transparent", "currentcolor"]:
            return "lxb_css_value_color_t"
        elif "px" in initial_value or "em" in initial_value or "rem" in initial_value:
            return "lxb_css_value_length_t"
        elif "%" in initial_value:
            return "lxb_css_value_percentage_t"
        elif initial_value.isdigit() or (initial_value.replace(".", "").isdigit() and "." in initial_value):
            return "lxb_css_value_number_t"
        else:
            return "lxb_css_value_type_t"
    else:
        return "lxb_css_value_type_t"

# Enhanced function to parse initial value strings with recursive capability
def parse_initial_value_string(initial_string, depth=0):
    """Parse a C struct initializer string into a structured format with recursive handling of nested structs."""
    # Clean up the string
    initial_string = initial_string.strip()
    
    # Base case for simple values or maximum recursion
    if not initial_string.startswith("&(") and not initial_string.startswith("{"):
        return {"value": initial_string}
    
    # Extract the struct type if it exists
    struct_type = None
    if initial_string.startswith("&("):
        type_end = initial_string.find(")")
        struct_type = initial_string[2:type_end].strip()  # Remove &( and )
        # Find the start of the initializer
        init_start = initial_string.find("{")
    else:
        # This is already the initializer part
        init_start = 0
    
    # Get the initializer part between { and }
    init_end = find_matching_brace(initial_string, init_start)
    if init_start == -1 or init_end == -1:
        return {"value": initial_string}
    
    initializer = initial_string[init_start+1:init_end].strip()
    
    # Parse the fields from the initializer
    fields = parse_struct_fields(initializer)
    
    # For any field that looks like a nested struct, recursively parse it
    for field, value in list(fields.items()):
        if isinstance(value, str) and (value.startswith("{") or value.startswith("&(")):
            fields[field] = parse_initial_value_string(value, depth + 1)
    
    return fields

# Helper function to find matching closing brace
def find_matching_brace(text, start_pos):
    """Find the position of the matching closing brace."""
    if start_pos >= len(text) or text[start_pos] != '{':
        return -1
    
    depth = 0
    for i in range(start_pos, len(text)):
        if text[i] == '{':
            depth += 1
        elif text[i] == '}':
            depth -= 1
            if depth == 0:
                return i
    
    return -1

# Helper function to parse struct fields with proper handling of nested structures
def parse_struct_fields(initializer):
    """Parse fields from a C struct initializer, handling nested braces and commas."""
    fields = {}
    
    # State tracking
    current_field = ""
    current_value = ""
    in_field = True  # Are we parsing field name
    depth = 0        # Brace depth
    escape_next = False  # For handling escaped characters
    
    # Add a trailing comma to process the last field
    for i, char in enumerate(initializer + ","):
        # Handle escaped characters
        if escape_next:
            if in_field:
                current_field += char
            else:
                current_value += char
            escape_next = False
            continue
            
        if char == '\\':
            escape_next = True
            if not in_field:
                current_value += char
            continue
            
        # Track brace depth
        if char == '{':
            depth += 1
            current_value += char
            in_field = False
            continue
        elif char == '}':
            depth -= 1
            current_value += char
            continue
            
        # Field/value separation logic only applies at depth 0
        if depth == 0:
            if char == '.' and in_field:
                # Start of a field
                current_field = ""
                continue
            elif char == '=' and in_field:
                # Transition from field name to value
                in_field = False
                continue
            elif char == ',' and not in_field:
                # End of field-value pair
                if current_field.strip():
                    fields[current_field.strip()] = current_value.strip()
                current_field = ""
                current_value = ""
                in_field = True
                continue
        
        # Add character to current field/value
        if in_field:
            current_field += char
        else:
            current_value += char
    
    return fields

# Normalize CSS type name by fixing double underscores and removing leading/trailing underscores
def normalize_css_type_name(type_name):
    """Normalize a CSS type name extracted from enum constants"""
    # Replace double underscores with single underscore
    normalized = type_name.replace('__', '_')
    # Remove leading/trailing underscores
    normalized = normalized.strip('_')
    return normalized

# Determine field type from a parsed initializer value with proper type structure
def determine_field_type_from_parsed(field_name, field_value, prop_name=None):
    """Determine the appropriate C type for a field based on its name and parsed value."""
    # Base property type format for common CSS properties
    base_prop_type = f"lxb_css_property_{field_name}_t" if prop_name is None else f"lxb_css_property_{to_c_func_name(prop_name)}_{field_name}_t"
    
    # Special handling for background-related properties
    if prop_name and prop_name.startswith("background-"):
        # Extract the background property type (e.g., "clip", "position")
        bg_prop_type = prop_name.split("-")[1] if len(prop_name.split("-")) > 1 else ""
        
        # For background property types with specific type handling
        if field_name == "type" and bg_prop_type:
            return f"lxb_css_background_{bg_prop_type}_type_t"
    
    # Check for specialized cases matching property.h patterns
    # Most properties in property.h are custom property types, not basic value types
    
    # Handle specific known property types that have dedicated structures
    if field_name in ["color", "background_color", "border_top_color", "border_right_color", 
                     "border_bottom_color", "border_left_color", "text_decoration_color"]:
        return "lxb_css_value_color_t"
        
    # Width/height and positional properties typically use length_percentage type
    elif field_name in ["width", "height", "min_width", "min_height", "max_width", 
                      "max_height", "top", "right", "bottom", "left"]:
        return "lxb_css_value_length_percentage_t"
    
    # For nested structures from known properties
    elif field_name in ["style", "width", "color"] and prop_name:
        prop_base = None
        if "border" in prop_name:
            prop_base = "border"
        elif "outline" in prop_name:
            prop_base = "outline"
        elif "column_rule" in prop_name:
            prop_base = "column_rule"
            
        if prop_base:
            return f"lxb_css_property_{prop_base}_{field_name}_t"
    
    # If we have a nested dict with type field, convert to appropriate property type
    if isinstance(field_value, dict) and "type" in field_value:
        type_value = field_value["type"]
        if isinstance(type_value, str) and type_value.startswith("LXB_CSS_"):
            # Extract the property type from the enum
            # Example: LXB_CSS_BACKGROUND_IMAGE_NONE -> background_image
            parts = type_value.split("_")
            if len(parts) >= 3:
                # Get the property type portion, convert to lowercase
                prop_type = "_".join(parts[2:-1]).lower()
                prop_type = normalize_css_type_name(prop_type)
                if prop_type:
                    # Look for matching struct pattern in property.h
                    return f"lxb_css_property_{prop_type}_t"
    
    # Default generic value types based on field name
    if "color" in field_name:
        return "lxb_css_value_color_t"
    elif "length" in field_name:
        return "lxb_css_value_length_t"
    elif "percentage" in field_name:
        return "lxb_css_value_percentage_t"
    elif "time" in field_name:
        return "lxb_css_value_time_t"
    elif "number" in field_name:
        return "lxb_css_value_number_t"
    elif "integer" in field_name:
        return "lxb_css_value_integer_t"
    elif field_name == "type":
        return "lxb_css_value_type_t"
    
    # If we have a string containing an enum
    if isinstance(field_value, str) and field_value.startswith("LXB_CSS_"):
        enum_parts = field_value.split("_")
        if len(enum_parts) >= 3:
            enum_prefix = enum_parts[2].lower()
            return f"lxb_css_{enum_prefix}_type_t"
    
    # Default case
    return "lxb_css_value_type_t"

# Generate fields recursively for nested structs with correct type format
def generate_fields_recursively(field_name, field_value, prop_name=None):
    """Generate C struct fields recursively handling nested structures."""
    fields = []
    field_c_name = to_c_func_name(field_name)
    
    # Handle nested dictionary structures
    if isinstance(field_value, dict) and field_value != {} and "value" not in field_value:
        # Check if this is a type-based field
        if "type" in field_value:
            type_value = field_value.get("type")
            if isinstance(type_value, str) and type_value.startswith("LXB_CSS_"):
                # This is an enum-based field - pattern found in property.h
                enum_parts = type_value.split("_")
                if len(enum_parts) >= 4:
                    type_enum = "_".join(enum_parts[2:-1]).lower()
                    type_enum = normalize_css_type_name(type_enum)
                    fields.append(f"    lxb_css_{type_enum}_type_t type;")
                    return fields
        
        # For composite property types (like border, margin) with sub-properties
        field_type = determine_field_type_from_parsed(field_name, field_value, prop_name)
        fields.append(f"    {field_type} {field_c_name};")
    else:
        # For leaf values
        if isinstance(field_value, dict) and "value" in field_value:
            simple_value = field_value["value"]
            field_type = determine_field_type_from_initial(simple_value)
        else:
            # For enum constants, use type field pattern
            if isinstance(field_value, str) and field_value.startswith("LXB_CSS_"):
                # Extract type from enum (e.g., LXB_CSS_TEXT_ALIGN_CENTER -> text_align)
                enum_parts = field_value.split("_")
                if len(enum_parts) >= 4:
                    type_name = "_".join(enum_parts[2:-1]).lower()
                    type_name = normalize_css_type_name(type_name)
                    fields.append(f"    lxb_css_{type_name}_type_t type;")
                    return fields
            
            field_type = determine_field_type_from_parsed(field_name, field_value, prop_name)
        
        # Handle array types
        if isinstance(field_value, list) or field_name in ["shadows", "transitions", "values"]:
            base_type = field_type.replace("*", "")
            fields.append(f"    {base_type} *{field_c_name};")
            fields.append("    size_t length;")
        else:
            fields.append(f"    {field_type} {field_c_name};")
    
    return fields

# Enhanced function to parse enum types from initializer strings
def parse_enum_type_from_initializer(initializer):
    """Extract enum type from initializer string like '.type = LXB_CSS_BACKGROUND_CLIP_BORDER_BOX'"""
    if not isinstance(initializer, str):
        return None
    
    # Look for enum pattern
    match = re.search(r'\.type\s*=\s*LXB_CSS_([A-Z][A-Z0-9_]+)_([A-Z][A-Z0-9_]+)', initializer)
    if match:
        enum_type = match.group(1).lower()
        enum_value = match.group(2)
        
        # Normalize the enum type name
        enum_type = normalize_css_type_name(enum_type)
        
        return enum_type
    
    return None

# Generate struct declaration for a property based on its value types
def generate_property_struct(prop_name, prop_data):
    c_func_name = to_c_func_name(prop_name)
    c_struct_name = to_c_struct_name(prop_name)
    
    # Use initials if available to determine fields
    if "initial" in prop_data and prop_data["initial"]:
        initial = prop_data["initial"]
        fields = []
        
        # Check if this is a simple enum-based property
        enum_type = parse_enum_type_from_initializer(initial)
        if enum_type:
            # For background-related properties, use the specific background enum type
            if "background" in prop_name:
                # Extract the specific background property type (e.g., "clip", "position")
                bg_type = prop_name.split("-")[1] if len(prop_name.split("-")) > 1 else "background"
                fields = [f"    lxb_css_background_{bg_type}_type_t type;"]
            else:
                fields = [f"    lxb_css_{enum_type}_type_t type;"]
        else:
            # Parse C struct initializer strings recursively
            if isinstance(initial, str) and initial.startswith("&("):
                parsed_initial = parse_initial_value_string(initial)
                
                # Special case for enum-based simple types
                if len(parsed_initial) == 1 and "type" in parsed_initial:
                    type_value = parsed_initial["type"]
                    if isinstance(type_value, str) and type_value.startswith("LXB_CSS_"):
                        # Extract property type from enum (e.g., LXB_CSS_DISPLAY_BLOCK -> display)
                        parts = type_value.split("_")
                        if len(parts) >= 4:
                            type_name = parts[2].lower()
                            type_name = normalize_css_type_name(type_name)
                            fields = [f"    lxb_css_{type_name}_type_t type;"]
                else:
                    # Generate fields for each parsed field recursively
                    for field_name, field_value in parsed_initial.items():
                        fields.extend(generate_fields_recursively(field_name, field_value, prop_name))
            else:
                # Original handling for non-C-initializer formats
                if isinstance(initial, str):
                    initial = parse_initial_value_string(initial)
                
                for field_name, field_value in initial.items():
                    field_c_name = to_c_func_name(field_name)
                    field_type = determine_field_type_from_initial(field_value)
                    
                    # Check if this is a list/array type field
                    if isinstance(field_value, list) or field_name in ["shadows", "transitions", "values"]:
                        base_type = field_type.replace("*", "")
                        fields.append(f"    {base_type} *{field_c_name};")
                        fields.append("    size_t length;")
                    else:
                        fields.append(f"    {field_type} {field_c_name};")
        
        fields_str = "\n".join(fields)
    else:
        # Fallback to existing logic for determining fields
        values = prop_data.get("values", [])
        value_types = " ".join(values)
        
        # Determine fields based on property definition
        if "type" in prop_data:
            property_type = prop_data["type"]
            
            # Multi-value properties
            if property_type == "box" or "box" in prop_data.get("flags", []):
                field_type = determine_field_type(value_types)
                fields_str = f"""    {field_type} top;
    {field_type} right;
    {field_type} bottom;
    {field_type} left;"""
            elif property_type == "radius" or "radius" in prop_name:
                field_type = determine_field_type(value_types)
                fields_str = f"""    {field_type} top_left;
    {field_type} top_right;
    {field_type} bottom_right;
    {field_type} bottom_left;"""
            elif property_type == "multi":
                # For properties that can have multiple values of the same type
                field_type = determine_field_type(value_types)
                fields_str = f"""    {field_type} *values;
    size_t length;"""
            elif property_type == "color" or "color" in value_types:
                fields_str = "    lxb_css_value_color_t color;"
            else:
                # Handle specific known property types
                if "shadow" in prop_name:
                    fields_str = """    lxb_css_value_shadow_t *shadows;
    size_t length;"""
                elif "transition" in prop_name:
                    fields_str = """    lxb_css_value_transition_t *transitions;
    size_t length;"""
                else:
                    # Default case based on values
                    field_type = determine_field_type(value_types)
                    fields_str = f"    {field_type} value;"
        else:
            # Determine fields based on property name and values
            if "color" in prop_name or "_color" in value_types:
                fields_str = "    lxb_css_value_color_t color;"
            elif any(box in prop_name for box in ["margin", "padding", "border"]):
                field_type = determine_field_type(value_types)
                fields_str = f"""    {field_type} top;
    {field_type} right;
    {field_type} bottom;
    {field_type} left;"""
            elif "radius" in prop_name:
                field_type = determine_field_type(value_types)
                fields_str = f"""    {field_type} top_left;
    {field_type} top_right;
    {field_type} bottom_right;
    {field_type} bottom_left;"""
            elif "_length" in value_types and "_percentage" in value_types:
                fields_str = "    lxb_css_value_length_percentage_t value;"
            else:
                # Default case for simple properties
                fields_str = "    lxb_css_value_type_t type;"
    
    struct_decl = f"""
typedef struct {{
{fields_str}
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

# Enhanced function to extract enum types from property initializers
def extract_enum_types_from_properties(properties):
    """Extract all enumeration types and their values from property initializers."""
    enum_types = {}
    
    for prop_name, prop_data in properties.items():
        if "initial" in prop_data and isinstance(prop_data["initial"], str):
            initial = prop_data["initial"]
            
            # Extract enum constants from the initializer string
            # Improved regex to better capture background-related enum constants
            enum_constants = re.findall(r'LXB_CSS_([A-Z][A-Z0-9_]+)_([A-Z][A-Z0-9_]+)', initial)
            
            for match in enum_constants:
                if len(match) == 2:
                    enum_type = match[0].lower()
                    enum_value = match[1]
                    
                    # Skip known non-enum types
                    if enum_type in ["value", "number", "integer", "length", "percentage"]:
                        continue
                    
                    # Normalize the enum type name
                    enum_type = normalize_css_type_name(enum_type)
                    
                    # Add to our collection
                    if enum_type not in enum_types:
                        enum_types[enum_type] = set()
                    
                    enum_types[enum_type].add(enum_value)
    
    return enum_types

# Generate C enum definition for an enum type
def generate_enum_definition(enum_type, enum_values):
    """Generate a C enum definition for a set of enum values."""
    # Sort values for consistency
    sorted_values = sorted(list(enum_values))
    
    # Generate the enum definition
    enum_name = f"lxb_css_{enum_type}_type_t"
    
    enum_def = f"""
typedef enum {{
"""
    
    # Add each enum constant
    for value in sorted_values:
        enum_def += f"    LXB_CSS_{enum_type.upper()}_{value},\n"
    
    # Close the enum definition
    enum_def += f"""    LXB_CSS_{enum_type.upper()}__LAST_ENTRY
}}
{enum_name};
"""
    
    return enum_def

# Generate all enum definitions
def generate_enum_definitions(properties):
    """Generate C enum definitions for all enumeration types."""
    enum_types = extract_enum_types_from_properties(properties)
    
    definitions = "/* Enumeration definitions */\n"
    
    # Sort enum types for consistent output
    for enum_type in sorted(enum_types.keys()):
        definitions += generate_enum_definition(enum_type, enum_types[enum_type])
    
    return definitions

# Generate file header with include guards - now includes enum definitions
def generate_file_header(properties):
    header = """/*
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

"""
    
    # Add enum definitions
    header += generate_enum_definitions(properties)
    
    header += "\n/* Struct definitions */\n"
    
    return header

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
        # Write header with include guards and enum definitions
        f.write(generate_file_header(additional_styles))
        
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
    
    # Print summary of enum types found
    enum_types = extract_enum_types_from_properties(additional_styles)
    print(f"Generated {len(enum_types)} enum type definitions")

if __name__ == "__main__":
    main()
