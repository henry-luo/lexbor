/*
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


/* background-image. */

LXB_API void *
lxb_css_property_background_image_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_background_image_t));
}

LXB_API void *
lxb_css_property_background_image_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_background_image_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_background_image_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* background-size. */

LXB_API void *
lxb_css_property_background_size_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_background_size_t));
}

LXB_API void *
lxb_css_property_background_size_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_background_size_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* background-repeat. */

LXB_API void *
lxb_css_property_background_repeat_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_background_repeat_t));
}

LXB_API void *
lxb_css_property_background_repeat_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_background_repeat_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_background_repeat_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* background-attachment. */

LXB_API void *
lxb_css_property_background_attachment_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_background_attachment_t));
}

LXB_API void *
lxb_css_property_background_attachment_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_background_attachment_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_background_attachment_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* background-origin. */

LXB_API void *
lxb_css_property_background_origin_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_background_origin_t));
}

LXB_API void *
lxb_css_property_background_origin_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_background_origin_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_background_origin_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* background-clip. */

LXB_API void *
lxb_css_property_background_clip_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_background_clip_t));
}

LXB_API void *
lxb_css_property_background_clip_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_background_clip_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_background_clip_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* background-position. */

LXB_API void *
lxb_css_property_background_position_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_background_position_t));
}

LXB_API void *
lxb_css_property_background_position_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_background_position_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* border-radius. */

LXB_API void *
lxb_css_property_border_radius_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_radius_t));
}

LXB_API void *
lxb_css_property_border_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* border-top-left-radius. */

LXB_API void *
lxb_css_property_border_top_left_radius_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_top_left_radius_t));
}

LXB_API void *
lxb_css_property_border_top_left_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_top_left_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* border-top-right-radius. */

LXB_API void *
lxb_css_property_border_top_right_radius_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_top_right_radius_t));
}

LXB_API void *
lxb_css_property_border_top_right_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_top_right_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* border-bottom-right-radius. */

LXB_API void *
lxb_css_property_border_bottom_right_radius_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_bottom_right_radius_t));
}

LXB_API void *
lxb_css_property_border_bottom_right_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_bottom_right_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* border-bottom-left-radius. */

LXB_API void *
lxb_css_property_border_bottom_left_radius_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_bottom_left_radius_t));
}

LXB_API void *
lxb_css_property_border_bottom_left_radius_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_bottom_left_radius_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* border-image-source. */

LXB_API void *
lxb_css_property_border_image_source_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_image_source_t));
}

LXB_API void *
lxb_css_property_border_image_source_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_image_source_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_border_image_source_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* border-image-slice. */

LXB_API void *
lxb_css_property_border_image_slice_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_image_slice_t));
}

LXB_API void *
lxb_css_property_border_image_slice_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_image_slice_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_border_image_slice_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* border-image-width. */

LXB_API void *
lxb_css_property_border_image_width_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_image_width_t));
}

LXB_API void *
lxb_css_property_border_image_width_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_image_width_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* border-image-outset. */

LXB_API void *
lxb_css_property_border_image_outset_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_image_outset_t));
}

LXB_API void *
lxb_css_property_border_image_outset_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_image_outset_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_border_image_outset_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* border-image-repeat. */

LXB_API void *
lxb_css_property_border_image_repeat_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_image_repeat_t));
}

LXB_API void *
lxb_css_property_border_image_repeat_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_image_repeat_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_border_image_repeat_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* border-image. */

LXB_API void *
lxb_css_property_border_image_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_image_t));
}

LXB_API void *
lxb_css_property_border_image_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_image_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_border_image_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* outline-style. */

LXB_API void *
lxb_css_property_outline_style_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_outline_style_t));
}

LXB_API void *
lxb_css_property_outline_style_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_outline_style_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_outline_style_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* outline-width. */

LXB_API void *
lxb_css_property_outline_width_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_outline_width_t));
}

LXB_API void *
lxb_css_property_outline_width_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_outline_width_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_outline_width_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* outline-color. */

LXB_API void *
lxb_css_property_outline_color_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_outline_color_t));
}

LXB_API void *
lxb_css_property_outline_color_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_outline_color_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_color_serialize(style, cb, ctx);
}

/* outline. */

LXB_API void *
lxb_css_property_outline_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_outline_t));
}

LXB_API void *
lxb_css_property_outline_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_outline_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_outline_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* outline-offset. */

LXB_API void *
lxb_css_property_outline_offset_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_outline_offset_t));
}

