/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_translate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 02:43:56 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 14:38:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

static void	handle_translate(int key_code, t_tween *tw, t_basis *b)
{
	if (!tw->curr)
		return ;
	tw->target = *tw->curr;
	if (key_code == XK_W)
		vec3_add_ip(&tw->target, vec3_scale(b->forward, TRANS_SPEED));
	else if (key_code == XK_S)
		vec3_add_ip(&tw->target, vec3_scale(b->forward, -TRANS_SPEED));
	else if (key_code == XK_A)
		vec3_add_ip(&tw->target, vec3_scale(b->right, -TRANS_SPEED));
	else if (key_code == XK_D)
		vec3_add_ip(&tw->target, vec3_scale(b->right, TRANS_SPEED));
	else if (key_code == XK_Q)
		vec3_add_ip(&tw->target, vec3_scale(b->up, TRANS_SPEED));
	else if (key_code == XK_E)
		vec3_add_ip(&tw->target, vec3_scale(b->up, -TRANS_SPEED));
}

void	dispatch_translate(int key_code, t_context *ctx)
{
	t_basis	*basis;

	basis = &ctx->scene->cam.basis;
	handle_translate(key_code, &ctx->tw_trans, basis);
}
