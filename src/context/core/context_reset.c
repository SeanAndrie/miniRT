/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:58:18 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 16:02:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

void	context_reset(t_context *ctx)
{
	if (!ctx)
		return ;
	ctx->s_obj = NULL;
	ctx->s_lgt = NULL;
	ctx->extend = FALSE;
	ctx->property = FALSE;
	ctx->dirty = TRUE;
	ctx->tw_trans = tween_translation(&ctx->scene->cam.point);
	ctx->tw_rotate.target = ctx->scene->cam.basis.forward;
	ctx->tw_rotate.curr = NULL;
	ctx->tw_rotate.target = ctx->scene->cam.basis.forward;
}
