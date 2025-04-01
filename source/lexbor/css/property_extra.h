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

/* Enumeration definitions */

typedef enum {
    LXB_CSS_APPEARANCE_AUTO,
    LXB_CSS_APPEARANCE_BUTTON,
    LXB_CSS_APPEARANCE_COMPAT_,
    LXB_CSS_APPEARANCE_TEXTFIELD,
    LXB_CSS_APPEARANCE__LAST_ENTRY
}
lxb_css_appearance_type_t;

typedef enum {
    LXB_CSS_BACKFACE_VISIBILITY_HIDDEN,
    LXB_CSS_BACKFACE_VISIBILITY_VISIBLE,
    LXB_CSS_BACKFACE_VISIBILITY__LAST_ENTRY
}
lxb_css_backface_visibility_type_t;

typedef enum {
    LXB_CSS_BACKGROUND_ATTACHMENT_FIXED,
    LXB_CSS_BACKGROUND_ATTACHMENT_LOCAL,
    LXB_CSS_BACKGROUND_ATTACHMENT_SCROLL,
    LXB_CSS_BACKGROUND_ATTACHMENT__LAST_ENTRY
}
lxb_css_background_attachment_type_t;

typedef enum {
    LXB_CSS_BACKGROUND_CLIP_BORDER_BOX,
    LXB_CSS_BACKGROUND_CLIP_CONTENT_BOX,
    LXB_CSS_BACKGROUND_CLIP_PADDING_BOX,
    LXB_CSS_BACKGROUND_CLIP_TEXT,
    LXB_CSS_BACKGROUND_CLIP__LAST_ENTRY
}
lxb_css_background_clip_type_t;

typedef enum {
    LXB_CSS_BACKGROUND_ORIGIN_BORDER_BOX,
    LXB_CSS_BACKGROUND_ORIGIN_CONTENT_BOX,
    LXB_CSS_BACKGROUND_ORIGIN_PADDING_BOX,
    LXB_CSS_BACKGROUND_ORIGIN__LAST_ENTRY
}
lxb_css_background_origin_type_t;

typedef enum {
    LXB_CSS_BACKGROUND_POSITION_CENTER,
    LXB_CSS_BACKGROUND_POSITION_CENTER_BOTTOM,
    LXB_CSS_BACKGROUND_POSITION_CENTER_TOP,
    LXB_CSS_BACKGROUND_POSITION_LEFT_BOTTOM,
    LXB_CSS_BACKGROUND_POSITION_LEFT_CENTER,
    LXB_CSS_BACKGROUND_POSITION_LEFT_TOP,
    LXB_CSS_BACKGROUND_POSITION_RIGHT_BOTTOM,
    LXB_CSS_BACKGROUND_POSITION_RIGHT_CENTER,
    LXB_CSS_BACKGROUND_POSITION_RIGHT_TOP,
    LXB_CSS_BACKGROUND_POSITION__LAST_ENTRY
}
lxb_css_background_position_type_t;

typedef enum {
    LXB_CSS_BACKGROUND_REPEAT_NO_REPEAT,
    LXB_CSS_BACKGROUND_REPEAT_REPEAT,
    LXB_CSS_BACKGROUND_REPEAT_REPEAT_X,
    LXB_CSS_BACKGROUND_REPEAT_REPEAT_Y,
    LXB_CSS_BACKGROUND_REPEAT_ROUND,
    LXB_CSS_BACKGROUND_REPEAT_SPACE,
    LXB_CSS_BACKGROUND_REPEAT__LAST_ENTRY
}
lxb_css_background_repeat_type_t;

typedef enum {
    LXB_CSS_BACKGROUND_SIZE_AUTO,
    LXB_CSS_BACKGROUND_SIZE_CONTAIN,
    LXB_CSS_BACKGROUND_SIZE_COVER,
    LXB_CSS_BACKGROUND_SIZE_LENGTH_,
    LXB_CSS_BACKGROUND_SIZE__LAST_ENTRY
}
lxb_css_background_size_type_t;

