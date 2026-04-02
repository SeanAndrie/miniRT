/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:47:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 03:43:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <core/render.h>
#include <libtensr_rt.h>
#include <core/context.h>

static void handle_movement(int key_code, t_context *ctx)
{
    if (ctx->extend)
        dispatch_rotate(key_code, ctx);
    else
        dispatch_translate(key_code, ctx);
    render(&ctx->pool, ctx->disp, ctx->scene);
}

static void handle_property(int key_code, t_context *ctx)
{
    if (!ctx->s_obj)
        return ;
    dispatch_property(key_code, ctx);
    render(&ctx->pool, ctx->disp, ctx->scene);
}

int	handle_keypress(int key_code, t_context *ctx)
{
    if (key_code == XK_Esc)
        return (close_app(ctx), 0);
    if (!ctx->property && key_code == XK_r)
        return (reset_app(ctx), 0);
    if (key_code == XK_Shift_L)
        ctx->extend = true;
    if (key_code == XK_p)
        ctx->property ^= 1;
    if (!ctx->property && movement_keys(key_code))
        handle_movement(key_code, ctx);
    if (ctx->property && property_keys(key_code))
        handle_property(key_code, ctx);
    if (ctx->extend && key_code == XK_l)
    {
        ctx->s_obj = NULL;
        ctx->s_lgt = ((t_light **)ctx->scene->lgt_view.data)[ctx->next_i];
        ctx->next_i = (ctx->next_i + 1) % ctx->scene->lgt_view.len;
    }
    return (0);
}
