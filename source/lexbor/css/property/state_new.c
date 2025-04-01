/*
 * Copyright (C) 2018-2023 Alexander Borisov
 *
 * Author: Alexander Borisov <borisov@lexbor.com>
 */

#include "lexbor/css/property/state.h"
#include "lexbor/css/syntax/parser.h"
#include "lexbor/css/syntax/state.h"
#include "lexbor/css/value.h"

/* Auto-generated code for CSS property parsers */

/* Property: border-radius */
bool
lxb_css_property_state_border_radius_repeat(lxb_css_parser_t *parser,
        const lxb_css_syntax_token_t *token, void *ctx)
{
    bool status;
    size_t count = 0;
    lxb_css_rule_declaration_t *declar = ctx;
    lxb_css_syntax_token_t *saved_token;
    lxb_css_parser_state_t *saved_state;
    /* Save current parser state */
    saved_token = lxb_css_syntax_parser_token(parser);
    saved_state = lxb_css_parser_state(parser);
    
    /* Attempt to parse the repetition pattern */
    while (true) {
        /* Stop if we've reached the maximum allowed repetitions */
        if (count >= 4) {
            break;
        }
        
        /* Try to parse the value */
        
        status = lxb_css_property_state_length_percentage(parser, token,
                                    (lxb_css_value_length_percentage_t *)&declar->u.border_radius->values[count]);
        
        if (!status) {
            break;
        }
        
        count++;
        token = lxb_css_syntax_parser_token(parser);
        
    }
    
    /* Check if we've met the minimum repetition requirement */
    if (count < 1) {
        /* Restore original parser state */
        lxb_css_parser_state_set(parser, saved_state);
        lxb_css_syntax_parser_token_set(parser, saved_token);
        return false;
    }
    
    /* Update property structure with the number of values */
    declar->u.border_radius->count = count;
    declar->u.border_radius->type = LXB_CSS_VALUE__LIST;
    
    return true;
}

bool
lxb_css_property_state_border_radius(lxb_css_parser_t *parser,
                             const lxb_css_syntax_token_t *token, void *ctx)
{
    lxb_css_value_type_t type;
    lxb_css_rule_declaration_t *declar = ctx;

    /* Handle global values first */
    if (token->type == LXB_CSS_SYNTAX_TOKEN_IDENT) {
        type = lxb_css_value_by_name(lxb_css_syntax_token_ident(token)->data,
                                    lxb_css_syntax_token_ident(token)->length);
        switch (type) {
            /* Global. */
            case LXB_CSS_VALUE_INITIAL:
            case LXB_CSS_VALUE_INHERIT:
            case LXB_CSS_VALUE_UNSET:
            case LXB_CSS_VALUE_REVERT:
                declar->u.border_radius->type = type;
                lxb_css_syntax_parser_consume(parser);
                return lxb_css_parser_success(parser);
            default:
                break;
        }
    }

    /* Try to parse the repeating pattern */
    if (lxb_css_property_state_border_radius_repeat(parser, token, declar)) {
        return lxb_css_parser_success(parser);
    }

    return lxb_css_parser_failed(parser);
}