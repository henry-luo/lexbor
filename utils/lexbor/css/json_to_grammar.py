#!/usr/bin/env python3
import json
import sys
import os
import re
from collections import defaultdict

def format_constraints(constraints):
    """Format constraints for a reference."""
    if not constraints:
        return ""
    
    parts = []
    for key, value in constraints.items():
        parts.append(f"{key}={value}")
    
    return " " + " ".join(parts) if parts else ""

def format_value(value):
    """Format a value node from JSON to grammar text format"""
    if not isinstance(value, dict):
        return str(value)
    
    value_type = value.get("type")
    
    if value_type == "Literal":
        return value.get("value")
    
    elif value_type == "Reference":
        name = value.get("name")
        constraints = format_constraints(value.get("constraints", {}))
        return f"<{name}{constraints}>"
    
    elif value_type == "ValueList":
        values = value.get("values", [])
        operator = value.get("operator", "|")
        
        formatted_values = [format_value(v) for v in values]
        
        if operator == "|":
            return " | ".join(formatted_values)
        elif operator == "||":
            return " || ".join(formatted_values)
        elif operator == "&&":
            return " && ".join(formatted_values)
        else:
            return " ".join(formatted_values)
    
    # Default case
    return str(value)

def extract_sections_and_rules(txt_file):
    """Extract section comments and their associated rules from original grammar file"""
    sections = []
    current_section = {"comment": [], "rules": []}
    in_section_comment = False
    
    try:
        with open(txt_file, 'r') as f:
            for line in f:
                line = line.rstrip('\n')
                
                # Handle section comments
                if line.strip().startswith('/*'):
                    in_section_comment = True
                    if current_section["comment"] or current_section["rules"]:
                        sections.append(current_section)
                        current_section = {"comment": [], "rules": []}
                    current_section["comment"].append(line)
                elif in_section_comment and line.strip().endswith('*/'):
                    in_section_comment = False
                    current_section["comment"].append(line)
                elif in_section_comment:
                    current_section["comment"].append(line)
                # Blank line within a section
                elif line.strip() == '':
                    if in_section_comment:
                        current_section["comment"].append(line)
                    else:
                        current_section["rules"].append(line)
                # Extract rule name for categorization
                elif line.strip().startswith('<') and '=' in line:
                    rule_name = line.split('<', 1)[1].split('>', 1)[0].strip()
                    current_section["rules"].append((rule_name, line))
    
        # Add the last section
        if current_section["comment"] or current_section["rules"]:
            sections.append(current_section)
            
    except FileNotFoundError:
        # If original file not found, create a default structure
        sections = [
            {"comment": ["/* CSS Grammar */"], "rules": []}
        ]
    
    return sections

def categorize_rules(data, original_sections):
    """Categorize JSON rules based on sections from the original grammar"""
    # Create a mapping of rule names to their sections
    rule_to_section = {}
    for idx, section in enumerate(original_sections):
        for rule_item in section["rules"]:
            if isinstance(rule_item, tuple):
                rule_name, _ = rule_item
                rule_to_section[rule_name] = idx
    
    # Process rules from JSON
    rules_by_name = defaultdict(list)
    for rule in data:
        if rule.get("type") == "Rule":
            name = rule.get("name")
            rules_by_name[name].append(rule)
    
    # Format rules and organize by section
    formatted_rules = []
    section_rules = defaultdict(list)
    
    # Process each group of rules
    for name, rules in rules_by_name.items():
        # Skip empty or special names
        if not name or name.startswith("--"):
            for rule in rules:
                formatted_rules.append(f"{name}")
            continue
        
        # Format the rules
        if len(rules) == 1 or name in ["number", "length"]:
            for rule in rules:
                value = format_value(rule.get("value"))
                formatted_rule = f"<{name}> = {value}"
                section_idx = rule_to_section.get(name, 0)  # Default to first section if not found
                section_rules[section_idx].append(formatted_rule)
        else:
            # For multiple rules with same name
            values = [format_value(rule.get("value")) for rule in rules]
            formatted_rule = f"<{name}> = {' | '.join(values)}"
            section_idx = rule_to_section.get(name, 0)
            section_rules[section_idx].append(formatted_rule)
    
    return section_rules

def convert_json_to_grammar(json_file, output_file=None):
    """Convert grammar.json to grammar.txt format"""
    with open(json_file, 'r') as f:
        data = json.load(f)
    
    # Get section structure from original file if available
    txt_file = json_file.replace('.json', '.txt')
    original_sections = extract_sections_and_rules(txt_file)
    
    # Categorize rules from JSON by section
    section_rules = categorize_rules(data, original_sections)
    
    # Merge sections with their rules
    result_lines = []
    for idx, section in enumerate(original_sections):
        # Add section comments
        result_lines.extend(section["comment"])
        
        # Add blank line after section comment if not already there
        if section["comment"] and not section["comment"][-1].strip() == "":
            result_lines.append("")
        
        # Add rules for this section
        if idx in section_rules:
            result_lines.extend(section_rules[idx])
            
            # Add blank line after rules if not the last section
            if idx < len(original_sections) - 1:
                result_lines.append("")
    
    # Add any rules that weren't categorized to the end
    uncategorized = []
    for idx in section_rules:
        if idx >= len(original_sections):
            uncategorized.extend(section_rules[idx])
    
    if uncategorized:
        if result_lines and not result_lines[-1].strip() == "":
            result_lines.append("")
        result_lines.append("/* Uncategorized Rules */")
        result_lines.append("")
        result_lines.extend(uncategorized)
    
    # Write output
    result = "\n".join(result_lines)
    if output_file:
        with open(output_file, 'w') as f:
            f.write(result)
        print(f"Grammar written to {output_file}")
    else:
        print(result)

if __name__ == "__main__":
    json_file = "./grammar.json"
    output_file = "./grammar.output.txt"
    
    if len(sys.argv) > 1:
        json_file = sys.argv[1]
    if len(sys.argv) > 2:
        output_file = sys.argv[2]
    
    convert_json_to_grammar(json_file, output_file)
    
    print("\nNote: This conversion provides an approximation of the original grammar format.")
    print("Manual editing may be needed for special notations like ^WS, {1,4}, etc.")
    print("and for complex nested structures not fully represented in the JSON.")
