/*
 * Copyright (C) 2023
 *
 * Author: 
 */

#ifndef LXB_CSS_PROPERTY_EXTRA_H
#define LXB_CSS_PROPERTY_EXTRA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lexbor/core/serialize.h"
#include "lexbor/css/base.h"
#include "lexbor/css/value.h"
#include "lexbor/css/unit/const.h"
#include "lexbor/css/property/const.h"
#include "lexbor/css/property.h"

/* Time unit type */
typedef enum {
    LXB_CSS_TIME_UNIT_SECONDS,
    LXB_CSS_TIME_UNIT_MILLISECONDS
} lxb_css_time_unit_t;

/* Time value */
typedef struct {
    double               value;
    lxb_css_time_unit_t  unit;
} lxb_css_value_time_t;

/* Transform type */
typedef enum {
    LXB_CSS_TRANSFORM_NONE,
    LXB_CSS_TRANSFORM_MATRIX,
    LXB_CSS_TRANSFORM_TRANSLATE,
    LXB_CSS_TRANSFORM_TRANSLATE_X,
    LXB_CSS_TRANSFORM_TRANSLATE_Y,
    LXB_CSS_TRANSFORM_TRANSLATE_Z,
    LXB_CSS_TRANSFORM_TRANSLATE_3D,
    LXB_CSS_TRANSFORM_SCALE,
    LXB_CSS_TRANSFORM_SCALE_X,
    LXB_CSS_TRANSFORM_SCALE_Y,
    LXB_CSS_TRANSFORM_SCALE_Z,
    LXB_CSS_TRANSFORM_SCALE_3D,
    LXB_CSS_TRANSFORM_ROTATE,
    LXB_CSS_TRANSFORM_ROTATE_X,
    LXB_CSS_TRANSFORM_ROTATE_Y,
    LXB_CSS_TRANSFORM_ROTATE_Z,
    LXB_CSS_TRANSFORM_ROTATE_3D,
    LXB_CSS_TRANSFORM_SKEW,
    LXB_CSS_TRANSFORM_SKEW_X,
    LXB_CSS_TRANSFORM_SKEW_Y,
    LXB_CSS_TRANSFORM_PERSPECTIVE
} lxb_css_transform_type_t;

/* Timing function type */
typedef enum {
    LXB_CSS_TIMING_FUNCTION_EASE,
    LXB_CSS_TIMING_FUNCTION_LINEAR,
    LXB_CSS_TIMING_FUNCTION_EASE_IN,
    LXB_CSS_TIMING_FUNCTION_EASE_OUT,
    LXB_CSS_TIMING_FUNCTION_EASE_IN_OUT,
    LXB_CSS_TIMING_FUNCTION_STEP_START,
    LXB_CSS_TIMING_FUNCTION_STEP_END,
    LXB_CSS_TIMING_FUNCTION_STEPS,
    LXB_CSS_TIMING_FUNCTION_CUBIC_BEZIER
} lxb_css_timing_function_type_t;

/* Animation direction type */
typedef enum {
    LXB_CSS_ANIMATION_DIRECTION_NORMAL,
    LXB_CSS_ANIMATION_DIRECTION_REVERSE,
    LXB_CSS_ANIMATION_DIRECTION_ALTERNATE,
    LXB_CSS_ANIMATION_DIRECTION_ALTERNATE_REVERSE
} lxb_css_animation_direction_type_t;

/* Animation play state type */
typedef enum {
    LXB_CSS_ANIMATION_PLAY_STATE_RUNNING,
    LXB_CSS_ANIMATION_PLAY_STATE_PAUSED
} lxb_css_animation_play_state_type_t;

/* Animation fill mode type */
typedef enum {
    LXB_CSS_ANIMATION_FILL_MODE_NONE,
    LXB_CSS_ANIMATION_FILL_MODE_FORWARDS,
    LXB_CSS_ANIMATION_FILL_MODE_BACKWARDS,
    LXB_CSS_ANIMATION_FILL_MODE_BOTH
} lxb_css_animation_fill_mode_type_t;

