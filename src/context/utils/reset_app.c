/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:21:24 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 17:51:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>
#include <core/render.h>

void	reset_app(t_context *ctx)
{
	scene_free(ctx->scene);
	ctx->scene = scene_init(ctx->fname, SCENE_FILE_EXT);
	if (!ctx->scene)
		close_app(ctx);
	context_reset(ctx);
	render_init(&ctx->pool, ctx->disp, ctx->scene);
	if (MULTITHREADED)
		render_threaded(&ctx->pool, ctx->disp, ctx->scene);
	else
		render(ctx->disp, ctx->scene);
}
