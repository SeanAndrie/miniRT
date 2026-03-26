/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:23:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 13:15:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <core/context.h>

static int close_app(t_context *ctx)
{
    context_free(ctx);
    exit(EXIT_SUCCESS);
    return (0);
}

void	context_hooks(t_context *ctx)
{
	mlx_hook(ctx->disp->window, KeyPress, KeyPressMask, handle_keypress, ctx);
    mlx_hook(ctx->disp->window, ButtonPress, ButtonPressMask, handle_mousepress, ctx);
	mlx_hook(ctx->disp->window, DestroyNotify, 0, close_app, ctx);
}