/* Grid template track type */
typedef enum {
    LXB_CSS_GRID_TEMPLATE_TRACK_AUTO,
    LXB_CSS_GRID_TEMPLATE_TRACK_MAX_CONTENT,
    LXB_CSS_GRID_TEMPLATE_TRACK_MIN_CONTENT,
    LXB_CSS_GRID_TEMPLATE_TRACK_MINMAX,
    LXB_CSS_GRID_TEMPLATE_TRACK_FIT_CONTENT,
    LXB_CSS_GRID_TEMPLATE_TRACK_REPEAT,
    LXB_CSS_GRID_TEMPLATE_TRACK_SUBGRID,
    LXB_CSS_GRID_TEMPLATE_TRACK_MASONRY
} lxb_css_grid_template_track_type_t;

/* Grid auto flow type */
typedef enum {
    LXB_CSS_GRID_AUTO_FLOW_ROW,
    LXB_CSS_GRID_AUTO_FLOW_COLUMN,
    LXB_CSS_GRID_AUTO_FLOW_DENSE,
    LXB_CSS_GRID_AUTO_FLOW_ROW_DENSE,
    LXB_CSS_GRID_AUTO_FLOW_COLUMN_DENSE
} lxb_css_grid_auto_flow_type_t;

/* Background image type */
typedef enum {
    LXB_CSS_BACKGROUND_IMAGE_NONE,
    LXB_CSS_BACKGROUND_IMAGE_URL,
    LXB_CSS_BACKGROUND_IMAGE_LINEAR_GRADIENT,
    LXB_CSS_BACKGROUND_IMAGE_RADIAL_GRADIENT,
    LXB_CSS_BACKGROUND_IMAGE_REPEATING_LINEAR_GRADIENT,
    LXB_CSS_BACKGROUND_IMAGE_REPEATING_RADIAL_GRADIENT,
    LXB_CSS_BACKGROUND_IMAGE_CONIC_GRADIENT,
    LXB_CSS_BACKGROUND_IMAGE_REPEATING_CONIC_GRADIENT
} lxb_css_background_image_type_t;

/* Background repeat type */
typedef enum {
    LXB_CSS_BACKGROUND_REPEAT_REPEAT,
    LXB_CSS_BACKGROUND_REPEAT_NO_REPEAT,
    LXB_CSS_BACKGROUND_REPEAT_SPACE,
    LXB_CSS_BACKGROUND_REPEAT_ROUND
} lxb_css_background_repeat_type_t;

/* Background size type */
typedef enum {
    LXB_CSS_BACKGROUND_SIZE_AUTO,
    LXB_CSS_BACKGROUND_SIZE_COVER,
    LXB_CSS_BACKGROUND_SIZE_CONTAIN,
    LXB_CSS_BACKGROUND_SIZE_LENGTH_PERCENTAGE
} lxb_css_background_size_type_t;

/* Background attachment type */
typedef enum {
    LXB_CSS_BACKGROUND_ATTACHMENT_SCROLL,
    LXB_CSS_BACKGROUND_ATTACHMENT_FIXED,
    LXB_CSS_BACKGROUND_ATTACHMENT_LOCAL
} lxb_css_background_attachment_type_t;

/* Background origin type */
typedef enum {
    LXB_CSS_BACKGROUND_ORIGIN_PADDING_BOX,
    LXB_CSS_BACKGROUND_ORIGIN_BORDER_BOX,
    LXB_CSS_BACKGROUND_ORIGIN_CONTENT_BOX
} lxb_css_background_origin_type_t;

/* Background clip type */
typedef enum {
    LXB_CSS_BACKGROUND_CLIP_BORDER_BOX,
    LXB_CSS_BACKGROUND_CLIP_PADDING_BOX,
    LXB_CSS_BACKGROUND_CLIP_CONTENT_BOX,
    LXB_CSS_BACKGROUND_CLIP_TEXT
} lxb_css_background_clip_type_t;

