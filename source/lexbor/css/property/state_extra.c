#include "lexbor/css/property.h"
#include "lexbor/css/parser.h"
#include "lexbor/css/rule.h"
#include "lexbor/css/value.h"
#include "lexbor/css/unit.h"
#include "lexbor/css/property/state.h"
#include "lexbor/css/property/res.h"

#define lxb_css_property_state_check_token(parser, token)                     \
    if ((token) == NULL) {                                                    \
        return lxb_css_parser_memory_fail(parser);                            \
    }

bool lxb_css_property_state_length_percentage(lxb_css_parser_t *parser,
    const lxb_css_syntax_token_t *token, lxb_css_value_length_percentage_t *lp);

bool lxb_css_property_state_box_shadow(lxb_css_parser_t *parser, const lxb_css_syntax_token_t *token, void *ctx) {
    // lxb_css_property_box_shadow_t *property = lxb_css_parser_create_property_placeholder(parser, offsetof(lxb_css_property_t, box_shadow));
    // if (property == NULL) {
    //     return lxb_css_parser_memory_fail(parser);
    // }

    // lxb_css_syntax_token_t *ident;
    // const lxb_char_t *name;
    // size_t length;

    // if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
    //     ident = token;
    //     name = lxb_css_syntax_token_ident_data(ident);
    //     length = lxb_css_syntax_token_ident_length(ident);
    //     if (lxb_css_property_state_eq(name, length, "none", 4)) {
    //         property->type = LXB_CSS_BOX_SHADOW_NONE;
    //     }
    //     else if (lxb_css_property_state_eq(name, length, "inset", 5)) {
    //         property->type = LXB_CSS_BOX_SHADOW_INSET;
    //     }
    //     else {
    //         lxb_css_parser_warning(parser, LXB_CSS_PARSER_WARNING_PROPERTY_INVALID_VALUE, token);
    //         lxb_css_parser_destroy_property_placeholder(parser);
    //         return lxb_css_parser_state_element_skip_to_semicolonp;
    //     }
    // }
    // else {
    //     lxb_css_parser_warning(parser, LXB_CSS_PARSER_WARNING_PROPERTY_INVALID_VALUE, token);
    //     lxb_css_parser_destroy_property_placeholder(parser);
    //     return lxb_css_parser_state_element_skip_to_semicolonp;
    // }

    // *out_token = lxb_css_parser_token_consume(parser);
    // return lxb_css_parser_state_element_return_to_parent;
}

bool lxb_css_property_state_border_radius(lxb_css_parser_t *parser, const lxb_css_syntax_token_t *token, void *ctx) {
    lxb_css_rule_declaration_t *declar = ctx;
    lxb_css_value_type_t type;
    lxb_css_value_length_percentage_t *prop;
    unsigned int state = 1;  bool with_auto = false;
NEXT:
    switch (state) {
    case 1:
        prop = &declar->u.border_radius->top_left;
        break;
    case 2:
        prop = &declar->u.border_radius->top_right;
        break;
    case 3:
        prop = &declar->u.border_radius->bottom_right;
        break;
    case 4:
        prop = &declar->u.border_radius->bottom_left;
        break;
    default:
        return lxb_css_parser_failed(parser);
    }
    if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
        type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
            lxb_css_syntax_token_ident(token)->length);
        switch (type) {
            case LXB_CSS_VALUE_INITIAL:
            case LXB_CSS_VALUE_INHERIT:
            case LXB_CSS_VALUE_UNSET:
            case LXB_CSS_VALUE_REVERT:
                prop->type = type;
                break;
            case LXB_CSS_VALUE_AUTO:
                if (with_auto) {
                    prop->type = type;
                    break;
                }
                /* Fall through. */
            default:
                return lxb_css_parser_failed(parser);
        }

        lxb_css_syntax_parser_consume(parser);
    }
    else if (!lxb_css_property_state_length_percentage(parser, token,
        (lxb_css_value_length_percentage_t *) prop)) {
        return lxb_css_parser_failed(parser);
    }

    token = lxb_css_syntax_parser_token_wo_ws(parser);
    lxb_css_property_state_check_token(parser, token);
    if (token->type == LXB_CSS_SYNTAX_TOKEN__END) {
        return lxb_css_parser_success(parser);
    }

    state++;
    goto NEXT;
}
