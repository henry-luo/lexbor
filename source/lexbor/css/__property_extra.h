/*
 * Copyright (C) 2023 Alexander Borisov
 *
 * Author: Alexander Borisov <borisov@lexbor.com>
 */

#ifndef LEXBOR_CSS_PROPERTY_GRAMMAR_H
#define LEXBOR_CSS_PROPERTY_GRAMMAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lexbor/core/str.h"
#include "lexbor/css/css.h"
#include "lexbor/css/value.h"


/* Struct definitions */

/* Struct definitions */

typedef struct {
    lxb_css_value_type_t type;
    // lxb_css_display_outside_type_t type;
}
lxb_css_property_display_outside_t;

typedef struct {
    lxb_css_value_type_t type;
    // lxb_css_display_inside_type_t type;
}
lxb_css_property_display_inside_t;

typedef struct {
    lxb_css_value_type_t type;
    // lxb_css_display_listitem_type_t type;
}
lxb_css_property_display_listitem_t;

typedef struct {
    lxb_css_value_type_t type;
    // lxb_css_display_internal_type_t type;
}
lxb_css_property_display_internal_t;

typedef struct {
    lxb_css_value_type_t type;
    // lxb_css_display_box_type_t type;
}
lxb_css_property_display_box_t;

typedef struct {
    lxb_css_value_type_t type;
    // lxb_css_display_legacy_type_t type;
}
lxb_css_property_display_legacy_t;

// typedef struct {
//     lxb_css_value_integer_t value;
// }
// lxb_css_property_order_t;

// typedef struct {
//     lxb_css_visibility_type_t type;
// }
// lxb_css_property_visibility_t;

// typedef struct {
//     lxb_css_width_type_t type;
// }
// lxb_css_property_width_t;

// typedef struct {
//     lxb_css_height_type_t type;
// }
// lxb_css_property_height_t;

// typedef struct {
//     lxb_css_min_width_type_t type;
// }
// lxb_css_property_min_width_t;

// typedef struct {
//     lxb_css_min_height_type_t type;
// }
// lxb_css_property_min_height_t;

// typedef struct {
//     lxb_css_max_width_type_t type;
// }
// lxb_css_property_max_width_t;

// typedef struct {
//     lxb_css_max_height_type_t type;
// }
// lxb_css_property_max_height_t;

// typedef struct {
//     lxb_css_value_type_t top;
//     lxb_css_value_type_t right;
//     lxb_css_value_type_t bottom;
//     lxb_css_value_type_t left;
// }
// lxb_css_property_margin_t;

// typedef struct {
//     lxb_css_margin_top_type_t type;
// }
// lxb_css_property_margin_top_t;

// typedef struct {
//     lxb_css_margin_right_type_t type;
// }
// lxb_css_property_margin_right_t;

// typedef struct {
//     lxb_css_margin_bottom_type_t type;
// }
// lxb_css_property_margin_bottom_t;

// typedef struct {
//     lxb_css_margin_left_type_t type;
// }
// lxb_css_property_margin_left_t;

// typedef struct {
//     lxb_css_value_type_t top;
//     lxb_css_value_type_t right;
//     lxb_css_value_type_t bottom;
//     lxb_css_value_type_t left;
// }
// lxb_css_property_padding_t;

// typedef struct {
//     lxb_css_padding_top_type_t type;
// }
// lxb_css_property_padding_top_t;

// typedef struct {
//     lxb_css_padding_right_type_t type;
// }
// lxb_css_property_padding_right_t;

// typedef struct {
//     lxb_css_padding_bottom_type_t type;
// }
// lxb_css_property_padding_bottom_t;

// typedef struct {
//     lxb_css_padding_left_type_t type;
// }
// lxb_css_property_padding_left_t;

// typedef struct {
//     lxb_css_value_color_t color;
// }
// lxb_css_property_background_color_t;

// typedef struct {
//     lxb_css_position_type_t type;
// }
// lxb_css_property_position_t;

