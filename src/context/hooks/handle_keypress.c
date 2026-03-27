/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:47:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 04:06:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>
#include <core/render.h>
#include <libtensr_rt.h>
#include <math.h>
#include <mlx.h>

static bool	translate_keys(int key_code)
{
	return (key_code == XK_a || key_code == XK_s || key_code == XK_w
		|| key_code == XK_d || key_code == XK_q || key_code == XK_e);
}

static void	close_app(t_context *ctx)
{
	context_free(ctx);
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int key_code, t_context *ctx)
{
	if (key_code == XK_Esc)
		return (close_app(ctx), 0);
	if (key_code == XK_r)
	{
		scene_free(ctx->scene);
		ctx->scene = scene_init(ctx->fname, SCENE_FILE_EXT);
		if (!ctx->scene)
			close_app(ctx);
		render_init(ctx->disp, ctx->scene);
		render(ctx->disp, ctx->scene);
	}
	if (key_code == XK_Shift_L)
		ctx->rotate = true;
	if (translate_keys(key_code))
	{
		if (ctx->rotate)
			dispatch_rotate(key_code, ctx);
		else
			dispatch_translate(key_code, ctx);
		render(ctx->disp, ctx->scene);
	}
	return (0);
}