typedef enum {
    LXB_CSS_BOX_SHADOW_INSET,
    LXB_CSS_BOX_SHADOW__LAST_ENTRY
}
lxb_css_box_shadow_type_t;

typedef enum {
    LXB_CSS_BREAK_AFTER_AUTO,
    LXB_CSS_BREAK_AFTER_AVOID,
    LXB_CSS_BREAK_AFTER_AVOID_COLUMN,
    LXB_CSS_BREAK_AFTER_AVOID_PAGE,
    LXB_CSS_BREAK_AFTER_AVOID_REGION,
    LXB_CSS_BREAK_AFTER_COLUMN,
    LXB_CSS_BREAK_AFTER_LEFT,
    LXB_CSS_BREAK_AFTER_PAGE,
    LXB_CSS_BREAK_AFTER_RECTO,
    LXB_CSS_BREAK_AFTER_REGION,
    LXB_CSS_BREAK_AFTER_RIGHT,
    LXB_CSS_BREAK_AFTER_VERSO,
    LXB_CSS_BREAK_AFTER__LAST_ENTRY
}
lxb_css_break_after_type_t;

typedef enum {
    LXB_CSS_BREAK_BEFORE_AUTO,
    LXB_CSS_BREAK_BEFORE_AVOID,
    LXB_CSS_BREAK_BEFORE_AVOID_COLUMN,
    LXB_CSS_BREAK_BEFORE_AVOID_PAGE,
    LXB_CSS_BREAK_BEFORE_AVOID_REGION,
    LXB_CSS_BREAK_BEFORE_COLUMN,
    LXB_CSS_BREAK_BEFORE_LEFT,
    LXB_CSS_BREAK_BEFORE_PAGE,
    LXB_CSS_BREAK_BEFORE_RECTO,
    LXB_CSS_BREAK_BEFORE_REGION,
    LXB_CSS_BREAK_BEFORE_RIGHT,
    LXB_CSS_BREAK_BEFORE_VERSO,
    LXB_CSS_BREAK_BEFORE__LAST_ENTRY
}
lxb_css_break_before_type_t;

typedef enum {
    LXB_CSS_BREAK_INSIDE_AUTO,
    LXB_CSS_BREAK_INSIDE_AVOID,
    LXB_CSS_BREAK_INSIDE_AVOID_COLUMN,
    LXB_CSS_BREAK_INSIDE_AVOID_PAGE,
    LXB_CSS_BREAK_INSIDE_AVOID_REGION,
    LXB_CSS_BREAK_INSIDE__LAST_ENTRY
}
lxb_css_break_inside_type_t;

typedef enum {
    LXB_CSS_CAPTION_SIDE_BOTTOM,
    LXB_CSS_CAPTION_SIDE_TOP,
    LXB_CSS_CAPTION_SIDE__LAST_ENTRY
}
lxb_css_caption_side_type_t;

typedef enum {
    LXB_CSS_CARET_COLOR_AUTO,
    LXB_CSS_CARET_COLOR__LAST_ENTRY
}
lxb_css_caret_color_type_t;

typedef enum {
    LXB_CSS_COLUMN_COUNT_AUTO,
    LXB_CSS_COLUMN_COUNT_INTEGER,
    LXB_CSS_COLUMN_COUNT__LAST_ENTRY
}
lxb_css_column_count_type_t;

typedef enum {
    LXB_CSS_COLUMN_FILL_AUTO,
    LXB_CSS_COLUMN_FILL_BALANCE,
    LXB_CSS_COLUMN_FILL_BALANCE_ALL,
    LXB_CSS_COLUMN_FILL__LAST_ENTRY
}
lxb_css_column_fill_type_t;

typedef enum {
    LXB_CSS_COLUMN_GAP_LENGTH_,
    LXB_CSS_COLUMN_GAP_NORMAL,
    LXB_CSS_COLUMN_GAP__LAST_ENTRY
}
lxb_css_column_gap_type_t;