// typedef struct {
//     lxb_css_top_type_t type;
// }
// lxb_css_property_top_t;

typedef struct {
    lxb_css_text_align_type_t type;
}
lxb_css_property_text_align_t;

typedef struct {
    lxb_css_text_align_all_type_t type;
}
lxb_css_property_text_align_all_t;

typedef struct {
    lxb_css_text_align_last_type_t type;
}
lxb_css_property_text_align_last_t;

typedef struct {
    lxb_css_text_justify_type_t type;
}
lxb_css_property_text_justify_t;

typedef struct {
    lxb_css_text_indent_type_t type;
}
lxb_css_property_text_indent_t;

typedef struct {
    lxb_css_white_space_type_t type;
}
lxb_css_property_white_space_t;

typedef struct {
    lxb_css_value_length_t value;
}
lxb_css_property_tab_size_t;

typedef struct {
    lxb_css_word_break_type_t type;
}
lxb_css_property_word_break_t;

typedef struct {
    lxb_css_line_break_type_t type;
}
lxb_css_property_line_break_t;

typedef struct {
    lxb_css_hyphens_type_t type;
}
lxb_css_property_hyphens_t;

typedef struct {
    lxb_css_overflow_wrap_type_t type;
}
lxb_css_property_overflow_wrap_t;

typedef struct {
    lxb_css_word_wrap_type_t type;
}
lxb_css_property_word_wrap_t;

typedef struct {
    lxb_css_word_spacing_type_t type;
}
lxb_css_property_word_spacing_t;

typedef struct {
    lxb_css_letter_spacing_type_t type;
}
lxb_css_property_letter_spacing_t;

typedef struct {
    lxb_css_value_type_t *values;
    size_t length;
}
lxb_css_property_font_family_t;

typedef struct {
    lxb_css_font_weight_type_t type;
}
lxb_css_property_font_weight_t;

typedef struct {
    lxb_css_font_stretch_type_t type;
}
lxb_css_property_font_stretch_t;

typedef struct {
    lxb_css_font_style_type_t type;
}
lxb_css_property_font_style_t;

typedef struct {
    lxb_css_font_size_type_t type;
}
lxb_css_property_font_size_t;

typedef struct {
    lxb_css_float_reference_type_t type;
}
lxb_css_property_float_reference_t;

typedef struct {
    lxb_css_float_type_t type;
}
lxb_css_property_float_t;

typedef struct {
    lxb_css_clear_type_t type;
}
lxb_css_property_clear_t;

typedef struct {
    lxb_css_float_defer_type_t type;
}
lxb_css_property_float_defer_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_float_offset_t;

typedef struct {
    lxb_css_wrap_flow_type_t type;
}
lxb_css_property_wrap_flow_t;

typedef struct {
    lxb_css_wrap_through_type_t type;
}
lxb_css_property_wrap_through_t;

typedef struct {
    lxb_css_flex_direction_type_t type;
}
lxb_css_property_flex_direction_t;

typedef struct {
    lxb_css_flex_wrap_type_t type;
}
lxb_css_property_flex_wrap_t;

typedef struct {
    lxb_css_flex_grow_type_t type;
}
lxb_css_property_flex_grow_t;

typedef struct {
    lxb_css_flex_shrink_type_t type;
}
lxb_css_property_flex_shrink_t;

typedef struct {
    lxb_css_flex_basis_type_t type;
}
lxb_css_property_flex_basis_t;

typedef struct {
    lxb_css_justify_content_type_t type;
}
lxb_css_property_justify_content_t;

typedef struct {
    lxb_css_align_items_type_t type;
}
lxb_css_property_align_items_t;

typedef struct {
    lxb_css_align_self_type_t type;
}
lxb_css_property_align_self_t;

typedef struct {
    lxb_css_align_content_type_t type;
}
lxb_css_property_align_content_t;

typedef struct {
    lxb_css_dominant_baseline_type_t type;
}
lxb_css_property_dominant_baseline_t;

