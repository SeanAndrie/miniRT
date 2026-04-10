/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tween_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:59:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 15:23:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

void	tween_update(t_context *ctx, const float t)
{
	t_bool trans_done;
	t_bool rot_done;

	trans_done = !ctx->tw_trans.curr
		|| ctx->tw_trans.update(&ctx->tw_trans, t);
	rot_done = !ctx->tw_rotate.curr
		|| ctx->tw_rotate.update(&ctx->tw_rotate, t);
	if (trans_done && rot_done)
		ctx->dirty = FALSE;
}
