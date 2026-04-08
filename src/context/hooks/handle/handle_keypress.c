/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:47:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/08 03:49:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <core/render.h>
#include <libtensr_rt.h>
#include <core/context.h>

static void handle_movement(int key_code, t_context *ctx)
{
    ctx->dirty = true;
    if (ctx->extend)
        dispatch_rotate(key_code, ctx);
    else
        dispatch_translate(key_code, ctx);
}

static void handle_property(int key_code, t_context *ctx)
{
    ctx->dirty = true;
    if (!ctx->s_obj)
        return ;
    dispatch_property(key_code, ctx);
}

static void handle_light_cycle(t_context *ctx)
{
    ctx->s_obj = NULL;
    ctx->s_obj = NULL;
    ctx->s_lgt = ((t_light **)ctx->scene->lgt_view.data)[ctx->next_i];
    ctx->next_i = (ctx->next_i + 1) % ctx->scene->lgt_view.len;
    ctx->tw_trans = tween_translation(&ctx->s_lgt->point);
    if (ctx->show_ui)
        ctx->dirty = true;
}

int	handle_keypress(int key_code, t_context *ctx)
{
    if (key_code == XK_ESC)
        return (close_app(ctx), 0);
    if (!ctx->property && key_code == XK_R)
        return (reset_app(ctx), 0);
    if (key_code == XK_SHIFT_L)
        ctx->extend = true;
    if (key_code == XK_P)
    {
        ctx->property ^= 1;
        if (ctx->show_ui)
            ctx->dirty = true;
    }
    if (key_code == XK_U)
    {
        ctx->show_ui ^= 1;
        ctx->dirty = true;
    }
    if (!ctx->property && movement_keys(key_code))
        handle_movement(key_code, ctx);
    if (ctx->property && property_keys(key_code))
        handle_property(key_code, ctx);
    if (ctx->extend && key_code == XK_L)
        handle_light_cycle(ctx);
    return (0);
}
