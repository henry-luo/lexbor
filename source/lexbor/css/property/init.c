#include "lexbor/css/property/property_extra.h"

lxb_status_t
lxb_css_property_state_init(lxb_css_parser_t *parser)
{
    lxb_status_t status;

    /* Initialize extra properties */
    status = lxb_css_property_state_init_extra(parser);
    if (status != LXB_STATUS_OK) {
        return status;
    }

    return LXB_STATUS_OK;
}