LXB_API void *
lxb_css_property_outline_offset_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_outline_offset_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_outline_offset_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* box-shadow. */

LXB_API void *
lxb_css_property_box_shadow_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_box_shadow_t));
}

LXB_API void *
lxb_css_property_box_shadow_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_box_shadow_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_box_shadow_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* text-shadow. */

LXB_API void *
lxb_css_property_text_shadow_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_text_shadow_t));
}

LXB_API void *
lxb_css_property_text_shadow_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_text_shadow_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_text_shadow_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* text-decoration-thickness. */

LXB_API void *
lxb_css_property_text_decoration_thickness_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_text_decoration_thickness_t));
}

LXB_API void *
lxb_css_property_text_decoration_thickness_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_text_decoration_thickness_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* text-emphasis-style. */

LXB_API void *
lxb_css_property_text_emphasis_style_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_text_emphasis_style_t));
}

LXB_API void *
lxb_css_property_text_emphasis_style_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_text_emphasis_style_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_text_emphasis_style_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* text-emphasis-color. */

LXB_API void *
lxb_css_property_text_emphasis_color_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_text_emphasis_color_t));
}

LXB_API void *
lxb_css_property_text_emphasis_color_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_text_emphasis_color_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_color_serialize(style, cb, ctx);
}

/* text-emphasis-position. */

LXB_API void *
lxb_css_property_text_emphasis_position_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_text_emphasis_position_t));
}

LXB_API void *
lxb_css_property_text_emphasis_position_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_text_emphasis_position_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_text_emphasis_position_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* text-emphasis. */

LXB_API void *
lxb_css_property_text_emphasis_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_text_emphasis_t));
}

LXB_API void *
lxb_css_property_text_emphasis_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_text_emphasis_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_text_emphasis_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* column-width. */

LXB_API void *
lxb_css_property_column_width_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_width_t));
}

LXB_API void *
lxb_css_property_column_width_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_width_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_column_width_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* column-count. */

LXB_API void *
lxb_css_property_column_count_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_count_t));
}

LXB_API void *
lxb_css_property_column_count_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_count_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_column_count_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* columns. */

LXB_API void *
lxb_css_property_columns_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_columns_t));
}

LXB_API void *
lxb_css_property_columns_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_columns_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_columns_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* column-gap. */

LXB_API void *
lxb_css_property_column_gap_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_gap_t));
}

LXB_API void *
lxb_css_property_column_gap_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_gap_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* column-rule-style. */

LXB_API void *
lxb_css_property_column_rule_style_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_rule_style_t));
}

LXB_API void *
lxb_css_property_column_rule_style_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_rule_style_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_column_rule_style_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* column-rule-width. */

LXB_API void *
lxb_css_property_column_rule_width_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_rule_width_t));
}

LXB_API void *
lxb_css_property_column_rule_width_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_rule_width_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_column_rule_width_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* column-rule-color. */

LXB_API void *
lxb_css_property_column_rule_color_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_rule_color_t));
}

LXB_API void *
lxb_css_property_column_rule_color_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_rule_color_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_color_serialize(style, cb, ctx);
}

/* column-rule. */

LXB_API void *
lxb_css_property_column_rule_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_rule_t));
}

LXB_API void *
lxb_css_property_column_rule_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_rule_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_column_rule_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* column-span. */

LXB_API void *
lxb_css_property_column_span_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_span_t));
}

LXB_API void *
lxb_css_property_column_span_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_span_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_column_span_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* column-fill. */

LXB_API void *
lxb_css_property_column_fill_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_column_fill_t));
}

LXB_API void *
lxb_css_property_column_fill_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_column_fill_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_column_fill_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* transform. */

LXB_API void *
lxb_css_property_transform_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transform_t));
}

LXB_API void *
lxb_css_property_transform_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transform_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_transform_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* transform-origin. */

LXB_API void *
lxb_css_property_transform_origin_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transform_origin_t));
}

LXB_API void *
lxb_css_property_transform_origin_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transform_origin_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* transform-style. */

LXB_API void *
lxb_css_property_transform_style_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transform_style_t));
}

LXB_API void *
lxb_css_property_transform_style_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transform_style_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_transform_style_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* perspective. */

LXB_API void *
lxb_css_property_perspective_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_perspective_t));
}

LXB_API void *
lxb_css_property_perspective_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_perspective_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_perspective_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* perspective-origin. */

LXB_API void *
lxb_css_property_perspective_origin_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_perspective_origin_t));
}

LXB_API void *
lxb_css_property_perspective_origin_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_perspective_origin_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* backface-visibility. */

