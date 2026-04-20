/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_property.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:10:33 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 13:10:14 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>
#include <math.h>

static void	modify_property(float *v_ptr, t_bool extend)
{
	if (extend)
	{
		if ((*v_ptr - PROP_INCREMENT) < 0.2f)
			return ;
		*v_ptr -= PROP_INCREMENT;
	}
	else
		*v_ptr += PROP_INCREMENT;
}

void	dispatch_property(int key_code, t_context *ctx)
{
	if (ctx->s_obj->type == OBJ_SPHERE)
	{
		if (key_code == XK_R)
			modify_property(&ctx->s_obj->data.sphere.radius, ctx->extend);
	}
	if (ctx->s_obj->type == OBJ_CYLINDER)
	{
		if (key_code == XK_H)
			modify_property(&ctx->s_obj->data.cylinder.height, ctx->extend);
		if (key_code == XK_R)
			modify_property(&ctx->s_obj->data.cylinder.radius, ctx->extend);
	}
	if (ctx->s_obj->type == OBJ_CONE)
	{
		if (key_code == XK_H)
			modify_property(&ctx->s_obj->data.cone.height, ctx->extend);
		if (key_code == XK_T)
		{
			modify_property(&ctx->s_obj->data.cone.theta, ctx->extend);
			ctx->s_obj->data.cone.k = tanf(ctx->s_obj->data.cone.theta * (M_PI
						/ 180.0f));
			ctx->s_obj->data.cone.k2 = ctx->s_obj->data.cone.k
				* ctx->s_obj->data.cone.k;
		}
	}
}
