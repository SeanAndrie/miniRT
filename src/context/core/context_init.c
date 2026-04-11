/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:19:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/11 01:37:13 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context.h>
#include <elements/scene.h>
#include <setup/display.h>
#include <setup/texture.h>

bool	context_init(t_context *ctx, char *fname)
{
	ctx->scene = scene_init(fname, SCENE_FILE_EXT);
	if (!ctx->scene)
		return (false);
	ctx->fname = fname;
	ctx->disp = display_init(W, H);
	if (!ctx->disp)
	{
		scene_free(ctx->scene);
		return (false);
	}
	texture_init(ctx);
	ctx->next_i = 0;
	ctx->s_obj = NULL;
	ctx->s_lgt = NULL;
	ctx->extend = false;
	ctx->property = false;
	ctx->dirty = true;
	ctx->tw_trans = tween_translation(&ctx->scene->cam.point);
	ctx->tw_rotate.curr = NULL;
	ctx->tw_rotate.target = ctx->scene->cam.basis.forward;
	ctx->tw_rotate.update = tween_slerp_update;
	return (true);
}