/* List style type */
typedef enum {
    LXB_CSS_LIST_STYLE_TYPE_NONE,
    LXB_CSS_LIST_STYLE_TYPE_DISC,
    LXB_CSS_LIST_STYLE_TYPE_CIRCLE,
    LXB_CSS_LIST_STYLE_TYPE_SQUARE,
    LXB_CSS_LIST_STYLE_TYPE_DECIMAL,
    LXB_CSS_LIST_STYLE_TYPE_DECIMAL_LEADING_ZERO,
    LXB_CSS_LIST_STYLE_TYPE_LOWER_ROMAN,
    LXB_CSS_LIST_STYLE_TYPE_UPPER_ROMAN,
    LXB_CSS_LIST_STYLE_TYPE_LOWER_GREEK,
    LXB_CSS_LIST_STYLE_TYPE_LOWER_ALPHA,
    LXB_CSS_LIST_STYLE_TYPE_LOWER_LATIN,
    LXB_CSS_LIST_STYLE_TYPE_UPPER_ALPHA,
    LXB_CSS_LIST_STYLE_TYPE_UPPER_LATIN,
    LXB_CSS_LIST_STYLE_TYPE_ARMENIAN,
    LXB_CSS_LIST_STYLE_TYPE_GEORGIAN,
    LXB_CSS_LIST_STYLE_TYPE_HEBREW,
    LXB_CSS_LIST_STYLE_TYPE_HIRAGANA,
    LXB_CSS_LIST_STYLE_TYPE_HIRAGANA_IROHA,
    LXB_CSS_LIST_STYLE_TYPE_KATAKANA,
    LXB_CSS_LIST_STYLE_TYPE_KATAKANA_IROHA,
    LXB_CSS_LIST_STYLE_TYPE_CJK_IDEOGRAPHIC
} lxb_css_list_style_type_t;

/* List style position type */
typedef enum {
    LXB_CSS_LIST_STYLE_POSITION_OUTSIDE,
    LXB_CSS_LIST_STYLE_POSITION_INSIDE
} lxb_css_list_style_position_type_t;

/* List style image type */
typedef enum {
    LXB_CSS_LIST_STYLE_IMAGE_NONE,
    LXB_CSS_LIST_STYLE_IMAGE_URL
} lxb_css_list_style_image_type_t;

/* Content type */
typedef enum {
    LXB_CSS_CONTENT_NORMAL,
    LXB_CSS_CONTENT_NONE,
    LXB_CSS_CONTENT_STRING,
    LXB_CSS_CONTENT_URL,
    LXB_CSS_CONTENT_COUNTER,
    LXB_CSS_CONTENT_COUNTERS,
    LXB_CSS_CONTENT_ATTR,
    LXB_CSS_CONTENT_OPEN_QUOTE,
    LXB_CSS_CONTENT_CLOSE_QUOTE,
    LXB_CSS_CONTENT_NO_OPEN_QUOTE,
    LXB_CSS_CONTENT_NO_CLOSE_QUOTE
} lxb_css_content_type_t;

/* User select type */
typedef enum {
    LXB_CSS_USER_SELECT_AUTO,
    LXB_CSS_USER_SELECT_NONE,
    LXB_CSS_USER_SELECT_TEXT,
    LXB_CSS_USER_SELECT_CONTAIN,
    LXB_CSS_USER_SELECT_ALL
} lxb_css_user_select_type_t;

/* Pointer events type */
typedef enum {
    LXB_CSS_POINTER_EVENTS_AUTO,
    LXB_CSS_POINTER_EVENTS_NONE,
    LXB_CSS_POINTER_EVENTS_VISIBLEPAINTED,
    LXB_CSS_POINTER_EVENTS_VISIBLEFILL,
    LXB_CSS_POINTER_EVENTS_VISIBLESTROKE,
    LXB_CSS_POINTER_EVENTS_VISIBLE,
    LXB_CSS_POINTER_EVENTS_PAINTED,
    LXB_CSS_POINTER_EVENTS_FILL,
    LXB_CSS_POINTER_EVENTS_STROKE,
    LXB_CSS_POINTER_EVENTS_ALL
} lxb_css_pointer_events_type_t;

