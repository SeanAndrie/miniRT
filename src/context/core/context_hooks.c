/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:23:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/04 00:56:35 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>
#include <mlx.h>

static int	on_loop(t_context *ctx)
{
	if (!ctx->dirty)
		return (0);
	if (!ctx->tw_trans.curr && !ctx->tw_rotate.curr)
		return (0);
	tween_update(ctx, TWEEN_FACTOR);
	if (MULTITHREADED)
		render_threaded(&ctx->pool, ctx->disp, ctx->scene);
	else
		render(ctx->disp, ctx->scene);
	return (0);
}

void	context_hooks(t_context *ctx)
{
	mlx_hook(ctx->disp->window, EVENT_KEYPRESS, MASK_KEYPRESS, handle_keypress,
		ctx);
	mlx_hook(ctx->disp->window, EVENT_KEYRELEASE, MASK_KEYRELEASE,
		handle_keyrelease, ctx);
	mlx_hook(ctx->disp->window, EVENT_BUTTONPRESS, MASK_BUTTONPRESS,
		handle_mousepress, ctx);
	mlx_hook(ctx->disp->window, EVENT_DESTROYNOTIFY, 0, close_app, ctx);
	mlx_loop_hook(ctx->disp->conn, on_loop, ctx);
}