typedef enum {
    LXB_CSS_COLUMN_RULE_STYLE_BORDER_,
    LXB_CSS_COLUMN_RULE_STYLE__LAST_ENTRY
}
lxb_css_column_rule_style_type_t;

typedef enum {
    LXB_CSS_COLUMN_RULE_WIDTH_BORDER_,
    LXB_CSS_COLUMN_RULE_WIDTH__LAST_ENTRY
}
lxb_css_column_rule_width_type_t;

typedef enum {
    LXB_CSS_COLUMN_SPAN_ALL,
    LXB_CSS_COLUMN_SPAN__LAST_ENTRY
}
lxb_css_column_span_type_t;

typedef enum {
    LXB_CSS_COLUMN_WIDTH_AUTO,
    LXB_CSS_COLUMN_WIDTH_LENGTH,
    LXB_CSS_COLUMN_WIDTH__LAST_ENTRY
}
lxb_css_column_width_type_t;

typedef enum {
    LXB_CSS_CONTENT_ATTR,
    LXB_CSS_CONTENT_CLOSE_QUOTE,
    LXB_CSS_CONTENT_NORMAL,
    LXB_CSS_CONTENT_NO_CLOSE_QUOTE,
    LXB_CSS_CONTENT_NO_OPEN_QUOTE,
    LXB_CSS_CONTENT_OPEN_QUOTE,
    LXB_CSS_CONTENT__LAST_ENTRY
}
lxb_css_content_type_t;

typedef enum {
    LXB_CSS_COUNTER_INCREMENT_CUSTOM_,
    LXB_CSS_COUNTER_INCREMENT__LAST_ENTRY
}
lxb_css_counter_increment_type_t;

typedef enum {
    LXB_CSS_COUNTER_RESET_CUSTOM_,
    LXB_CSS_COUNTER_RESET__LAST_ENTRY
}
lxb_css_counter_reset_type_t;

typedef enum {
    LXB_CSS_EMPTY_CELLS_HIDE,
    LXB_CSS_EMPTY_CELLS_SHOW,
    LXB_CSS_EMPTY_CELLS__LAST_ENTRY
}
lxb_css_empty_cells_type_t;

typedef enum {
    LXB_CSS_FILTER_FILTER_FUNCTION_,
    LXB_CSS_FILTER__LAST_ENTRY
}
lxb_css_filter_type_t;

typedef enum {
    LXB_CSS_IMAGE_RENDERING_AUTO,
    LXB_CSS_IMAGE_RENDERING_CRISP_EDGES,
    LXB_CSS_IMAGE_RENDERING_HIGH_QUALITY,
    LXB_CSS_IMAGE_RENDERING_PIXELATED,
    LXB_CSS_IMAGE_RENDERING_SMOOTH,
    LXB_CSS_IMAGE_RENDERING__LAST_ENTRY
}
lxb_css_image_rendering_type_t;

typedef enum {
    LXB_CSS_ISOLATION_AUTO,
    LXB_CSS_ISOLATION_ISOLATE,
    LXB_CSS_ISOLATION__LAST_ENTRY
}
lxb_css_isolation_type_t;

typedef enum {
    LXB_CSS_LIST_STYLE_POSITION_INSIDE,
    LXB_CSS_LIST_STYLE_POSITION_OUTSIDE,
    LXB_CSS_LIST_STYLE_POSITION__LAST_ENTRY
}
lxb_css_list_style_position_type_t;