/* Resize type */
typedef enum {
    LXB_CSS_RESIZE_NONE,
    LXB_CSS_RESIZE_BOTH,
    LXB_CSS_RESIZE_HORIZONTAL,
    LXB_CSS_RESIZE_VERTICAL,
    LXB_CSS_RESIZE_BLOCK,
    LXB_CSS_RESIZE_INLINE
} lxb_css_resize_type_t;

/* Object fit type */
typedef enum {
    LXB_CSS_OBJECT_FIT_FILL,
    LXB_CSS_OBJECT_FIT_CONTAIN,
    LXB_CSS_OBJECT_FIT_COVER,
    LXB_CSS_OBJECT_FIT_NONE,
    LXB_CSS_OBJECT_FIT_SCALE_DOWN
} lxb_css_object_fit_type_t;

/* Transform */
typedef struct {
    lxb_css_transform_type_t type;
    lxb_css_value_number_length_percentage_t values[3];  /* For functions with parameters */
    double                    angle;                     /* For rotate functions */
}
lxb_css_property_transform_t;

/* Transition-property */
typedef struct {
    lexbor_str_t property_name;
}
lxb_css_property_transition_property_t;

/* Transition-duration */
typedef lxb_css_value_time_t lxb_css_property_transition_duration_t;

/* Transition-timing-function */
typedef struct {
    lxb_css_timing_function_type_t type;
    lxb_css_value_number_t         x1;
    lxb_css_value_number_t         y1;
    lxb_css_value_number_t         x2;
    lxb_css_value_number_t         y2;
}
lxb_css_property_transition_timing_function_t;

/* Transition-delay */
typedef lxb_css_value_time_t lxb_css_property_transition_delay_t;

/* Transition (shorthand) */
typedef struct {
    lxb_css_property_transition_property_t      property;
    lxb_css_property_transition_duration_t      duration;
    lxb_css_property_transition_timing_function_t timing_function;
    lxb_css_property_transition_delay_t         delay;
}
lxb_css_property_transition_t;

/* Animation-name */
typedef struct {
    lexbor_str_t name;
}
lxb_css_property_animation_name_t;

/* Animation-duration */
typedef lxb_css_value_time_t lxb_css_property_animation_duration_t;

/* Animation-timing-function */
typedef lxb_css_property_transition_timing_function_t lxb_css_property_animation_timing_function_t;

/* Animation-iteration-count */
typedef struct {
    bool                   infinite;
    lxb_css_value_number_t count;
}
lxb_css_property_animation_iteration_count_t;

/* Animation-direction */
typedef struct {
    lxb_css_animation_direction_type_t type;
}
lxb_css_property_animation_direction_t;

/* Animation-play-state */
typedef struct {
    lxb_css_animation_play_state_type_t type;
}
lxb_css_property_animation_play_state_t;

/* Animation-delay */
typedef lxb_css_value_time_t lxb_css_property_animation_delay_t;

/* Animation-fill-mode */
typedef struct {
    lxb_css_animation_fill_mode_type_t type;
}
lxb_css_property_animation_fill_mode_t;

/* Animation (shorthand) */
typedef struct {
    lxb_css_property_animation_name_t           name;
    lxb_css_property_animation_duration_t       duration;
    lxb_css_property_animation_timing_function_t timing_function;
    lxb_css_property_animation_delay_t          delay;
    lxb_css_property_animation_iteration_count_t iteration_count;
    lxb_css_property_animation_direction_t      direction;
    lxb_css_property_animation_fill_mode_t      fill_mode;
    lxb_css_property_animation_play_state_t     play_state;
}
lxb_css_property_animation_t;

/* Grid-template-columns */
typedef struct {
    size_t                                count;
    lxb_css_value_length_percentage_t     *tracks;
    lxb_css_grid_template_track_type_t    *track_types;
}
lxb_css_property_grid_template_columns_t;

/* Grid-template-rows */
typedef struct {
    size_t                                count;
    lxb_css_value_length_percentage_t     *tracks;
    lxb_css_grid_template_track_type_t    *track_types;
}
lxb_css_property_grid_template_rows_t;

