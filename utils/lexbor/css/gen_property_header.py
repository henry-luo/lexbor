#!/usr/bin/env python3
"""
Generate C header file for CSS properties from grammar.txt
This script parses the CSS grammar rules and generates
the struct declarations, enum definitions, and function prototypes.

Usage:
  python3 gen_property_from_grammar.py [output_file]

The script will parse grammar.txt and produce a header file with:
1. Enum definitions for property values
2. Struct definitions for CSS properties
3. Function prototypes for working with these properties
"""

import os
import sys
import re
from collections import defaultdict
from names_extra import additional_styles

# Find and append run script dir to module search path
ABS_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.append(f"{ABS_PATH}/../lexbor/")

# Constants
DEFAULT_OUTPUT_FILE = os.path.join(os.path.dirname(ABS_PATH), '..', '..', 'source', 'lexbor', 'css', 'property_extra.h')
GRAMMAR_FILE = os.path.join(ABS_PATH, 'grammar.txt')
IGNORED_TYPES = ["value", "number", "integer", "length", "percentage"]

# Helper function to convert property name to C function name format
def to_c_func_name(property_name):
    return property_name.replace('-', '_')

# Helper function to convert property name to C struct name format
def to_c_struct_name(property_name):
    return f"lxb_css_property_{to_c_func_name(property_name)}_t"

# Normalize CSS type name
def normalize_css_type_name(type_name):
    """Normalize a CSS type name"""
    # Replace double underscores with single underscore
    normalized = type_name.replace('__', '_')
    # Remove leading/trailing underscores
    normalized = normalized.strip('_')
    return normalized

# Parse the grammar.txt file
def parse_grammar_file(file_path):
    """Parse the CSS grammar file and extract property definitions"""
    properties = {}
    
    try:
        with open(file_path, 'r') as f:
            content = f.read()
            
        # Extract property definitions
        # Pattern: <property-name> = <definition>
        property_pattern = r'<([a-z0-9-]+)>\s*=\s*([^\n]+)'
        matches = re.findall(property_pattern, content)
        
        for prop_name, definition in matches:
            # Skip meta-definitions (those in angle brackets that aren't CSS properties)
            if prop_name.startswith('color') or prop_name.startswith('border') or prop_name in [
                'global', 'relative-units', 'absolute-units', 'angle-units', 'time-units',
                'frequency-units', 'resolution-units', 'angle', 'angle-90-deg', 'time', 
                'frequency', 'resolution', 'length', 'length-percentage', 'min-max', 
                'padding-value', 'margin-value', 'border-values', 'line-width', 'line-style',
                'color-handler', 'absolute-color-base', 'absolute-color-function',
                'hex-color', 'alpha-value', 'hue', 'named-color', 'system-color', 'rgb()',
                'rgba()', 'hsl()', 'hsla()', 'hwb()', 'lab()', 'lch()', 'oklab()', 'oklch()',
                'generic-family', 'font-weight-absolute', 'absolute-size', 'relative-size',
                'snap-block()', 'snap-inline()', 'declarations', 'box-sizing'
            ]:
                continue
                
            # Extract values from the definition
            values = extract_values_from_definition(definition)
            
            # Skip if it's not a direct CSS property
            if not values or '||' in definition or prop_name == 'filter-function':
                continue
                
            # Store the property and its values
            properties[prop_name] = {
                'values': values,
                'definition': definition
            }
    
    except Exception as e:
        print(f"Error parsing grammar file: {e}")
        return {}
    
    return properties

# Extract values from a property definition
def extract_values_from_definition(definition):
    """Extract the possible values from a property definition"""
    values = []
    
    # Extract identifiers (words that aren't wrapped in angle brackets)
    # Matches: word, word1, word-word, but not <word>, [word], #{word}, etc.
    ident_pattern = r'\b([a-z][\w-]+)\b(?![>\]])'
    identifiers = re.findall(ident_pattern, definition)
    
    # Add explicit values
    for ident in identifiers:
        if ident not in ['min', 'max', 'none'] and not ident.endswith('units'):
            values.append(ident)
    
    # Look for value types referenced in angle brackets
    type_pattern = r'<([a-z0-9-]+)>'
    types = re.findall(type_pattern, definition)
    
    for type_name in types:
        if type_name == 'color':
            values.append('_color')
        elif type_name == 'length':
            values.append('_length')
        elif type_name == 'percentage':
            values.append('_percentage')
        elif type_name == 'length-percentage':
            values.append('_length')
            values.append('_percentage')
        elif type_name == 'number':
            values.append('_number')
        elif type_name == 'integer':
            values.append('_integer')
        elif type_name == 'string':
            values.append('_string')
        elif type_name == 'url':
            values.append('_url')
        elif type_name == 'angle':
            values.append('_angle')
        elif type_name == 'time':
            values.append('_time')
    
    return values