LXB_API void *
lxb_css_property_backface_visibility_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_backface_visibility_t));
}

LXB_API void *
lxb_css_property_backface_visibility_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_backface_visibility_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_backface_visibility_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* transition-property. */

LXB_API void *
lxb_css_property_transition_property_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transition_property_t));
}

LXB_API void *
lxb_css_property_transition_property_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transition_property_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_transition_property_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* transition-duration. */

LXB_API void *
lxb_css_property_transition_duration_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transition_duration_t));
}

LXB_API void *
lxb_css_property_transition_duration_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transition_duration_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_transition_duration_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* transition-timing-function. */

LXB_API void *
lxb_css_property_transition_timing_function_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transition_timing_function_t));
}

LXB_API void *
lxb_css_property_transition_timing_function_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transition_timing_function_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_transition_timing_function_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* transition-delay. */

LXB_API void *
lxb_css_property_transition_delay_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transition_delay_t));
}

LXB_API void *
lxb_css_property_transition_delay_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transition_delay_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_transition_delay_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* transition. */

LXB_API void *
lxb_css_property_transition_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_transition_t));
}

LXB_API void *
lxb_css_property_transition_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_transition_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_transition_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-name. */

LXB_API void *
lxb_css_property_animation_name_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_name_t));
}

LXB_API void *
lxb_css_property_animation_name_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_name_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_name_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-duration. */

LXB_API void *
lxb_css_property_animation_duration_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_duration_t));
}

LXB_API void *
lxb_css_property_animation_duration_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_duration_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_duration_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-timing-function. */

LXB_API void *
lxb_css_property_animation_timing_function_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_timing_function_t));
}

LXB_API void *
lxb_css_property_animation_timing_function_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_timing_function_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_timing_function_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-iteration-count. */

LXB_API void *
lxb_css_property_animation_iteration_count_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_iteration_count_t));
}

LXB_API void *
lxb_css_property_animation_iteration_count_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_iteration_count_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_iteration_count_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-direction. */

LXB_API void *
lxb_css_property_animation_direction_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_direction_t));
}

LXB_API void *
lxb_css_property_animation_direction_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_direction_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_direction_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-play-state. */

LXB_API void *
lxb_css_property_animation_play_state_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_play_state_t));
}

LXB_API void *
lxb_css_property_animation_play_state_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_play_state_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_play_state_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-delay. */

LXB_API void *
lxb_css_property_animation_delay_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_delay_t));
}

LXB_API void *
lxb_css_property_animation_delay_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_delay_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_delay_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation-fill-mode. */

LXB_API void *
lxb_css_property_animation_fill_mode_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_fill_mode_t));
}

LXB_API void *
lxb_css_property_animation_fill_mode_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_fill_mode_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_fill_mode_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* animation. */

LXB_API void *
lxb_css_property_animation_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_animation_t));
}

LXB_API void *
lxb_css_property_animation_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_animation_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_animation_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* list-style-type. */

LXB_API void *
lxb_css_property_list_style_type_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_list_style_type_t));
}

LXB_API void *
lxb_css_property_list_style_type_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_list_style_type_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_list_style_type_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* list-style-position. */

LXB_API void *
lxb_css_property_list_style_position_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_list_style_position_t));
}

LXB_API void *
lxb_css_property_list_style_position_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_list_style_position_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_list_style_position_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* list-style-image. */

LXB_API void *
lxb_css_property_list_style_image_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_list_style_image_t));
}

LXB_API void *
lxb_css_property_list_style_image_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_list_style_image_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_list_style_image_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* list-style. */

LXB_API void *
lxb_css_property_list_style_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_list_style_t));
}

LXB_API void *
lxb_css_property_list_style_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_list_style_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_list_style_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* border-collapse. */

LXB_API void *
lxb_css_property_border_collapse_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_collapse_t));
}

LXB_API void *
lxb_css_property_border_collapse_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_collapse_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_border_collapse_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* border-spacing. */

LXB_API void *
lxb_css_property_border_spacing_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_border_spacing_t));
}

LXB_API void *
lxb_css_property_border_spacing_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_border_spacing_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_border_spacing_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* caption-side. */

LXB_API void *
lxb_css_property_caption_side_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_caption_side_t));
}

LXB_API void *
lxb_css_property_caption_side_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_caption_side_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_caption_side_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* empty-cells. */

LXB_API void *
lxb_css_property_empty_cells_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_empty_cells_t));
}

