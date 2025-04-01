import sys, re, os, datetime

# Find and append run script run dir to module search path
ABS_PATH = os.path.dirname(os.path.abspath(__file__))
sys.path.append("{}/../lexbor/".format(ABS_PATH))

import LXB

# CSS color values (reused from names.py)
color_named = ["aliceblue", "antiquewhite", "aqua", "aquamarine", "azure",
               "beige", "bisque", "black", "blanchedalmond", "blue",
               "blueviolet", "brown", "burlywood", "cadetblue",
               "chartreuse", "chocolate", "coral", "cornflowerblue",
               "cornsilk", "crimson", "cyan", "darkblue", "darkcyan",
               "darkgoldenrod", "darkgray", "darkgreen", "darkgrey",
               "darkkhaki", "darkmagenta", "darkolivegreen", "darkorange",
               "darkorchid", "darkred", "darksalmon", "darkseagreen",
               "darkslateblue", "darkslategray", "darkslategrey",
               "darkturquoise", "darkviolet", "deeppink", "deepskyblue",
               "dimgray", "dimgrey", "dodgerblue", "firebrick", "floralwhite",
               "forestgreen", "fuchsia", "gainsboro", "ghostwhite", "gold",
               "goldenrod", "gray", "green", "greenyellow", "grey", "honeydew",
               "hotpink", "indianred", "indigo", "ivory", "khaki", "lavender",
               "lavenderblush", "lawngreen", "lemonchiffon", "lightblue",
               "lightcoral", "lightcyan", "lightgoldenrodyellow", "lightgray",
               "lightgreen", "lightgrey", "lightpink", "lightsalmon",
               "lightseagreen", "lightskyblue", "lightslategray",
               "lightslategrey", "lightsteelblue", "lightyellow", "lime",
               "limegreen", "linen", "magenta", "maroon", "mediumaquamarine",
               "mediumblue", "mediumorchid", "mediumpurple", "mediumseagreen",
               "mediumslateblue", "mediumspringgreen", "mediumturquoise",
               "mediumvioletred", "midnightblue", "mintcream", "mistyrose",
               "moccasin", "navajowhite", "navy", "oldlace", "olive",
               "olivedrab", "orange", "orangered", "orchid", "palegoldenrod",
               "palegreen", "paleturquoise", "palevioletred", "papayawhip",
               "peachpuff", "peru", "pink", "plum", "powderblue", "purple",
               "rebeccapurple", "red", "rosybrown", "royalblue", "saddlebrown",
               "salmon", "sandybrown", "seagreen", "seashell", "sienna",
               "silver", "skyblue", "slateblue", "slategray", "slategrey",
               "snow", "springgreen", "steelblue", "tan", "teal", "thistle",
               "tomato", "turquoise", "violet", "wheat", "white", "whitesmoke",
               "yellow", "yellowgreen"]

color_system = ["Canvas", "CanvasText", "LinkText", "VisitedText", "ActiveText",
                "ButtonFace", "ButtonText", "ButtonBorder", "Field", "FieldText",
                "Highlight", "HighlightText", "SelectedItem", "SelectedItemText",
                "Mark", "MarkText", "GrayText", "AccentColor", "AccentColorText"]

color_function = ["rgb", "rgba",
                  "hsl", "hsla", "hwb",
                  "lab", "lch", "oklab", "oklch",
                  "color"]

color_values = ["currentcolor", "transparent", "hex"] + color_named + color_system + color_function

# Utility values for initializers
length_0 = ".u.length = {.num = 0, .is_float = false}"
length_percentage_0 = "{.type = LXB_CSS_VALUE__LENGTH, %s}" % (length_0)
length_percentage_auto = "{.type = LXB_CSS_VALUE_AUTO, %s}" % (length_0)
time_0 = ".u.time = {.num = 0, .is_float = false, .unit = LXB_CSS_UNIT_S}"

