/*
 * Copyright (C) 2023 Alexander Borisov
 *
 * Author: Alexander Borisov <borisov@lexbor.com>
 */

/* Enumeration definitions */

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

// typedef enum {
//     LXB_CSS_BOX_SHADOW_INSET,
//     LXB_CSS_BOX_SHADOW__LAST_ENTRY
// }
// lxb_css_box_shadow_type_t;

/* Struct definitions */

/* Struct definitions */

typedef struct {
    lxb_css_value_type_t type;
    lxb_css_value_color_t *values;
    size_t length;
}
lxb_css_property_box_shadow_t;

/* Function prototypes */

LXB_API void *
lxb_css_property_box_shadow_create(lxb_css_memory_t *memory);
LXB_API void *
lxb_css_property_box_shadow_destroy(lxb_css_memory_t *memory,
                                     void *style, bool self_destroy);
LXB_API lxb_status_t
lxb_css_property_box_shadow_serialize(const void *style,
                                       lexbor_serialize_cb_f cb, void *ctx);

typedef struct {
    lxb_css_value_length_percentage_t top;
    lxb_css_value_length_percentage_t right;
    lxb_css_value_length_percentage_t bottom;
    lxb_css_value_length_percentage_t left;
} lxb_css_property_border_radius_t;

/* Struct definitions */

/* Function prototypes */