# Determine field type based on property values
def determine_field_type(values):
    """Determine the C struct field type based on property values"""
    if "_color" in values:
        return "lxb_css_value_color_t"
    elif "_length" in values and "_percentage" in values:
        return "lxb_css_value_length_percentage_t"
    elif "_length" in values:
        return "lxb_css_value_length_t"
    elif "_percentage" in values:
        return "lxb_css_value_percentage_t"
    elif "_number" in values:
        return "lxb_css_value_number_t"
    elif "_string" in values:
        return "lxb_css_value_string_t"
    elif "_url" in values:
        return "lxb_css_value_url_t"
    elif "_integer" in values:
        return "lxb_css_value_integer_t"
    elif "_angle" in values:
        return "lxb_css_value_angle_t"
    elif "_time" in values:
        return "lxb_css_value_time_t"
    else:
        return "lxb_css_value_type_t"

# Generate enum values for a property
def generate_enum_values(prop_name, values):
    """Generate enum values for a property based on its allowed values"""
    enum_values = set()
    
    # Convert property name to uppercase for enum prefix
    prop_upper = prop_name.replace('-', '_').upper()
    
    # Add standard values as enum entries
    for value in values:
        # Skip value types (those starting with underscore)
        if value.startswith('_'):
            continue
            
        # Convert value to enum format
        enum_value = value.replace('-', '_').upper()
        enum_values.add(enum_value)
    
    return enum_values

# Generate struct definition for a property
def generate_property_struct(prop_name, prop_data):
    """Generate a C struct definition for a CSS property"""
    c_func_name = to_c_func_name(prop_name)
    c_struct_name = to_c_struct_name(prop_name)
    
    values = prop_data.get('values', [])
    definition = prop_data.get('definition', '')
    
    # If this is a box-model property (margin, padding, border)
    if prop_name in ['margin', 'padding'] or prop_name in ['border'] or prop_name.startswith('border-') and prop_name.endswith(('-color', '-style', '-width')):
        field_type = determine_field_type(values)
        fields_str = f"""    {field_type} top;
    {field_type} right;
    {field_type} bottom;
    {field_type} left;"""
    
    # If this is a radius property
    elif 'radius' in prop_name:
        field_type = determine_field_type(values)
        fields_str = f"""    {field_type} top_left;
    {field_type} top_right;
    {field_type} bottom_right;
    {field_type} bottom_left;"""
    
    # If this is a color property
    elif prop_name == 'color' or prop_name.endswith('-color'):
        fields_str = "    lxb_css_value_color_t color;"
    
    # If multiple values are allowed (using # or +)
    elif '#' in definition or '+' in definition:
        field_type = determine_field_type(values)
        fields_str = f"""    {field_type} *values;
    size_t length;"""
    
    # If this is a shadow property
    elif 'shadow' in prop_name:
        fields_str = """    lxb_css_value_shadow_t *shadows;
    size_t length;"""
    
    # If this is a transition property
    elif 'transition' in prop_name and prop_name != 'transition-property' and prop_name != 'transition-duration':
        fields_str = """    lxb_css_value_transition_t *transitions;
    size_t length;"""
    
    # If this is an animation property
    elif 'animation' in prop_name and prop_name != 'animation-name' and prop_name != 'animation-duration':
        fields_str = """    lxb_css_value_animation_t *animations;
    size_t length;"""
        
    # For background properties
    elif prop_name.startswith('background-'):
        # Extract the specific background property type
        bg_type = prop_name.split('-')[1]
        
        # Use enum type if it's an enumerated property
        if any(not v.startswith('_') for v in values):
            fields_str = f"    lxb_css_background_{bg_type}_type_t type;"
        else:
            field_type = determine_field_type(values)
            fields_str = f"    {field_type} value;"
    
    # Most other properties can be represented with a type field or a value field
    else:
        # Check if this should be a type enum or a value
        has_enum_values = any(not v.startswith('_') for v in values)
        
        if has_enum_values:
            fields_str = f"    lxb_css_{c_func_name}_type_t type;"
        else:
            field_type = determine_field_type(values)
            fields_str = f"    {field_type} value;"
    
    struct_decl = f"""
typedef struct {{
{fields_str}
}}
{c_struct_name};
"""
    return struct_decl