/* Grid-template-areas */
typedef struct {
    size_t      row_count;
    size_t      col_count;
    lexbor_str_t **areas;  /* 2D array of area names */
}
lxb_css_property_grid_template_areas_t;

/* Grid-auto-flow */
typedef struct {
    lxb_css_grid_auto_flow_type_t type;
    bool                          dense;
}
lxb_css_property_grid_auto_flow_t;

/* Grid-auto-rows */
typedef struct {
    size_t                            count;
    lxb_css_value_length_percentage_t *sizes;
}
lxb_css_property_grid_auto_rows_t;

/* Grid-auto-columns */
typedef struct {
    size_t                            count;
    lxb_css_value_length_percentage_t *sizes;
}
lxb_css_property_grid_auto_columns_t;

/* Grid-column-start, Grid-column-end, Grid-row-start, Grid-row-end */
typedef struct {
    bool                          is_span;
    lxb_css_value_integer_t       line;
    lexbor_str_t                  name;
}
lxb_css_property_grid_line_t;

typedef lxb_css_property_grid_line_t lxb_css_property_grid_column_start_t;
typedef lxb_css_property_grid_line_t lxb_css_property_grid_column_end_t;
typedef lxb_css_property_grid_line_t lxb_css_property_grid_row_start_t;
typedef lxb_css_property_grid_line_t lxb_css_property_grid_row_end_t;

/* Grid-column, Grid-row (shorthands) */
typedef struct {
    lxb_css_property_grid_line_t start;
    lxb_css_property_grid_line_t end;
}
lxb_css_property_grid_column_t;

typedef struct {
    lxb_css_property_grid_line_t start;
    lxb_css_property_grid_line_t end;
}
lxb_css_property_grid_row_t;

/* Grid-area (shorthand for grid-row-start, grid-column-start, grid-row-end, grid-column-end) */
typedef struct {
    lxb_css_property_grid_row_start_t    row_start;
    lxb_css_property_grid_column_start_t column_start;
    lxb_css_property_grid_row_end_t      row_end;
    lxb_css_property_grid_column_end_t   column_end;
}
lxb_css_property_grid_area_t;

/* Grid (shorthand for all grid properties) */
typedef struct {
    lxb_css_property_grid_template_rows_t    template_rows;
    lxb_css_property_grid_template_columns_t template_columns;
    lxb_css_property_grid_template_areas_t   template_areas;
    lxb_css_property_grid_auto_rows_t        auto_rows;
    lxb_css_property_grid_auto_columns_t     auto_columns;
    lxb_css_property_grid_auto_flow_t        auto_flow;
}
lxb_css_property_grid_t;

/* Background-image */
typedef struct {
    lxb_css_background_image_type_t type;
    union {
        lexbor_str_t               url;
        lxb_css_value_color_t      color;
        /* Add other gradient types as needed */
    } u;
}
lxb_css_property_background_image_t;

/* Background-repeat */
typedef struct {
    lxb_css_background_repeat_type_t x;
    lxb_css_background_repeat_type_t y;
}
lxb_css_property_background_repeat_t;

/* Background-size */
typedef struct {
    lxb_css_background_size_type_t type;
    lxb_css_value_length_percentage_t width;
    lxb_css_value_length_percentage_t height;
}
lxb_css_property_background_size_t;

/* Background-position */
typedef struct {
    lxb_css_value_length_percentage_t x;
    lxb_css_value_length_percentage_t y;
}
lxb_css_property_background_position_t;

/* Background-attachment */
typedef struct {
    lxb_css_background_attachment_type_t type;
}
lxb_css_property_background_attachment_t;

/* Background-origin */
typedef struct {
    lxb_css_background_origin_type_t type;
}
lxb_css_property_background_origin_t;

/* Background-clip */
typedef struct {
    lxb_css_background_clip_type_t type;
}
lxb_css_property_background_clip_t;

/* Box-shadow */
typedef struct {
    bool inset;
    lxb_css_value_length_t x_offset;
    lxb_css_value_length_t y_offset;
    lxb_css_value_length_t blur_radius;
    lxb_css_value_length_t spread_radius;
    lxb_css_value_color_t color;
}
lxb_css_property_box_shadow_t;