typedef enum {
    LXB_CSS_LIST_STYLE_TYPE_ARMENIAN,
    LXB_CSS_LIST_STYLE_TYPE_CIRCLE,
    LXB_CSS_LIST_STYLE_TYPE_DECIMAL,
    LXB_CSS_LIST_STYLE_TYPE_DECIMAL_LEADING_ZERO,
    LXB_CSS_LIST_STYLE_TYPE_DISC,
    LXB_CSS_LIST_STYLE_TYPE_GEORGIAN,
    LXB_CSS_LIST_STYLE_TYPE_LOWER_GREEK,
    LXB_CSS_LIST_STYLE_TYPE_LOWER_LATIN,
    LXB_CSS_LIST_STYLE_TYPE_LOWER_ROMAN,
    LXB_CSS_LIST_STYLE_TYPE_SQUARE,
    LXB_CSS_LIST_STYLE_TYPE_UPPER_LATIN,
    LXB_CSS_LIST_STYLE_TYPE_UPPER_ROMAN,
    LXB_CSS_LIST_STYLE_TYPE__LAST_ENTRY
}
lxb_css_list_style_type_type_t;

typedef enum {
    LXB_CSS_MARKER_OFFSET_AUTO,
    LXB_CSS_MARKER_OFFSET__LAST_ENTRY
}
lxb_css_marker_offset_type_t;

typedef enum {
    LXB_CSS_MASK_TYPE_ALPHA,
    LXB_CSS_MASK_TYPE_LUMINANCE,
    LXB_CSS_MASK_TYPE__LAST_ENTRY
}
lxb_css_mask_type_type_t;

typedef enum {
    LXB_CSS_MIX_BLEND_MODE_COLOR,
    LXB_CSS_MIX_BLEND_MODE_COLOR_BURN,
    LXB_CSS_MIX_BLEND_MODE_COLOR_DODGE,
    LXB_CSS_MIX_BLEND_MODE_DARKEN,
    LXB_CSS_MIX_BLEND_MODE_DIFFERENCE,
    LXB_CSS_MIX_BLEND_MODE_EXCLUSION,
    LXB_CSS_MIX_BLEND_MODE_HARD_LIGHT,
    LXB_CSS_MIX_BLEND_MODE_HUE,
    LXB_CSS_MIX_BLEND_MODE_LIGHTEN,
    LXB_CSS_MIX_BLEND_MODE_LUMINOSITY,
    LXB_CSS_MIX_BLEND_MODE_MULTIPLY,
    LXB_CSS_MIX_BLEND_MODE_NORMAL,
    LXB_CSS_MIX_BLEND_MODE_OVERLAY,
    LXB_CSS_MIX_BLEND_MODE_SATURATION,
    LXB_CSS_MIX_BLEND_MODE_SCREEN,
    LXB_CSS_MIX_BLEND_MODE_SOFT_LIGHT,
    LXB_CSS_MIX_BLEND_MODE__LAST_ENTRY
}
lxb_css_mix_blend_mode_type_t;

typedef enum {
    LXB_CSS_NAV_DOWN_AUTO,
    LXB_CSS_NAV_DOWN_CURRENT,
    LXB_CSS_NAV_DOWN_ROOT,
    LXB_CSS_NAV_DOWN_TARGET_,
    LXB_CSS_NAV_DOWN__LAST_ENTRY
}
lxb_css_nav_down_type_t;

typedef enum {
    LXB_CSS_NAV_INDEX_AUTO,
    LXB_CSS_NAV_INDEX__LAST_ENTRY
}
lxb_css_nav_index_type_t;

typedef enum {
    LXB_CSS_NAV_LEFT_AUTO,
    LXB_CSS_NAV_LEFT_CURRENT,
    LXB_CSS_NAV_LEFT_ROOT,
    LXB_CSS_NAV_LEFT_TARGET_,
    LXB_CSS_NAV_LEFT__LAST_ENTRY
}
lxb_css_nav_left_type_t;

typedef enum {
    LXB_CSS_NAV_RIGHT_AUTO,
    LXB_CSS_NAV_RIGHT_CURRENT,
    LXB_CSS_NAV_RIGHT_ROOT,
    LXB_CSS_NAV_RIGHT_TARGET_,
    LXB_CSS_NAV_RIGHT__LAST_ENTRY
}
lxb_css_nav_right_type_t;