typedef struct {
    lxb_css_alignment_baseline_type_t type;
}
lxb_css_property_alignment_baseline_t;

typedef struct {
    lxb_css_baseline_shift_type_t type;
}
lxb_css_property_baseline_shift_t;

typedef struct {
    lxb_css_baseline_source_type_t type;
}
lxb_css_property_baseline_source_t;

typedef struct {
    lxb_css_line_height_type_t type;
}
lxb_css_property_line_height_t;

typedef struct {
    lxb_css_z_index_type_t type;
}
lxb_css_property_z_index_t;

typedef struct {
    lxb_css_direction_type_t type;
}
lxb_css_property_direction_t;

typedef struct {
    lxb_css_unicode_bidi_type_t type;
}
lxb_css_property_unicode_bidi_t;

typedef struct {
    lxb_css_writing_mode_type_t type;
}
lxb_css_property_writing_mode_t;

typedef struct {
    lxb_css_text_orientation_type_t type;
}
lxb_css_property_text_orientation_t;

typedef struct {
    lxb_css_text_combine_upright_type_t type;
}
lxb_css_property_text_combine_upright_t;

typedef struct {
    lxb_css_overflow_x_type_t type;
}
lxb_css_property_overflow_x_t;

typedef struct {
    lxb_css_overflow_y_type_t type;
}
lxb_css_property_overflow_y_t;

typedef struct {
    lxb_css_overflow_block_type_t type;
}
lxb_css_property_overflow_block_t;

typedef struct {
    lxb_css_overflow_inline_type_t type;
}
lxb_css_property_overflow_inline_t;

typedef struct {
    lxb_css_text_overflow_type_t type;
}
lxb_css_property_text_overflow_t;

typedef struct {
    lxb_css_text_decoration_style_type_t type;
}
lxb_css_property_text_decoration_style_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_text_decoration_color_t;

typedef struct {
    lxb_css_background_size_type_t type;
}
lxb_css_property_background_size_t;

typedef struct {
    lxb_css_background_repeat_type_t type;
}
lxb_css_property_background_repeat_t;

typedef struct {
    lxb_css_background_attachment_type_t type;
}
lxb_css_property_background_attachment_t;

typedef struct {
    lxb_css_background_origin_type_t type;
}
lxb_css_property_background_origin_t;

typedef struct {
    lxb_css_background_clip_type_t type;
}
lxb_css_property_background_clip_t;

typedef struct {
    lxb_css_outline_style_type_t type;
}
lxb_css_property_outline_style_t;

typedef struct {
    lxb_css_outline_width_type_t type;
}
lxb_css_property_outline_width_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_outline_color_t;

typedef struct {
    lxb_css_value_length_t value;
}
lxb_css_property_outline_offset_t;

typedef struct {
    lxb_css_value_color_t *values;
    size_t length;
}
lxb_css_property_box_shadow_t;

typedef struct {
    lxb_css_value_color_t *values;
    size_t length;
}
lxb_css_property_text_shadow_t;

typedef struct {
    lxb_css_text_decoration_thickness_type_t type;
}
lxb_css_property_text_decoration_thickness_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_text_emphasis_color_t;

typedef struct {
    lxb_css_text_emphasis_position_type_t type;
}
lxb_css_property_text_emphasis_position_t;

typedef struct {
    lxb_css_column_width_type_t type;
}
lxb_css_property_column_width_t;

typedef struct {
    lxb_css_column_count_type_t type;
}
lxb_css_property_column_count_t;

typedef struct {
    lxb_css_column_gap_type_t type;
}
lxb_css_property_column_gap_t;

typedef struct {
    lxb_css_column_rule_style_type_t type;
}
lxb_css_property_column_rule_style_t;

typedef struct {
    lxb_css_column_rule_width_type_t type;
}
lxb_css_property_column_rule_width_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_column_rule_color_t;

typedef struct {
    lxb_css_column_span_type_t type;
}
lxb_css_property_column_span_t;

typedef struct {
    lxb_css_column_fill_type_t type;
}
lxb_css_property_column_fill_t;

