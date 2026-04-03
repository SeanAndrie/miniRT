/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 02:46:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 18:02:37 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

static void	rodrigues_rotate(t_vec3 *v, t_vec3 ax, float angle)
{
	float	c;
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	div;

	c = cosf(angle);
	div = vec3_cross(ax, *v);
	c1 = vec3_scale(div, sinf(angle));
	c2 = vec3_scale(vec3_cross(ax, div), (1 - c));
	vec3_scale_ip(v, c);
	vec3_add_ip(v, vec3_add(c1, c2));
}

static t_vec3	rotation_axis(int key_code, t_basis *b)
{
	if (key_code == XK_W || key_code == XK_S)
		return (b->right);
	else if (key_code == XK_A || key_code == XK_D)
		return (b->up);
	return (b->forward);
}

static void	handle_rotation(int key_code, t_context *ctx, t_basis *b,
		const float angle)
{
	t_vec3	ax;

	ax = rotation_axis(key_code, b);
	if (!ctx->s_obj)
	{
		if (!ctx->tw_rotate.curr)
			ctx->tw_rotate = tween_rotation(&ctx->scene->cam.basis.forward);
	}
	else if (ctx->s_obj->type == OBJ_CYLINDER)
	{
		if (!ctx->tw_rotate.curr)
			ctx->tw_rotate = tween_rotation(&ctx->s_obj->data.cylinder.axis);
	}
	else if (ctx->s_obj->type == OBJ_CONE)
	{
		if (!ctx->tw_rotate.curr)
			ctx->tw_rotate = tween_rotation(&ctx->s_obj->data.cone.axis);
	}
	else
		return ;
	ctx->tw_rotate.target = *ctx->tw_rotate.curr;
	rodrigues_rotate(&ctx->tw_rotate.target, ax, angle);
}

void	dispatch_rotate(int key_code, t_context *ctx)
{
	float	angle;

	if (key_code == XK_W || key_code == XK_A || key_code == XK_Q)
		angle = -ROTATE_ANGLE;
	else if (key_code == XK_S || key_code == XK_D || key_code == XK_E)
		angle = ROTATE_ANGLE;
	else
		return ;
	handle_rotation(key_code, ctx, &ctx->scene->cam.basis, angle);
}