/* Border-radius */
typedef struct {
    lxb_css_value_length_percentage_t top_left;
    lxb_css_value_length_percentage_t top_right;
    lxb_css_value_length_percentage_t bottom_right;
    lxb_css_value_length_percentage_t bottom_left;
}
lxb_css_property_border_radius_t;

/* Border-top-left-radius */
typedef lxb_css_value_length_percentage_t lxb_css_property_border_top_left_radius_t;

/* Border-top-right-radius */
typedef lxb_css_value_length_percentage_t lxb_css_property_border_top_right_radius_t;

/* Border-bottom-right-radius */
typedef lxb_css_value_length_percentage_t lxb_css_property_border_bottom_right_radius_t;

/* Border-bottom-left-radius */
typedef lxb_css_value_length_percentage_t lxb_css_property_border_bottom_left_radius_t;

/* Text-shadow */
typedef struct {
    lxb_css_value_length_t x_offset;
    lxb_css_value_length_t y_offset;
    lxb_css_value_length_t blur_radius;
    lxb_css_value_color_t color;
}
lxb_css_property_text_shadow_t;

/* List-style-type */
typedef struct {
    lxb_css_list_style_type_t type;
}
lxb_css_property_list_style_type_t;

/* List-style-position */
typedef struct {
    lxb_css_list_style_position_type_t type;
}
lxb_css_property_list_style_position_t;

/* List-style-image */
typedef struct {
    lxb_css_list_style_image_type_t type;
    lexbor_str_t                   url;
}
lxb_css_property_list_style_image_t;

/* List-style */
typedef struct {
    lxb_css_property_list_style_type_t     type;
    lxb_css_property_list_style_position_t position;
    lxb_css_property_list_style_image_t    image;
}
lxb_css_property_list_style_t;

/* Content */
typedef struct {
    lxb_css_content_type_t type;
    lexbor_str_t          value;
}
lxb_css_property_content_t;

/* Counter-reset */
typedef struct {
    lexbor_str_t          name;
    lxb_css_value_integer_t value;
}
lxb_css_property_counter_reset_t;

/* Counter-increment */
typedef struct {
    lexbor_str_t          name;
    lxb_css_value_integer_t value;
}
lxb_css_property_counter_increment_t;

/* Font (shorthand) */
typedef struct {
    lxb_css_property_font_style_t   style;
    lxb_css_property_font_weight_t  weight;
    lxb_css_property_font_stretch_t stretch;
    lxb_css_property_font_size_t    size;
    lxb_css_property_line_height_t  line_height;
    lxb_css_property_font_family_t  family;
}
lxb_css_property_font_t;

/* Column-count */
typedef lxb_css_value_integer_type_t lxb_css_property_column_count_t;

/* Column-width */
typedef lxb_css_value_length_type_t lxb_css_property_column_width_t;

/* Column-gap */
typedef lxb_css_value_length_percentage_t lxb_css_property_column_gap_t;

/* Row-gap */
typedef lxb_css_value_length_percentage_t lxb_css_property_row_gap_t;

/* Gap (shorthand) */
typedef struct {
    lxb_css_property_row_gap_t    row;
    lxb_css_property_column_gap_t column;
}
lxb_css_property_gap_t;

/* User-select */
typedef struct {
    lxb_css_user_select_type_t type;
}
lxb_css_property_user_select_t;

/* Pointer-events */
typedef struct {
    lxb_css_pointer_events_type_t type;
}
lxb_css_property_pointer_events_t;

/* Resize */
typedef struct {
    lxb_css_resize_type_t type;
}
lxb_css_property_resize_t;

/* Object-fit */
typedef struct {
    lxb_css_object_fit_type_t type;
}
lxb_css_property_object_fit_t;

/* Object-position */
typedef struct {
    lxb_css_value_length_percentage_t x;
    lxb_css_value_length_percentage_t y;
}
lxb_css_property_object_position_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LXB_CSS_PROPERTY_EXTRA_H */