typedef struct {
    lxb_css_value_type_t *values;
    size_t length;
}
lxb_css_property_transform_t;

typedef struct {
    lxb_css_transform_origin_type_t type;
}
lxb_css_property_transform_origin_t;

typedef struct {
    lxb_css_transform_style_type_t type;
}
lxb_css_property_transform_style_t;

typedef struct {
    lxb_css_value_length_t value;
}
lxb_css_property_perspective_t;

typedef struct {
    lxb_css_perspective_origin_type_t type;
}
lxb_css_property_perspective_origin_t;

typedef struct {
    lxb_css_backface_visibility_type_t type;
}
lxb_css_property_backface_visibility_t;

typedef struct {
    lxb_css_value_type_t *values;
    size_t length;
}
lxb_css_property_transition_property_t;

typedef struct {
    lxb_css_value_time_t *values;
    size_t length;
}
lxb_css_property_transition_duration_t;

typedef struct {
    lxb_css_value_transition_t *transitions;
    size_t length;
}
lxb_css_property_transition_timing_function_t;

typedef struct {
    lxb_css_value_time_t *values;
    size_t length;
}
lxb_css_property_transition_delay_t;

typedef struct {
    lxb_css_value_type_t *values;
    size_t length;
}
lxb_css_property_animation_name_t;

typedef struct {
    lxb_css_value_time_t *values;
    size_t length;
}
lxb_css_property_animation_duration_t;

typedef struct {
    lxb_css_value_type_t *values;
    size_t length;
}
lxb_css_property_animation_timing_function_t;

typedef struct {
    lxb_css_value_number_t *values;
    size_t length;
}
lxb_css_property_animation_iteration_count_t;

typedef struct {
    lxb_css_value_animation_t *animations;
    size_t length;
}
lxb_css_property_animation_direction_t;

typedef struct {
    lxb_css_value_animation_t *animations;
    size_t length;
}
lxb_css_property_animation_play_state_t;

typedef struct {
    lxb_css_value_time_t *values;
    size_t length;
}
lxb_css_property_animation_delay_t;

typedef struct {
    lxb_css_value_animation_t *animations;
    size_t length;
}
lxb_css_property_animation_fill_mode_t;

typedef struct {
    lxb_css_list_style_type_type_t type;
}
lxb_css_property_list_style_type_t;

typedef struct {
    lxb_css_list_style_position_type_t type;
}
lxb_css_property_list_style_position_t;

typedef struct {
    lxb_css_caption_side_type_t type;
}
lxb_css_property_caption_side_t;

typedef struct {
    lxb_css_empty_cells_type_t type;
}
lxb_css_property_empty_cells_t;

typedef struct {
    lxb_css_table_layout_type_t type;
}
lxb_css_property_table_layout_t;

typedef struct {
    lxb_css_resize_type_t type;
}
lxb_css_property_resize_t;

typedef struct {
    lxb_css_cursor_type_t type;
}
lxb_css_property_cursor_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_caret_color_t;

typedef struct {
    lxb_css_nav_index_type_t type;
}
lxb_css_property_nav_index_t;

typedef struct {
    lxb_css_nav_up_type_t type;
}
lxb_css_property_nav_up_t;

typedef struct {
    lxb_css_nav_right_type_t type;
}
lxb_css_property_nav_right_t;

typedef struct {
    lxb_css_nav_down_type_t type;
}
lxb_css_property_nav_down_t;

typedef struct {
    lxb_css_nav_left_type_t type;
}
lxb_css_property_nav_left_t;

typedef struct {
    lxb_css_page_break_before_type_t type;
}
lxb_css_property_page_break_before_t;

typedef struct {
    lxb_css_page_break_after_type_t type;
}
lxb_css_property_page_break_after_t;

typedef struct {
    lxb_css_page_break_inside_type_t type;
}
lxb_css_property_page_break_inside_t;

typedef struct {
    lxb_css_value_integer_t value;
}
lxb_css_property_orphans_t;

