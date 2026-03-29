/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_translate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 02:43:56 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 17:40:16 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

static void	handle_translate(int key_code, t_vec3 *v, t_basis *b)
{
	if (key_code == XK_w)
		vec3_add_ip(v, vec3_scale(b->forward, TRANS_SPEED));
	else if (key_code == XK_s)
		vec3_add_ip(v, vec3_scale(b->forward, -TRANS_SPEED));
	else if (key_code == XK_a)
		vec3_add_ip(v, vec3_scale(b->right, -TRANS_SPEED));
	else if (key_code == XK_d)
		vec3_add_ip(v, vec3_scale(b->right, TRANS_SPEED));
	else if (key_code == XK_q)
		vec3_add_ip(v, vec3_scale(b->up, TRANS_SPEED));
	else if (key_code == XK_e)
		vec3_add_ip(v, vec3_scale(b->up, -TRANS_SPEED));
}

void	dispatch_translate(int key_code, t_context *ctx)
{
	t_object	*obj;
	t_camera	*cam;
	t_basis		*basis;

	obj = ctx->s_obj;
	cam = &ctx->scene->cam;
	basis = &ctx->scene->cam.basis;
	if (!obj)
	{
		if (ctx->s_lgt)
			handle_translate(key_code, &ctx->s_lgt->point, basis);
		else
			handle_translate(key_code, &cam->point, basis);
		return ;
	}
	if (obj->type == OBJ_SPHERE)
		handle_translate(key_code, &obj->data.sphere.center, basis);
	else if (obj->type == OBJ_PLANE)
		handle_translate(key_code, &obj->data.plane.point, basis);
	else if (obj->type == OBJ_CYLINDER)
		handle_translate(key_code, &obj->data.cylinder.point, basis);
	else if (obj->type == OBJ_CONE)
		handle_translate(key_code, &obj->data.cone.apex, basis);
}
