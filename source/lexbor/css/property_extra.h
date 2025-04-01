/*
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

/* Struct definitions */

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_background_image_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_background_size_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_background_repeat_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_background_attachment_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_background_origin_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_background_clip_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_background_position_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_border_radius_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_border_top_left_radius_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_border_top_right_radius_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_border_bottom_right_radius_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_border_bottom_left_radius_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_border_image_source_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_border_image_slice_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_border_image_width_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_border_image_outset_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_border_image_repeat_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_border_image_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_outline_style_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_outline_width_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_outline_color_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_outline_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_outline_offset_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_box_shadow_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_text_shadow_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_text_decoration_thickness_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_text_emphasis_style_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_text_emphasis_color_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_text_emphasis_position_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_text_emphasis_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_column_width_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_column_count_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_columns_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_column_gap_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_column_rule_style_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_column_rule_width_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_column_rule_color_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_column_rule_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_column_span_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_column_fill_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_transform_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_transform_origin_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_transform_style_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_perspective_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_perspective_origin_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_backface_visibility_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_transition_property_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_transition_duration_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_transition_timing_function_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_transition_delay_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_transition_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_name_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_duration_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_timing_function_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_iteration_count_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_direction_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_play_state_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_delay_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_fill_mode_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_animation_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_list_style_type_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_list_style_position_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_list_style_image_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_list_style_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_border_collapse_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_border_spacing_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_caption_side_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_empty_cells_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_table_layout_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_resize_t;

typedef struct {
    lxb_css_value_color_t color;
}
lxb_css_property_caret_color_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_nav_index_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_nav_up_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_nav_right_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_nav_down_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_nav_left_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_page_break_before_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_page_break_after_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_page_break_inside_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_orphans_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_widows_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_image_orientation_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_content_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_quotes_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_counter_reset_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_counter_increment_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_marker_offset_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_appearance_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_user_select_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_break_before_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_break_after_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_break_inside_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_isolation_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_mix_blend_mode_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_object_fit_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_object_position_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_image_rendering_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_mask_type_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_filter_t;

typedef struct {
    lxb_css_value_length_percentage_t top;
    lxb_css_value_length_percentage_t right;
    lxb_css_value_length_percentage_t bottom;
    lxb_css_value_length_percentage_t left;
}
lxb_css_property_overflow_clip_margin_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_pointer_events_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_scroll_behavior_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_overscroll_behavior_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_scroll_snap_type_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_scroll_snap_align_t;

typedef struct {
    lxb_css_value_length_percentage_t top;
    lxb_css_value_length_percentage_t right;
    lxb_css_value_length_percentage_t bottom;
    lxb_css_value_length_percentage_t left;
}
lxb_css_property_scroll_margin_t;

typedef struct {
    lxb_css_value_length_percentage_t value;
}
lxb_css_property_scroll_padding_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_ruby_align_t;

typedef struct {
    lxb_css_value_type_t type;
}
lxb_css_property_ruby_position_t;

/* Function prototypes */

LXB_API void *
lxb_css_property_background_image_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_image_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_image_serialize(const void *style,
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
lxb_css_property_background_position_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_background_position_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_background_position_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_radius_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_top_left_radius_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_top_left_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_top_left_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_top_right_radius_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_top_right_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_top_right_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_bottom_right_radius_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_bottom_right_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_bottom_right_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_bottom_left_radius_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_bottom_left_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_bottom_left_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_image_source_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_image_source_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_image_source_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_image_slice_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_image_slice_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_image_slice_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_image_width_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_image_width_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_image_width_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_image_outset_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_image_outset_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_image_outset_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_image_repeat_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_image_repeat_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_image_repeat_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_image_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_image_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_image_serialize(const void *style,
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
lxb_css_property_outline_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_outline_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_outline_serialize(const void *style,
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
lxb_css_property_text_emphasis_style_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_emphasis_style_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_emphasis_style_serialize(const void *style,
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
lxb_css_property_text_emphasis_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_text_emphasis_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_text_emphasis_serialize(const void *style,
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
lxb_css_property_columns_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_columns_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_columns_serialize(const void *style,
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
lxb_css_property_column_rule_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_column_rule_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_column_rule_serialize(const void *style,
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
lxb_css_property_transition_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_transition_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_transition_serialize(const void *style,
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
lxb_css_property_animation_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_animation_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_animation_serialize(const void *style,
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
lxb_css_property_list_style_image_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_list_style_image_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_list_style_image_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_list_style_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_list_style_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_list_style_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_collapse_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_collapse_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_collapse_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx);
LXB_API void *
lxb_css_property_border_spacing_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_border_spacing_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_border_spacing_serialize(const void *style,
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
lxb_css_property_image_orientation_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_image_orientation_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_image_orientation_serialize(const void *style,
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
lxb_css_property_object_position_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_object_position_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_object_position_serialize(const void *style,
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

#endif /* LEXBOR_CSS_PROPERTY_EXTRA_H */