typedef struct {
    lxb_css_value_integer_t value;
}
lxb_css_property_widows_t;

typedef struct {
    lxb_css_value_string_t *values;
    size_t length;
}
lxb_css_property_content_t;

typedef struct {
    lxb_css_value_string_t *values;
    size_t length;
}
lxb_css_property_quotes_t;

typedef struct {
    lxb_css_value_integer_t *values;
    size_t length;
}
lxb_css_property_counter_reset_t;

typedef struct {
    lxb_css_value_integer_t *values;
    size_t length;
}
lxb_css_property_counter_increment_t;

typedef struct {
    lxb_css_marker_offset_type_t type;
}
lxb_css_property_marker_offset_t;

typedef struct {
    lxb_css_appearance_type_t type;
}
lxb_css_property_appearance_t;

typedef struct {
    lxb_css_user_select_type_t type;
}
lxb_css_property_user_select_t;

typedef struct {
    lxb_css_break_before_type_t type;
}
lxb_css_property_break_before_t;

typedef struct {
    lxb_css_break_after_type_t type;
}
lxb_css_property_break_after_t;

typedef struct {
    lxb_css_break_inside_type_t type;
}
lxb_css_property_break_inside_t;

typedef struct {
    lxb_css_isolation_type_t type;
}
lxb_css_property_isolation_t;

typedef struct {
    lxb_css_mix_blend_mode_type_t type;
}
lxb_css_property_mix_blend_mode_t;

typedef struct {
    lxb_css_object_fit_type_t type;
}
lxb_css_property_object_fit_t;

typedef struct {
    lxb_css_image_rendering_type_t type;
}
lxb_css_property_image_rendering_t;

typedef struct {
    lxb_css_mask_type_type_t type;
}
lxb_css_property_mask_type_t;

typedef struct {
    lxb_css_filter_type_t type;
}
lxb_css_property_filter_t;

typedef struct {
    lxb_css_overflow_clip_margin_type_t type;
}
lxb_css_property_overflow_clip_margin_t;

typedef struct {
    lxb_css_pointer_events_type_t type;
}
lxb_css_property_pointer_events_t;

typedef struct {
    lxb_css_scroll_behavior_type_t type;
}
lxb_css_property_scroll_behavior_t;

typedef struct {
    lxb_css_overscroll_behavior_type_t type;
}
lxb_css_property_overscroll_behavior_t;

typedef struct {
    lxb_css_scroll_snap_type_type_t type;
}
lxb_css_property_scroll_snap_type_t;

typedef struct {
    lxb_css_scroll_snap_align_type_t type;
}
lxb_css_property_scroll_snap_align_t;

typedef struct {
    lxb_css_value_length_t value;
}
lxb_css_property_scroll_margin_t;

typedef struct {
    lxb_css_scroll_padding_type_t type;
}
lxb_css_property_scroll_padding_t;

typedef struct {
    lxb_css_ruby_align_type_t type;
}
lxb_css_property_ruby_align_t;

typedef struct {
    lxb_css_ruby_position_type_t type;
}
lxb_css_property_ruby_position_t;

/* Function prototypes */