# Generate function prototypes for a property
def generate_property_prototypes(prop_name):
    """Generate function prototypes for a CSS property"""
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

# Extract enum types from properties
def extract_enum_types_from_properties(properties):
    """Extract enum types and their values from property definitions"""
    enum_types = defaultdict(set)
    
    # Process each property
    for prop_name, prop_data in properties.items():
        values = prop_data.get('values', [])
        c_func_name = to_c_func_name(prop_name)
        
        # Only consider properties with non-type values (not starting with _)
        enum_values = [v for v in values if not v.startswith('_')]
        if enum_values:
            # For background properties, use background_* enum types
            if prop_name.startswith('background-'):
                bg_type = prop_name.split('-')[1]
                type_name = f"background_{bg_type}"
            else:
                type_name = c_func_name
            
            # Convert values to enum format and add to the collection
            for value in enum_values:
                enum_value = value.replace('-', '_').upper()
                enum_types[type_name].add(enum_value)
    
    # Add explicit enum definitions for background properties that might be missing
    # For background-origin
    if "background_origin" not in enum_types:
        enum_types["background_origin"] = {"BORDER_BOX", "PADDING_BOX", "CONTENT_BOX"}
    
    # For background-clip
    if "background_clip" not in enum_types:
        enum_types["background_clip"] = {"BORDER_BOX", "PADDING_BOX", "CONTENT_BOX", "TEXT"}
    
    # For background-position
    if "background_position" not in enum_types:
        enum_types["background_position"] = {
            "LEFT_TOP", "LEFT_CENTER", "LEFT_BOTTOM", 
            "CENTER_TOP", "CENTER", "CENTER_BOTTOM", 
            "RIGHT_TOP", "RIGHT_CENTER", "RIGHT_BOTTOM"
        }
    
    return enum_types

# Generate enum definition
def generate_enum_definition(enum_type, enum_values):
    """Generate a C enum definition for a CSS property type"""
    # Sort values for consistency
    sorted_values = sorted(list(enum_values))
    
    # Generate the enum definition
    enum_name = f"lxb_css_{enum_type}_type_t"
    enum_prefix = enum_type.upper()
    
    enum_def = f"""
typedef enum {{
"""
    
    # Add each enum constant
    for value in sorted_values:
        enum_def += f"    LXB_CSS_{enum_prefix}_{value},\n"
    
    # Close the enum definition with a last entry marker
    enum_def += f"""    LXB_CSS_{enum_prefix}__LAST_ENTRY
}}
{enum_name};
"""
    
    return enum_def

# Generate all enum definitions
def generate_enum_definitions(properties):
    """Generate C enum definitions for all CSS property types"""
    enum_types = extract_enum_types_from_properties(properties)
    definitions = "/* Enumeration definitions */\n"
    
    # Sort enum types for consistent output
    for enum_type in sorted(enum_types.keys()):
        definitions += generate_enum_definition(enum_type, enum_types[enum_type])
    
    return definitions

# Generate file header with include guards
def generate_file_header(properties):
    """Generate the header file preamble with include guards and enums"""
    # Add enum definitions
    header = generate_enum_definitions(properties)
    
    return header

# Main function
def gen_property_h():
    target_property_name = sys.argv[1]

    output_file = DEFAULT_OUTPUT_FILE
    
    # Parse the grammar file
    print(f"Parsing grammar file: {GRAMMAR_FILE}")
    properties = parse_grammar_file(GRAMMAR_FILE)
    
    if not properties:
        print("Error: No properties were parsed from the grammar file")
        return
    
    # keeps properties defined in names_extra.py
    for prop_name in list(properties.keys()):
        # if not (prop_name in additional_styles):
        if not(prop_name == target_property_name):
            del properties[prop_name]

    # Generate the header file
    with open(output_file, 'a') as f:
        # Write header with include guards and enum definitions
        f.write(generate_file_header(properties))
        
        # Write struct definitions
        f.write("\n/* Struct definitions */\n")
        for prop_name, prop_data in properties.items():
            f.write(generate_property_struct(prop_name, prop_data))
        
        # Write function prototypes
        f.write("\n/* Function prototypes */\n")
        for prop_name in properties.keys():
            f.write(generate_property_prototypes(prop_name))
        
    
    print(f"Generated header file written to {output_file}")
    
    # Print summary of enum types found
    enum_types = extract_enum_types_from_properties(properties)
    print(f"Generated {len(enum_types)} enum type definitions")

if __name__ == "__main__":
    gen_property_h()
