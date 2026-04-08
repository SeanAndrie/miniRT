/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 01:19:48 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/08 03:45:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

int	context_loop(t_context *ctx)
{
	if (!ctx->dirty)
		return (0);
	if (!ctx->tw_trans.curr && !ctx->tw_rotate.curr)
		return (0);
	tween_update(ctx, TWEEN_FACTOR);
	if (ctx->show_ui)
		mlx_clear_window(ctx->disp->conn, ctx->disp->window);
	if (MULTITHREADED)
		render_threaded(&ctx->pool, ctx->disp, ctx->scene);
	else
		render(ctx->disp, ctx->scene);
	if (ctx->show_ui)
		interface_render(ctx, LINE_HEIGHT);
	return (0);
}