LXB_API void *
lxb_css_property_display_outside_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_display_outside_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_display_outside_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_display_inside_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_display_inside_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_display_inside_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_display_listitem_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_display_listitem_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_display_listitem_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_display_internal_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_display_internal_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_display_internal_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_display_box_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_display_box_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_display_box_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_display_legacy_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_display_legacy_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_display_legacy_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_order_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_order_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_order_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_visibility_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_visibility_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_visibility_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_width_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_width_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_width_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_height_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_height_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_height_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_min_width_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_min_width_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_min_width_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_min_height_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_min_height_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_min_height_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_max_width_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_max_width_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_max_width_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_max_height_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_max_height_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_max_height_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_margin_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_margin_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_margin_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_margin_top_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_margin_top_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_margin_top_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_margin_right_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_margin_right_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_margin_right_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_margin_bottom_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_margin_bottom_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_margin_bottom_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_margin_left_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_margin_left_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_margin_left_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_padding_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_padding_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_padding_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_padding_top_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_padding_top_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_padding_top_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_padding_right_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_padding_right_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_padding_right_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_padding_bottom_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_padding_bottom_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_padding_bottom_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_padding_left_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_padding_left_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_padding_left_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_background_color_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_color_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_color_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_position_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_position_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_position_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_top_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_top_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_top_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_align_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_align_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_align_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_align_all_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_align_all_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_align_all_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_align_last_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_align_last_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_align_last_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_justify_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_justify_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_justify_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_indent_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_indent_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_indent_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_white_space_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_white_space_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_white_space_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_tab_size_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_tab_size_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_tab_size_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_word_break_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_word_break_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_word_break_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_line_break_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_line_break_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_line_break_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_hyphens_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_hyphens_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_hyphens_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_overflow_wrap_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_overflow_wrap_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_overflow_wrap_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_word_wrap_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_word_wrap_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_word_wrap_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_word_spacing_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_word_spacing_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_word_spacing_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_letter_spacing_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_letter_spacing_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_letter_spacing_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_font_family_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_font_family_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_font_family_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_font_weight_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_font_weight_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_font_weight_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_font_stretch_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_font_stretch_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_font_stretch_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_font_style_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_font_style_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_font_style_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_font_size_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_font_size_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_font_size_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_float_reference_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_float_reference_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_float_reference_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_float_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_float_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_float_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_clear_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_clear_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_clear_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_float_defer_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_float_defer_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_float_defer_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_float_offset_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_float_offset_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_float_offset_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_wrap_flow_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_wrap_flow_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_wrap_flow_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_wrap_through_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_wrap_through_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_wrap_through_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_flex_direction_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_flex_direction_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_flex_direction_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_flex_wrap_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_flex_wrap_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_flex_wrap_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_flex_grow_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_flex_grow_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_flex_grow_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_flex_shrink_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_flex_shrink_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_flex_shrink_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_flex_basis_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_flex_basis_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_flex_basis_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_justify_content_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_justify_content_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_justify_content_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_align_items_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_align_items_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_align_items_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_align_self_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_align_self_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_align_self_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_align_content_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_align_content_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_align_content_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_dominant_baseline_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_dominant_baseline_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_dominant_baseline_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_alignment_baseline_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_alignment_baseline_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_alignment_baseline_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_baseline_shift_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_baseline_shift_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_baseline_shift_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_baseline_source_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_baseline_source_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_baseline_source_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_line_height_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_line_height_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_line_height_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_z_index_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_z_index_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_z_index_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_direction_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_direction_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_direction_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_unicode_bidi_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_unicode_bidi_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_unicode_bidi_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_writing_mode_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_writing_mode_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_writing_mode_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_orientation_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_orientation_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_orientation_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_combine_upright_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_combine_upright_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_combine_upright_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_overflow_x_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_overflow_x_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_overflow_x_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_overflow_y_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_overflow_y_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_overflow_y_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_overflow_block_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_overflow_block_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_overflow_block_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_overflow_inline_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_overflow_inline_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_overflow_inline_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_overflow_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_overflow_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_overflow_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_decoration_style_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_decoration_style_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_decoration_style_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_decoration_color_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_decoration_color_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_decoration_color_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_background_size_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_size_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_size_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_background_repeat_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_repeat_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_repeat_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_background_attachment_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_attachment_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_attachment_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_background_origin_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_origin_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_origin_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_background_clip_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_clip_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_clip_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_outline_style_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_outline_style_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_outline_style_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_outline_width_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_outline_width_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_outline_width_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_outline_color_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_outline_color_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_outline_color_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_outline_offset_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_outline_offset_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_outline_offset_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_box_shadow_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_box_shadow_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_box_shadow_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_shadow_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_shadow_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_shadow_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_decoration_thickness_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_decoration_thickness_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_decoration_thickness_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_emphasis_color_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_emphasis_color_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_emphasis_color_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_text_emphasis_position_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_emphasis_position_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_emphasis_position_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_width_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_width_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_width_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_count_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_count_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_count_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_gap_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_gap_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_gap_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_rule_style_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_rule_style_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_rule_style_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_rule_width_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_rule_width_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_rule_width_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_rule_color_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_rule_color_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_rule_color_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_span_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_span_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_span_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_column_fill_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_fill_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_fill_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_transform_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transform_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transform_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_transform_origin_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transform_origin_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transform_origin_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_transform_style_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transform_style_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transform_style_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_perspective_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_perspective_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_perspective_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_perspective_origin_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_perspective_origin_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_perspective_origin_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_backface_visibility_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_backface_visibility_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_backface_visibility_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_transition_property_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transition_property_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transition_property_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_transition_duration_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transition_duration_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transition_duration_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_transition_timing_function_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transition_timing_function_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transition_timing_function_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_transition_delay_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transition_delay_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transition_delay_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_name_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_name_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_name_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_duration_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_duration_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_duration_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_timing_function_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_timing_function_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_timing_function_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_iteration_count_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_iteration_count_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_iteration_count_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_direction_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_direction_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_direction_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_play_state_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_play_state_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_play_state_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_delay_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_delay_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_delay_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_animation_fill_mode_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_fill_mode_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_fill_mode_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_list_style_type_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_list_style_type_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_list_style_type_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_list_style_position_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_list_style_position_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_list_style_position_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_caption_side_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_caption_side_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_caption_side_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_empty_cells_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_empty_cells_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_empty_cells_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_table_layout_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_table_layout_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_table_layout_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_resize_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_resize_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_resize_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_cursor_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_cursor_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_cursor_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_caret_color_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_caret_color_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_caret_color_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_nav_index_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_nav_index_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_nav_index_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_nav_up_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_nav_up_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_nav_up_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_nav_right_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_nav_right_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_nav_right_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_nav_down_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_nav_down_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_nav_down_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_nav_left_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_nav_left_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_nav_left_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_page_break_before_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_page_break_before_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_page_break_before_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_page_break_after_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_page_break_after_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_page_break_after_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_page_break_inside_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_page_break_inside_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_page_break_inside_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_orphans_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_orphans_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_orphans_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_widows_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_widows_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_widows_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_content_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_content_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_content_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_quotes_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_quotes_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_quotes_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_counter_reset_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_counter_reset_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_counter_reset_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_counter_increment_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_counter_increment_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_counter_increment_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_marker_offset_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_marker_offset_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_marker_offset_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_appearance_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_appearance_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_appearance_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_user_select_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_user_select_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_user_select_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_break_before_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_break_before_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_break_before_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_break_after_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_break_after_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_break_after_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_break_inside_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_break_inside_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_break_inside_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_isolation_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_isolation_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_isolation_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_mix_blend_mode_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_mix_blend_mode_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_mix_blend_mode_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_object_fit_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_object_fit_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_object_fit_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_image_rendering_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_image_rendering_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_image_rendering_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_mask_type_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_mask_type_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_mask_type_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_filter_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_filter_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_filter_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_overflow_clip_margin_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_overflow_clip_margin_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_overflow_clip_margin_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_pointer_events_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_pointer_events_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_pointer_events_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_scroll_behavior_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_scroll_behavior_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_scroll_behavior_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_overscroll_behavior_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_overscroll_behavior_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_overscroll_behavior_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_scroll_snap_type_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_scroll_snap_type_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_scroll_snap_type_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_scroll_snap_align_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_scroll_snap_align_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_scroll_snap_align_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_scroll_margin_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_scroll_margin_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_scroll_margin_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_scroll_padding_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_scroll_padding_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_scroll_padding_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_ruby_align_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_ruby_align_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_ruby_align_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_ruby_position_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_ruby_position_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_ruby_position_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LEXBOR_CSS_PROPERTY_GRAMMAR_H */
