/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:19:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 03:38:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context.h>
#include <setup/display.h>
#include <elements/scene.h>

bool	context_init(t_context *ctx, char *fname)
{
	ctx->scene = scene_init(fname, SCENE_FILE_EXT);
	if (!ctx->scene)
		return (false);
	scene_info(ctx->scene);
    ctx->fname = fname;
	ctx->disp = display_init(W, H, TITLE);
	if (!ctx->disp)
	{
		scene_free(ctx->scene);
		return (false);
	}
    ctx->select = NULL;
    ctx->rotate = false;
	return (true);
}