# Additional CSS properties missing from names.py
additional_styles = {
    # Background Properties
    "background-image": {"values": ["none"], "initial": "&(lxb_css_property_background_image_t) {.type = LXB_CSS_BACKGROUND_IMAGE_NONE}"},
    "background-size": {"values": ["auto", "cover", "contain", "_length", "_percentage"], "initial": "&(lxb_css_property_background_size_t) {.type = LXB_CSS_BACKGROUND_SIZE_AUTO}"},
    "background-repeat": {"values": ["repeat", "repeat-x", "repeat-y", "no-repeat", "space", "round"], "initial": "&(lxb_css_property_background_repeat_t) {.type = LXB_CSS_BACKGROUND_REPEAT_REPEAT}"},
    "background-attachment": {"values": ["scroll", "fixed", "local"], "initial": "&(lxb_css_property_background_attachment_t) {.type = LXB_CSS_BACKGROUND_ATTACHMENT_SCROLL}"},
    "background-origin": {"values": ["padding-box", "border-box", "content-box"], "initial": "&(lxb_css_property_background_origin_t) {.type = LXB_CSS_BACKGROUND_ORIGIN_PADDING_BOX}"},
    "background-clip": {"values": ["border-box", "padding-box", "content-box", "text"], "initial": "&(lxb_css_property_background_clip_t) {.type = LXB_CSS_BACKGROUND_CLIP_BORDER_BOX}"},
    "background-position": {"values": ["left", "center", "right", "top", "bottom", "_length", "_percentage"], "initial": "&(lxb_css_property_background_position_t) {.type = LXB_CSS_BACKGROUND_POSITION_LEFT_TOP}"},
    
    # Border Radius Properties
    "border-radius": {"values": ["_length", "_percentage"], "initial": "&(lxb_css_property_border_radius_t) {.top_left = %s, .top_right = %s, .bottom_right = %s, .bottom_left = %s}" % (length_percentage_0, length_percentage_0, length_percentage_0, length_percentage_0)},
    "border-top-left-radius": {"values": ["_length", "_percentage"], "initial": "&(lxb_css_property_border_top_left_radius_t) " + length_percentage_0},
    "border-top-right-radius": {"values": ["_length", "_percentage"], "initial": "&(lxb_css_property_border_top_right_radius_t) " + length_percentage_0},
    "border-bottom-right-radius": {"values": ["_length", "_percentage"], "initial": "&(lxb_css_property_border_bottom_right_radius_t) " + length_percentage_0},
    "border-bottom-left-radius": {"values": ["_length", "_percentage"], "initial": "&(lxb_css_property_border_bottom_left_radius_t) " + length_percentage_0},
    
    # Border Image Properties
    "border-image-source": {"values": ["none"], "initial": "&(lxb_css_property_border_image_source_t) {.type = LXB_CSS_BORDER_IMAGE_SOURCE_NONE}"},
    "border-image-slice": {"values": ["_number", "_percentage", "fill"], "initial": "&(lxb_css_property_border_image_slice_t) {.type = LXB_CSS_BORDER_IMAGE_SLICE__NUMBER, .fill = false, .values = {.num = 100, .is_float = false}}"},
    "border-image-width": {"values": ["_length", "_percentage", "_number", "auto"], "initial": "&(lxb_css_property_border_image_width_t) {.type = LXB_CSS_BORDER_IMAGE_WIDTH__NUMBER, .u = {.number = {.num = 1, .is_float = false}}}"},
    "border-image-outset": {"values": ["_length", "_number"], "initial": "&(lxb_css_property_border_image_outset_t) {.type = LXB_CSS_BORDER_IMAGE_OUTSET__NUMBER, .u = {.number = {.num = 0, .is_float = false}}}"},
    "border-image-repeat": {"values": ["stretch", "repeat", "round", "space"], "initial": "&(lxb_css_property_border_image_repeat_t) {.type = LXB_CSS_BORDER_IMAGE_REPEAT_STRETCH}"},
    "border-image": {"values": [], "initial": "&(lxb_css_property_border_image_t) {.source = {.type = LXB_CSS_BORDER_IMAGE_SOURCE_NONE}, .slice = {.type = LXB_CSS_BORDER_IMAGE_SLICE__NUMBER, .fill = false, .values = {.num = 100, .is_float = false}}, .width = {.type = LXB_CSS_BORDER_IMAGE_WIDTH__NUMBER, .u = {.number = {.num = 1, .is_float = false}}}, .outset = {.type = LXB_CSS_BORDER_IMAGE_OUTSET__NUMBER, .u = {.number = {.num = 0, .is_float = false}}}, .repeat = {.type = LXB_CSS_BORDER_IMAGE_REPEAT_STRETCH}}"},
    
    # Outline Properties
    "outline-style": {"values": ["none", "hidden", "dotted", "dashed", "solid", "double", "groove", "ridge", "inset", "outset"], "initial": "&(lxb_css_property_outline_style_t) {.type = LXB_CSS_OUTLINE_STYLE_NONE}"},
    "outline-width": {"values": ["thin", "medium", "thick", "_length"], "initial": "&(lxb_css_property_outline_width_t) {.type = LXB_CSS_OUTLINE_WIDTH_MEDIUM}"},
    "outline-color": {"values": color_values + ["invert"], "initial": "&(lxb_css_property_outline_color_t) {.type = LXB_CSS_COLOR_CURRENTCOLOR}"},
    "outline": {"values": [], "initial": "&(lxb_css_property_outline_t) {.style = {.type = LXB_CSS_OUTLINE_STYLE_NONE}, .width = {.type = LXB_CSS_OUTLINE_WIDTH_MEDIUM}, .color = {.type = LXB_CSS_COLOR_CURRENTCOLOR}}"},
    "outline-offset": {"values": ["_length"], "initial": "&(lxb_css_property_outline_offset_t) {.type = LXB_CSS_VALUE__LENGTH, .u = {.length = {.num = 0, .is_float = false, .unit = LXB_CSS_UNIT__UNDEF}}}"},
    
    # Box and Text Shadow
    "box-shadow": {"values": ["none", "inset"], "initial": "&(lxb_css_property_box_shadow_t) {.type = LXB_CSS_BOX_SHADOW_NONE}"},
    "text-shadow": {"values": ["none"], "initial": "&(lxb_css_property_text_shadow_t) {.type = LXB_CSS_TEXT_SHADOW_NONE}"},
    
    # Text Decoration Extensions
    "text-decoration-thickness": {"values": ["auto", "from-font", "_length", "_percentage"], "initial": "&(lxb_css_property_text_decoration_thickness_t) {.type = LXB_CSS_TEXT_DECORATION_THICKNESS_AUTO}"},
    
    # Text Emphasis
    "text-emphasis-style": {"values": ["none", "filled", "open", "dot", "circle", "double-circle", "triangle", "sesame"], "initial": "&(lxb_css_property_text_emphasis_style_t) {.type = LXB_CSS_TEXT_EMPHASIS_STYLE_NONE}"},
    "text-emphasis-color": {"values": color_values, "initial": "&(lxb_css_property_text_emphasis_color_t) {.type = LXB_CSS_COLOR_CURRENTCOLOR}"},
    "text-emphasis-position": {"values": ["over", "under", "right", "left"], "initial": "&(lxb_css_property_text_emphasis_position_t) {.vertical = LXB_CSS_TEXT_EMPHASIS_POSITION_OVER, .horizontal = LXB_CSS_TEXT_EMPHASIS_POSITION_RIGHT}"},
    "text-emphasis": {"values": [], "initial": "&(lxb_css_property_text_emphasis_t) {.style = {.type = LXB_CSS_TEXT_EMPHASIS_STYLE_NONE}, .color = {.type = LXB_CSS_COLOR_CURRENTCOLOR}}"},
    
    # Multi-column Layout
    "column-width": {"values": ["auto", "_length"], "initial": "&(lxb_css_property_column_width_t) {.type = LXB_CSS_COLUMN_WIDTH_AUTO}"},
    "column-count": {"values": ["auto", "_integer"], "initial": "&(lxb_css_property_column_count_t) {.type = LXB_CSS_COLUMN_COUNT_AUTO}"},
    "columns": {"values": [], "initial": "&(lxb_css_property_columns_t) {.width = {.type = LXB_CSS_COLUMN_WIDTH_AUTO}, .count = {.type = LXB_CSS_COLUMN_COUNT_AUTO}}"},
    "column-gap": {"values": ["normal", "_length", "_percentage"], "initial": "&(lxb_css_property_column_gap_t) {.type = LXB_CSS_COLUMN_GAP_NORMAL}"},
    "column-rule-style": {"values": ["none", "hidden", "dotted", "dashed", "solid", "double", "groove", "ridge", "inset", "outset"], "initial": "&(lxb_css_property_column_rule_style_t) {.type = LXB_CSS_COLUMN_RULE_STYLE_NONE}"},
    "column-rule-width": {"values": ["thin", "medium", "thick", "_length"], "initial": "&(lxb_css_property_column_rule_width_t) {.type = LXB_CSS_COLUMN_RULE_WIDTH_MEDIUM}"},
    "column-rule-color": {"values": color_values, "initial": "&(lxb_css_property_column_rule_color_t) {.type = LXB_CSS_COLOR_CURRENTCOLOR}"},
    "column-rule": {"values": [], "initial": "&(lxb_css_property_column_rule_t) {.width = {.type = LXB_CSS_COLUMN_RULE_WIDTH_MEDIUM}, .style = {.type = LXB_CSS_COLUMN_RULE_STYLE_NONE}, .color = {.type = LXB_CSS_COLOR_CURRENTCOLOR}}"},
    "column-span": {"values": ["none", "all"], "initial": "&(lxb_css_property_column_span_t) {.type = LXB_CSS_COLUMN_SPAN_NONE}"},
    "column-fill": {"values": ["auto", "balance", "balance-all"], "initial": "&(lxb_css_property_column_fill_t) {.type = LXB_CSS_COLUMN_FILL_BALANCE}"},
    
    # Transform Properties
    "transform": {"values": ["none"], "initial": "&(lxb_css_property_transform_t) {.type = LXB_CSS_TRANSFORM_NONE}"},
    "transform-origin": {"values": ["left", "center", "right", "top", "bottom", "_length", "_percentage"], "initial": "&(lxb_css_property_transform_origin_t) {.x = {.type = LXB_CSS_VALUE__PERCENTAGE, .u = {.percentage = 50}}, .y = {.type = LXB_CSS_VALUE__PERCENTAGE, .u = {.percentage = 50}}, .z = {.type = LXB_CSS_VALUE__LENGTH, .u = {.length = {.num = 0, .is_float = false, .unit = LXB_CSS_UNIT__UNDEF}}}}"},
    "transform-style": {"values": ["flat", "preserve-3d"], "initial": "&(lxb_css_property_transform_style_t) {.type = LXB_CSS_TRANSFORM_STYLE_FLAT}"},
    "perspective": {"values": ["none", "_length"], "initial": "&(lxb_css_property_perspective_t) {.type = LXB_CSS_PERSPECTIVE_NONE}"},
    "perspective-origin": {"values": ["left", "center", "right", "top", "bottom", "_length", "_percentage"], "initial": "&(lxb_css_property_perspective_origin_t) {.x = {.type = LXB_CSS_VALUE__PERCENTAGE, .u = {.percentage = 50}}, .y = {.type = LXB_CSS_VALUE__PERCENTAGE, .u = {.percentage = 50}}}"},
    "backface-visibility": {"values": ["visible", "hidden"], "initial": "&(lxb_css_property_backface_visibility_t) {.type = LXB_CSS_BACKFACE_VISIBILITY_VISIBLE}"},
    
    # Transitions
    "transition-property": {"values": ["none", "all"], "initial": "&(lxb_css_property_transition_property_t) {.type = LXB_CSS_TRANSITION_PROPERTY_ALL}"},
    "transition-duration": {"values": ["_time"], "initial": "&(lxb_css_property_transition_duration_t) {.type = LXB_CSS_VALUE__NUMBER, %s}" % time_0},
    "transition-timing-function": {"values": ["ease", "linear", "ease-in", "ease-out", "ease-in-out", "step-start", "step-end"], "initial": "&(lxb_css_property_transition_timing_function_t) {.type = LXB_CSS_TRANSITION_TIMING_FUNCTION_EASE}"},
    "transition-delay": {"values": ["_time"], "initial": "&(lxb_css_property_transition_delay_t) {.type = LXB_CSS_VALUE__NUMBER, %s}" % time_0},
    "transition": {"values": [], "initial": "&(lxb_css_property_transition_t) {.property = {.type = LXB_CSS_TRANSITION_PROPERTY_ALL}, .duration = {.type = LXB_CSS_VALUE__NUMBER, %s}, .timing_function = {.type = LXB_CSS_TRANSITION_TIMING_FUNCTION_EASE}, .delay = {.type = LXB_CSS_VALUE__NUMBER, %s}}" % (time_0, time_0)},
    
    # Animations
    # "animation-name": {"values": ["none"], "initial": "&(lxb_css_property_animation_name_t) {.type = LXB_CSS_ANIMATION_NAME_NONE}"},
    # "animation-duration": {"values": ["_time"], "initial": "&(lxb_css_property_animation_duration_t) {.type = LXB_CSS_VALUE__NUMBER, %s}" % time_0},
    # "animation-timing-function": {"values": ["ease", "linear", "ease-in", "ease-out", "ease-in-out", "step-start", "step-end"], "initial": "&(lxb_css_property_animation_timing_function_t) {.type = LXB_CSS_ANIMATION_TIMING_FUNCTION_EASE}"},
    # "animation-iteration-count": {"values": ["infinite", "_number"], "initial": "&(lxb_css_property_animation_iteration_count_t) {.type = LXB_CSS_ANIMATION_ITERATION_COUNT__NUMBER, .number = {.num = 1, .is_float = false}}"},
    # "animation-direction": {"values": ["normal", "reverse", "alternate", "alternate-reverse"], "initial": "&(lxb_css_property_animation_direction_t) {.type = LXB_CSS_ANIMATION_DIRECTION_NORMAL}"},
    # "animation-play-state": {"values": ["running", "paused"], "initial": "&(lxb_css_property_animation_play_state_t) {.type = LXB_CSS_ANIMATION_PLAY_STATE_RUNNING}"},
    # "animation-delay": {"values": ["_time"], "initial": "&(lxb_css_property_animation_delay_t) {.type = LXB_CSS_VALUE__NUMBER, %s}" % time_0},
    # "animation-fill-mode": {"values": ["none", "forwards", "backwards", "both"], "initial": "&(lxb_css_property_animation_fill_mode_t) {.type = LXB_CSS_ANIMATION_FILL_MODE_NONE}"},
    # "animation": {"values": [], "initial": "&(lxb_css_property_animation_t) {.name = {.type = LXB_CSS_ANIMATION_NAME_NONE}, .duration = {.type = LXB_CSS_VALUE__NUMBER, %s}, .timing_function = {.type = LXB_CSS_ANIMATION_TIMING_FUNCTION_EASE}, .iteration_count = {.type = LXB_CSS_ANIMATION_ITERATION_COUNT__NUMBER, .number = {.num = 1, .is_float = false}}, .direction = {.type = LXB_CSS_ANIMATION_DIRECTION_NORMAL}, .play_state = {.type = LXB_CSS_ANIMATION_PLAY_STATE_RUNNING}, .delay = {.type = LXB_CSS_VALUE__NUMBER, %s}, .fill_mode = {.type = LXB_CSS_ANIMATION_FILL_MODE_NONE}}" % (time_0, time_0)},
    
    # Lists
    "list-style-type": {"values": ["disc", "circle", "square", "decimal", "decimal-leading-zero", "lower-roman", "upper-roman", "lower-greek", "lower-latin", "upper-latin", "armenian", "georgian", "none"], "initial": "&(lxb_css_property_list_style_type_t) {.type = LXB_CSS_LIST_STYLE_TYPE_DISC}"},
    "list-style-position": {"values": ["inside", "outside"], "initial": "&(lxb_css_property_list_style_position_t) {.type = LXB_CSS_LIST_STYLE_POSITION_OUTSIDE}"},
    "list-style-image": {"values": ["none"], "initial": "&(lxb_css_property_list_style_image_t) {.type = LXB_CSS_LIST_STYLE_IMAGE_NONE}"},
    "list-style": {"values": [], "initial": "&(lxb_css_property_list_style_t) {.type = {.type = LXB_CSS_LIST_STYLE_TYPE_DISC}, .position = {.type = LXB_CSS_LIST_STYLE_POSITION_OUTSIDE}, .image = {.type = LXB_CSS_LIST_STYLE_IMAGE_NONE}}"},
    
    # Tables
    "border-collapse": {"values": ["collapse", "separate"], "initial": "&(lxb_css_property_border_collapse_t) {.type = LXB_CSS_BORDER_COLLAPSE_SEPARATE}"},
    "border-spacing": {"values": ["_length"], "initial": "&(lxb_css_property_border_spacing_t) {.horizontal = %s, .vertical = %s}" % (length_0, length_0)},
    "caption-side": {"values": ["top", "bottom"], "initial": "&(lxb_css_property_caption_side_t) {.type = LXB_CSS_CAPTION_SIDE_TOP}"},
    "empty-cells": {"values": ["show", "hide"], "initial": "&(lxb_css_property_empty_cells_t) {.type = LXB_CSS_EMPTY_CELLS_SHOW}"},
    "table-layout": {"values": ["auto", "fixed"], "initial": "&(lxb_css_property_table_layout_t) {.type = LXB_CSS_TABLE_LAYOUT_AUTO}"},
    
    # User Interface
    "resize": {"values": ["none", "both", "horizontal", "vertical", "block", "inline"], "initial": "&(lxb_css_property_resize_t) {.type = LXB_CSS_RESIZE_NONE}"},
    "caret-color": {"values": color_values + ["auto"], "initial": "&(lxb_css_property_caret_color_t) {.type = LXB_CSS_CARET_COLOR_AUTO}"},
    "nav-index": {"values": ["auto", "_integer"], "initial": "&(lxb_css_property_nav_index_t) {.type = LXB_CSS_NAV_INDEX_AUTO}"},
    "nav-up": {"values": ["auto"], "initial": "&(lxb_css_property_nav_up_t) {.type = LXB_CSS_NAV_UP_AUTO}"},
    "nav-right": {"values": ["auto"], "initial": "&(lxb_css_property_nav_right_t) {.type = LXB_CSS_NAV_RIGHT_AUTO}"},
    "nav-down": {"values": ["auto"], "initial": "&(lxb_css_property_nav_down_t) {.type = LXB_CSS_NAV_DOWN_AUTO}"},
    "nav-left": {"values": ["auto"], "initial": "&(lxb_css_property_nav_left_t) {.type = LXB_CSS_NAV_LEFT_AUTO}"},
    
    # Paged Media
    "page-break-before": {"values": ["auto", "always", "avoid", "left", "right"], "initial": "&(lxb_css_property_page_break_before_t) {.type = LXB_CSS_PAGE_BREAK_BEFORE_AUTO}"},
    "page-break-after": {"values": ["auto", "always", "avoid", "left", "right"], "initial": "&(lxb_css_property_page_break_after_t) {.type = LXB_CSS_PAGE_BREAK_AFTER_AUTO}"},
    "page-break-inside": {"values": ["auto", "avoid"], "initial": "&(lxb_css_property_page_break_inside_t) {.type = LXB_CSS_PAGE_BREAK_INSIDE_AUTO}"},
    "orphans": {"values": ["_integer"], "initial": "&(lxb_css_property_orphans_t) {.type = LXB_CSS_ORPHANS__INTEGER, .integer = {.num = 2}}"},
    "widows": {"values": ["_integer"], "initial": "&(lxb_css_property_widows_t) {.type = LXB_CSS_WIDOWS__INTEGER, .integer = {.num = 2}}"},
    "image-orientation": {"values": ["none", "from-image", "_angle"], "initial": "&(lxb_css_property_image_orientation_t) {.type = LXB_CSS_IMAGE_ORIENTATION_FROM_IMAGE}"},
    
    # Generated Content
    "content": {"values": ["normal", "none"], "initial": "&(lxb_css_property_content_t) {.type = LXB_CSS_CONTENT_NORMAL}"},
    "quotes": {"values": ["none"], "initial": "&(lxb_css_property_quotes_t) {.type = LXB_CSS_QUOTES_NONE}"},
    "counter-reset": {"values": ["none"], "initial": "&(lxb_css_property_counter_reset_t) {.type = LXB_CSS_COUNTER_RESET_NONE}"},
    "counter-increment": {"values": ["none"], "initial": "&(lxb_css_property_counter_increment_t) {.type = LXB_CSS_COUNTER_INCREMENT_NONE}"},
    "marker-offset": {"values": ["auto", "_length"], "initial": "&(lxb_css_property_marker_offset_t) {.type = LXB_CSS_MARKER_OFFSET_AUTO}"},
    
    # Miscellaneous
    "appearance": {"values": ["none", "auto"], "initial": "&(lxb_css_property_appearance_t) {.type = LXB_CSS_APPEARANCE_AUTO}"},
    "user-select": {"values": ["auto", "text", "none", "contain", "all"], "initial": "&(lxb_css_property_user_select_t) {.type = LXB_CSS_USER_SELECT_AUTO}"},
    "break-before": {"values": ["auto", "avoid", "avoid-page", "page", "left", "right", "recto", "verso", "avoid-column", "column", "avoid-region", "region"], "initial": "&(lxb_css_property_break_before_t) {.type = LXB_CSS_BREAK_BEFORE_AUTO}"},
    "break-after": {"values": ["auto", "avoid", "avoid-page", "page", "left", "right", "recto", "verso", "avoid-column", "column", "avoid-region", "region"], "initial": "&(lxb_css_property_break_after_t) {.type = LXB_CSS_BREAK_AFTER_AUTO}"},
    "break-inside": {"values": ["auto", "avoid", "avoid-page", "avoid-column", "avoid-region"], "initial": "&(lxb_css_property_break_inside_t) {.type = LXB_CSS_BREAK_INSIDE_AUTO}"},
    "isolation": {"values": ["auto", "isolate"], "initial": "&(lxb_css_property_isolation_t) {.type = LXB_CSS_ISOLATION_AUTO}"},
    "mix-blend-mode": {"values": ["normal", "multiply", "screen", "overlay", "darken", "lighten", "color-dodge", "color-burn", "hard-light", "soft-light", "difference", "exclusion", "hue", "saturation", "color", "luminosity"], "initial": "&(lxb_css_property_mix_blend_mode_t) {.type = LXB_CSS_MIX_BLEND_MODE_NORMAL}"},
    "object-fit": {"values": ["fill", "contain", "cover", "none", "scale-down"], "initial": "&(lxb_css_property_object_fit_t) {.type = LXB_CSS_OBJECT_FIT_FILL}"},
    "object-position": {"values": ["left", "center", "right", "top", "bottom", "_length", "_percentage"], "initial": "&(lxb_css_property_object_position_t) {.x = {.type = LXB_CSS_VALUE__PERCENTAGE, .u = {.percentage = 50}}, .y = {.type = LXB_CSS_VALUE__PERCENTAGE, .u = {.percentage = 50}}}"},
    "image-rendering": {"values": ["auto", "smooth", "high-quality", "crisp-edges", "pixelated"], "initial": "&(lxb_css_property_image_rendering_t) {.type = LXB_CSS_IMAGE_RENDERING_AUTO}"},
    "mask-type": {"values": ["luminance", "alpha"], "initial": "&(lxb_css_property_mask_type_t) {.type = LXB_CSS_MASK_TYPE_LUMINANCE}"},
    
    # Filter
    "filter": {"values": ["none"], "initial": "&(lxb_css_property_filter_t) {.type = LXB_CSS_FILTER_NONE}"},
    
    # Overflow
    "overflow-clip-margin": {"values": ["border-box", "padding-box", "content-box", "_length"], "initial": "&(lxb_css_property_overflow_clip_margin_t) {.type = LXB_CSS_OVERFLOW_CLIP_MARGIN_BORDER_BOX}"},
    
    # Pointer Events
    "pointer-events": {"values": ["auto", "none", "visiblePainted", "visibleFill", "visibleStroke", "visible", "painted", "fill", "stroke", "all"], "initial": "&(lxb_css_property_pointer_events_t) {.type = LXB_CSS_POINTER_EVENTS_AUTO}"},
    
    # Scrolling
    "scroll-behavior": {"values": ["auto", "smooth"], "initial": "&(lxb_css_property_scroll_behavior_t) {.type = LXB_CSS_SCROLL_BEHAVIOR_AUTO}"},
    "overscroll-behavior": {"values": ["contain", "none", "auto"], "initial": "&(lxb_css_property_overscroll_behavior_t) {.x = LXB_CSS_OVERSCROLL_BEHAVIOR_AUTO, .y = LXB_CSS_OVERSCROLL_BEHAVIOR_AUTO}"},
    "scroll-snap-type": {"values": ["none", "x", "y", "block", "inline", "both"], "initial": "&(lxb_css_property_scroll_snap_type_t) {.type = LXB_CSS_SCROLL_SNAP_TYPE_NONE}"},
    "scroll-snap-align": {"values": ["none", "start", "end", "center"], "initial": "&(lxb_css_property_scroll_snap_align_t) {.block = LXB_CSS_SCROLL_SNAP_ALIGN_NONE, .inline = LXB_CSS_SCROLL_SNAP_ALIGN_NONE}"},
    "scroll-margin": {"values": ["_length"], "initial": "&(lxb_css_property_scroll_margin_t) {.top = %s, .right = %s, .bottom = %s, .left = %s}" % (length_0, length_0, length_0, length_0)},
    "scroll-padding": {"values": ["auto", "_length", "_percentage"], "initial": "&(lxb_css_property_scroll_padding_t) {.top = %s, .right = %s, .bottom = %s, .left = %s}" % (length_percentage_auto, length_percentage_auto, length_percentage_auto, length_percentage_auto)},
    
    # Ruby Annotation
    "ruby-align": {"values": ["start", "center", "space-between", "space-around"], "initial": "&(lxb_css_property_ruby_align_t) {.type = LXB_CSS_RUBY_ALIGN_SPACE_AROUND}"},
    "ruby-position": {"values": ["over", "under", "inter-character"], "initial": "&(lxb_css_property_ruby_position_t) {.type = LXB_CSS_RUBY_POSITION_OVER}"},
}

for prop_name in list(additional_styles.keys()):
    # if not (prop_name in additional_styles):
    if not(prop_name == 'box-shadow'):
        del additional_styles[prop_name]

# Function to merge additional properties with any existing properties
def merge_with_existing_styles(existing_styles=None):
    if existing_styles is None:
        return additional_styles
    
    merged = existing_styles.copy()
    for prop, value in additional_styles.items():
        merged[prop] = value
    
    return merged

# If this script is run directly, print some info
if __name__ == "__main__":
    print("CSS additional properties defined:", len(additional_styles))
    print("To use these properties, import this module and call merge_with_existing_styles()")