LXB_API void *
lxb_css_property_empty_cells_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_empty_cells_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_empty_cells_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* table-layout. */

LXB_API void *
lxb_css_property_table_layout_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_table_layout_t));
}

LXB_API void *
lxb_css_property_table_layout_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_table_layout_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_table_layout_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* resize. */

LXB_API void *
lxb_css_property_resize_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_resize_t));
}

LXB_API void *
lxb_css_property_resize_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_resize_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_resize_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* caret-color. */

LXB_API void *
lxb_css_property_caret_color_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_caret_color_t));
}

LXB_API void *
lxb_css_property_caret_color_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_caret_color_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_color_serialize(style, cb, ctx);
}

/* nav-index. */

LXB_API void *
lxb_css_property_nav_index_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_nav_index_t));
}

LXB_API void *
lxb_css_property_nav_index_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_nav_index_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_nav_index_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* nav-up. */

LXB_API void *
lxb_css_property_nav_up_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_nav_up_t));
}

LXB_API void *
lxb_css_property_nav_up_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_nav_up_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_nav_up_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* nav-right. */

LXB_API void *
lxb_css_property_nav_right_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_nav_right_t));
}

LXB_API void *
lxb_css_property_nav_right_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_nav_right_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_nav_right_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* nav-down. */

LXB_API void *
lxb_css_property_nav_down_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_nav_down_t));
}

LXB_API void *
lxb_css_property_nav_down_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_nav_down_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_nav_down_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* nav-left. */

LXB_API void *
lxb_css_property_nav_left_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_nav_left_t));
}

LXB_API void *
lxb_css_property_nav_left_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_nav_left_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_nav_left_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* page-break-before. */

LXB_API void *
lxb_css_property_page_break_before_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_page_break_before_t));
}

LXB_API void *
lxb_css_property_page_break_before_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_page_break_before_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_page_break_before_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* page-break-after. */

LXB_API void *
lxb_css_property_page_break_after_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_page_break_after_t));
}

LXB_API void *
lxb_css_property_page_break_after_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_page_break_after_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_page_break_after_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* page-break-inside. */

LXB_API void *
lxb_css_property_page_break_inside_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_page_break_inside_t));
}

LXB_API void *
lxb_css_property_page_break_inside_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_page_break_inside_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_page_break_inside_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* orphans. */

LXB_API void *
lxb_css_property_orphans_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_orphans_t));
}

LXB_API void *
lxb_css_property_orphans_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_orphans_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_orphans_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* widows. */

LXB_API void *
lxb_css_property_widows_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_widows_t));
}

LXB_API void *
lxb_css_property_widows_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_widows_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_widows_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* image-orientation. */

LXB_API void *
lxb_css_property_image_orientation_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_image_orientation_t));
}

LXB_API void *
lxb_css_property_image_orientation_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_image_orientation_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_image_orientation_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* content. */

LXB_API void *
lxb_css_property_content_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_content_t));
}

LXB_API void *
lxb_css_property_content_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_content_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_content_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* quotes. */

LXB_API void *
lxb_css_property_quotes_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_quotes_t));
}

LXB_API void *
lxb_css_property_quotes_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_quotes_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_quotes_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* counter-reset. */

LXB_API void *
lxb_css_property_counter_reset_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_counter_reset_t));
}

LXB_API void *
lxb_css_property_counter_reset_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_counter_reset_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_counter_reset_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* counter-increment. */

LXB_API void *
lxb_css_property_counter_increment_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_counter_increment_t));
}

LXB_API void *
lxb_css_property_counter_increment_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_counter_increment_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_counter_increment_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* marker-offset. */

LXB_API void *
lxb_css_property_marker_offset_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_marker_offset_t));
}

LXB_API void *
lxb_css_property_marker_offset_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_marker_offset_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_marker_offset_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* appearance. */

LXB_API void *
lxb_css_property_appearance_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_appearance_t));
}

LXB_API void *
lxb_css_property_appearance_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_appearance_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_appearance_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* user-select. */

LXB_API void *
lxb_css_property_user_select_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_user_select_t));
}

LXB_API void *
lxb_css_property_user_select_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_user_select_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_user_select_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* break-before. */

LXB_API void *
lxb_css_property_break_before_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_break_before_t));
}

LXB_API void *
lxb_css_property_break_before_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_break_before_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_break_before_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* break-after. */

LXB_API void *
lxb_css_property_break_after_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_break_after_t));
}

LXB_API void *
lxb_css_property_break_after_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_break_after_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_break_after_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* break-inside. */