typedef enum {
    LXB_CSS_NAV_UP_AUTO,
    LXB_CSS_NAV_UP_CURRENT,
    LXB_CSS_NAV_UP_ROOT,
    LXB_CSS_NAV_UP_TARGET_,
    LXB_CSS_NAV_UP__LAST_ENTRY
}
lxb_css_nav_up_type_t;

typedef enum {
    LXB_CSS_OBJECT_FIT_CONTAIN,
    LXB_CSS_OBJECT_FIT_COVER,
    LXB_CSS_OBJECT_FIT_FILL,
    LXB_CSS_OBJECT_FIT_SCALE_DOWN,
    LXB_CSS_OBJECT_FIT__LAST_ENTRY
}
lxb_css_object_fit_type_t;

typedef enum {
    LXB_CSS_OUTLINE_COLOR_INVERT,
    LXB_CSS_OUTLINE_COLOR__LAST_ENTRY
}
lxb_css_outline_color_type_t;

typedef enum {
    LXB_CSS_OUTLINE_STYLE_DASHED,
    LXB_CSS_OUTLINE_STYLE_DOTTED,
    LXB_CSS_OUTLINE_STYLE_DOUBLE,
    LXB_CSS_OUTLINE_STYLE_GROOVE,
    LXB_CSS_OUTLINE_STYLE_HIDDEN,
    LXB_CSS_OUTLINE_STYLE_INSET,
    LXB_CSS_OUTLINE_STYLE_OUTSET,
    LXB_CSS_OUTLINE_STYLE_RIDGE,
    LXB_CSS_OUTLINE_STYLE_SOLID,
    LXB_CSS_OUTLINE_STYLE__LAST_ENTRY
}
lxb_css_outline_style_type_t;

typedef enum {
    LXB_CSS_OUTLINE_WIDTH_LENGTH,
    LXB_CSS_OUTLINE_WIDTH_MEDIUM,
    LXB_CSS_OUTLINE_WIDTH_THICK,
    LXB_CSS_OUTLINE_WIDTH_THIN,
    LXB_CSS_OUTLINE_WIDTH__LAST_ENTRY
}
lxb_css_outline_width_type_t;

typedef enum {
    LXB_CSS_OVERFLOW_CLIP_MARGIN_VISUAL_,
    LXB_CSS_OVERFLOW_CLIP_MARGIN__LAST_ENTRY
}
lxb_css_overflow_clip_margin_type_t;

typedef enum {
    LXB_CSS_OVERSCROLL_BEHAVIOR_AUTO,
    LXB_CSS_OVERSCROLL_BEHAVIOR_CONTAIN,
    LXB_CSS_OVERSCROLL_BEHAVIOR__LAST_ENTRY
}
lxb_css_overscroll_behavior_type_t;

typedef enum {
    LXB_CSS_PAGE_BREAK_AFTER_ALWAYS,
    LXB_CSS_PAGE_BREAK_AFTER_AUTO,
    LXB_CSS_PAGE_BREAK_AFTER_AVOID,
    LXB_CSS_PAGE_BREAK_AFTER_LEFT,
    LXB_CSS_PAGE_BREAK_AFTER_RIGHT,
    LXB_CSS_PAGE_BREAK_AFTER__LAST_ENTRY
}
lxb_css_page_break_after_type_t;

typedef enum {
    LXB_CSS_PAGE_BREAK_BEFORE_ALWAYS,
    LXB_CSS_PAGE_BREAK_BEFORE_AUTO,
    LXB_CSS_PAGE_BREAK_BEFORE_AVOID,
    LXB_CSS_PAGE_BREAK_BEFORE_LEFT,
    LXB_CSS_PAGE_BREAK_BEFORE_RIGHT,
    LXB_CSS_PAGE_BREAK_BEFORE__LAST_ENTRY
}
lxb_css_page_break_before_type_t;

