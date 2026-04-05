/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:23:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/06 01:20:56 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>
#include <mlx.h>

void	context_hooks(t_context *ctx)
{
	mlx_hook(ctx->disp->window, EVENT_KEYPRESS, MASK_KEYPRESS, handle_keypress,
		ctx);
	mlx_hook(ctx->disp->window, EVENT_KEYRELEASE, MASK_KEYRELEASE,
		handle_keyrelease, ctx);
	mlx_hook(ctx->disp->window, EVENT_BUTTONPRESS, MASK_BUTTONPRESS,
		handle_mousepress, ctx);
	mlx_hook(ctx->disp->window, EVENT_DESTROYNOTIFY, 0, close_app, ctx);
	mlx_loop_hook(ctx->disp->conn, context_loop, ctx);
}