LXB_API void *
lxb_css_property_break_inside_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_break_inside_t));
}

LXB_API void *
lxb_css_property_break_inside_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_break_inside_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_break_inside_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* isolation. */

LXB_API void *
lxb_css_property_isolation_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_isolation_t));
}

LXB_API void *
lxb_css_property_isolation_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_isolation_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_isolation_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* mix-blend-mode. */

LXB_API void *
lxb_css_property_mix_blend_mode_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_mix_blend_mode_t));
}

LXB_API void *
lxb_css_property_mix_blend_mode_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_mix_blend_mode_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_mix_blend_mode_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* object-fit. */

LXB_API void *
lxb_css_property_object_fit_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_object_fit_t));
}

LXB_API void *
lxb_css_property_object_fit_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_object_fit_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_object_fit_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* object-position. */

LXB_API void *
lxb_css_property_object_position_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_object_position_t));
}

LXB_API void *
lxb_css_property_object_position_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_object_position_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* image-rendering. */

LXB_API void *
lxb_css_property_image_rendering_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_image_rendering_t));
}

LXB_API void *
lxb_css_property_image_rendering_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_image_rendering_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_image_rendering_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* mask-type. */

LXB_API void *
lxb_css_property_mask_type_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_mask_type_t));
}

LXB_API void *
lxb_css_property_mask_type_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_mask_type_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_mask_type_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* filter. */

LXB_API void *
lxb_css_property_filter_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_filter_t));
}

LXB_API void *
lxb_css_property_filter_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_filter_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_filter_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* overflow-clip-margin. */

LXB_API void *
lxb_css_property_overflow_clip_margin_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_overflow_clip_margin_t));
}

LXB_API void *
lxb_css_property_overflow_clip_margin_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_overflow_clip_margin_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_overflow_clip_margin_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* pointer-events. */

LXB_API void *
lxb_css_property_pointer_events_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_pointer_events_t));
}

LXB_API void *
lxb_css_property_pointer_events_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_pointer_events_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_pointer_events_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* scroll-behavior. */

LXB_API void *
lxb_css_property_scroll_behavior_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_scroll_behavior_t));
}

LXB_API void *
lxb_css_property_scroll_behavior_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_scroll_behavior_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_scroll_behavior_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* overscroll-behavior. */

LXB_API void *
lxb_css_property_overscroll_behavior_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_overscroll_behavior_t));
}

LXB_API void *
lxb_css_property_overscroll_behavior_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_overscroll_behavior_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_overscroll_behavior_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* scroll-snap-type. */

LXB_API void *
lxb_css_property_scroll_snap_type_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_scroll_snap_type_t));
}

LXB_API void *
lxb_css_property_scroll_snap_type_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_scroll_snap_type_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_scroll_snap_type_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* scroll-snap-align. */

LXB_API void *
lxb_css_property_scroll_snap_align_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_scroll_snap_align_t));
}

LXB_API void *
lxb_css_property_scroll_snap_align_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_scroll_snap_align_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_scroll_snap_align_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* scroll-margin. */

LXB_API void *
lxb_css_property_scroll_margin_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_scroll_margin_t));
}

LXB_API void *
lxb_css_property_scroll_margin_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_scroll_margin_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_scroll_margin_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* scroll-padding. */

LXB_API void *
lxb_css_property_scroll_padding_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_scroll_padding_t));
}

LXB_API void *
lxb_css_property_scroll_padding_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_scroll_padding_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    return lxb_css_value_length_percentage_sr(style, cb, ctx);
}

/* ruby-align. */

LXB_API void *
lxb_css_property_ruby_align_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_ruby_align_t));
}

LXB_API void *
lxb_css_property_ruby_align_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_ruby_align_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_ruby_align_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}

/* ruby-position. */

LXB_API void *
lxb_css_property_ruby_position_create(lxb_css_memory_t *memory)
{
    return lexbor_mraw_calloc(memory->mraw, sizeof(lxb_css_property_ruby_position_t));
}

LXB_API void *
lxb_css_property_ruby_position_destroy(lxb_css_memory_t *memory,
                                      void *style, bool self_destroy)
{
    return lxb_css_property__undef_destroy(memory, style, self_destroy);
}

LXB_API lxb_status_t
lxb_css_property_ruby_position_serialize(const void *style,
                                        lexbor_serialize_cb_f cb, void *ctx)
{
    const lxb_css_property_ruby_position_t *prop = style;
    return lxb_css_value_serialize(prop->type, cb, ctx);
}