typedef enum {
    LXB_CSS_PAGE_BREAK_INSIDE_AUTO,
    LXB_CSS_PAGE_BREAK_INSIDE_AVOID,
    LXB_CSS_PAGE_BREAK_INSIDE__LAST_ENTRY
}
lxb_css_page_break_inside_type_t;

typedef enum {
    LXB_CSS_PERSPECTIVE_ORIGIN_BOTTOM,
    LXB_CSS_PERSPECTIVE_ORIGIN_CENTER,
    LXB_CSS_PERSPECTIVE_ORIGIN_LEFT,
    LXB_CSS_PERSPECTIVE_ORIGIN_LENGTH_,
    LXB_CSS_PERSPECTIVE_ORIGIN_RIGHT,
    LXB_CSS_PERSPECTIVE_ORIGIN_TOP,
    LXB_CSS_PERSPECTIVE_ORIGIN__LAST_ENTRY
}
lxb_css_perspective_origin_type_t;

typedef enum {
    LXB_CSS_POINTER_EVENTS_ALL,
    LXB_CSS_POINTER_EVENTS_AUTO,
    LXB_CSS_POINTER_EVENTS_FILL,
    LXB_CSS_POINTER_EVENTS_PAINTED,
    LXB_CSS_POINTER_EVENTS_STROKE,
    LXB_CSS_POINTER_EVENTS_VISIBLE,
    LXB_CSS_POINTER_EVENTS_VISIBLEFILL,
    LXB_CSS_POINTER_EVENTS_VISIBLEPAINTED,
    LXB_CSS_POINTER_EVENTS_VISIBLESTROKE,
    LXB_CSS_POINTER_EVENTS__LAST_ENTRY
}
lxb_css_pointer_events_type_t;

typedef enum {
    LXB_CSS_RESIZE_BLOCK,
    LXB_CSS_RESIZE_BOTH,
    LXB_CSS_RESIZE_HORIZONTAL,
    LXB_CSS_RESIZE_INLINE,
    LXB_CSS_RESIZE_VERTICAL,
    LXB_CSS_RESIZE__LAST_ENTRY
}
lxb_css_resize_type_t;

typedef enum {
    LXB_CSS_RUBY_ALIGN_CENTER,
    LXB_CSS_RUBY_ALIGN_SPACE_AROUND,
    LXB_CSS_RUBY_ALIGN_SPACE_BETWEEN,
    LXB_CSS_RUBY_ALIGN_START,
    LXB_CSS_RUBY_ALIGN__LAST_ENTRY
}
lxb_css_ruby_align_type_t;

typedef enum {
    LXB_CSS_RUBY_POSITION_INTER_CHARACTER,
    LXB_CSS_RUBY_POSITION_OVER,
    LXB_CSS_RUBY_POSITION_UNDER,
    LXB_CSS_RUBY_POSITION__LAST_ENTRY
}
lxb_css_ruby_position_type_t;

typedef enum {
    LXB_CSS_SCROLL_BEHAVIOR_AUTO,
    LXB_CSS_SCROLL_BEHAVIOR_SMOOTH,
    LXB_CSS_SCROLL_BEHAVIOR__LAST_ENTRY
}
lxb_css_scroll_behavior_type_t;

typedef enum {
    LXB_CSS_SCROLL_PADDING_AUTO,
    LXB_CSS_SCROLL_PADDING_LENGTH_,
    LXB_CSS_SCROLL_PADDING__LAST_ENTRY
}
lxb_css_scroll_padding_type_t;

typedef enum {
    LXB_CSS_SCROLL_SNAP_ALIGN_CENTER,
    LXB_CSS_SCROLL_SNAP_ALIGN_END,
    LXB_CSS_SCROLL_SNAP_ALIGN_START,
    LXB_CSS_SCROLL_SNAP_ALIGN__LAST_ENTRY
}
lxb_css_scroll_snap_align_type_t;

