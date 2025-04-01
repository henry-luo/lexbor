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