typedef enum {
    LXB_CSS_SCROLL_SNAP_TYPE_BLOCK,
    LXB_CSS_SCROLL_SNAP_TYPE_BOTH,
    LXB_CSS_SCROLL_SNAP_TYPE_INLINE,
    LXB_CSS_SCROLL_SNAP_TYPE_MANDATORY,
    LXB_CSS_SCROLL_SNAP_TYPE_PROXIMITY,
    LXB_CSS_SCROLL_SNAP_TYPE__LAST_ENTRY
}
lxb_css_scroll_snap_type_type_t;

typedef enum {
    LXB_CSS_TABLE_LAYOUT_AUTO,
    LXB_CSS_TABLE_LAYOUT_FIXED,
    LXB_CSS_TABLE_LAYOUT__LAST_ENTRY
}
lxb_css_table_layout_type_t;

typedef enum {
    LXB_CSS_TEXT_DECORATION_THICKNESS_AUTO,
    LXB_CSS_TEXT_DECORATION_THICKNESS_FROM_FONT,
    LXB_CSS_TEXT_DECORATION_THICKNESS__LAST_ENTRY
}
lxb_css_text_decoration_thickness_type_t;

typedef enum {
    LXB_CSS_TEXT_EMPHASIS_POSITION_LEFT,
    LXB_CSS_TEXT_EMPHASIS_POSITION_OVER,
    LXB_CSS_TEXT_EMPHASIS_POSITION_RIGHT,
    LXB_CSS_TEXT_EMPHASIS_POSITION_UNDER,
    LXB_CSS_TEXT_EMPHASIS_POSITION__LAST_ENTRY
}
lxb_css_text_emphasis_position_type_t;

typedef enum {
    LXB_CSS_TRANSFORM_TRANSFORM_,
    LXB_CSS_TRANSFORM__LAST_ENTRY
}
lxb_css_transform_type_t;

typedef enum {
    LXB_CSS_TRANSFORM_ORIGIN_BOTTOM,
    LXB_CSS_TRANSFORM_ORIGIN_CENTER,
    LXB_CSS_TRANSFORM_ORIGIN_LEFT,
    LXB_CSS_TRANSFORM_ORIGIN_LENGTH_,
    LXB_CSS_TRANSFORM_ORIGIN_RIGHT,
    LXB_CSS_TRANSFORM_ORIGIN_TOP,
    LXB_CSS_TRANSFORM_ORIGIN__LAST_ENTRY
}
lxb_css_transform_origin_type_t;

typedef enum {
    LXB_CSS_TRANSFORM_STYLE_FLAT,
    LXB_CSS_TRANSFORM_STYLE_PRESERVE_3D,
    LXB_CSS_TRANSFORM_STYLE__LAST_ENTRY
}
lxb_css_transform_style_type_t;

typedef enum {
    LXB_CSS_TRANSITION_PROPERTY_ALL,
    LXB_CSS_TRANSITION_PROPERTY_CUSTOM_,
    LXB_CSS_TRANSITION_PROPERTY__LAST_ENTRY
}
lxb_css_transition_property_type_t;

typedef enum {
    LXB_CSS_TRANSITION_TIMING_FUNCTION_CUBIC_BEZIER,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_EASE,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_EASE_IN,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_EASE_IN_OUT,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_EASE_OUT,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_LINEAR,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_STEPS,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_STEP_,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_STEP_END,
    LXB_CSS_TRANSITION_TIMING_FUNCTION_STEP_START,
    LXB_CSS_TRANSITION_TIMING_FUNCTION__LAST_ENTRY
}
lxb_css_transition_timing_function_type_t;

typedef enum {
    LXB_CSS_USER_SELECT_ALL,
    LXB_CSS_USER_SELECT_AUTO,
    LXB_CSS_USER_SELECT_CONTAIN,
    LXB_CSS_USER_SELECT_TEXT,
    LXB_CSS_USER_SELECT__LAST_ENTRY
}
lxb_css_user_select_type_t;

/* Struct definitions */

/* Struct definitions */

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
