/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 02:46:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 17:35:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

static void	rodrigues_rotate(t_vec3 *v, t_vec3 ax, float angle)
{
	t_vec3	c1;
	t_vec3	c2;
	t_vec3	div;
	float	c;

	c = cosf(angle);
	div = vec3_cross(ax, *v);
	c1 = vec3_scale(div, sinf(angle));
	c2 = vec3_scale(vec3_cross(ax, div), (1 - c));
	vec3_scale_ip(v, c);
	vec3_add_ip(v, vec3_add(c1, c2));
}

static void rotate_camera(int key_code, t_basis *b, float angle)
{
    if (key_code == XK_w || key_code == XK_s)
    {
        rodrigues_rotate(&b->forward, b->right, angle);
        rodrigues_rotate(&b->up, b->right, angle);
    }
    else if (key_code == XK_a || key_code == XK_d)
    {
        rodrigues_rotate(&b->forward, b->up, angle);
        rodrigues_rotate(&b->right, b->up, angle);
    }
    else if (key_code == XK_q || key_code == XK_e)
    {
        rodrigues_rotate(&b->right, b->forward, angle);
        rodrigues_rotate(&b->up, b->forward, angle);
    }
    vec3_normalize_ip(&b->forward);
    vec3_normalize_ip(&b->right);
    vec3_normalize_ip(&b->up);
}

static void rotate_object(t_object *obj, t_basis *basis, int key_code, float angle)
{
    if (obj->type == OBJ_CYLINDER)
    {
        if (key_code == XK_w || key_code == XK_s)
            rodrigues_rotate(&obj->data.cylinder.axis, basis->right, angle);
        else if (key_code == XK_a || key_code == XK_d)
            rodrigues_rotate(&obj->data.cylinder.axis, basis->up, angle);
        else if (key_code == XK_q || key_code == XK_e)
            rodrigues_rotate(&obj->data.cylinder.axis, basis->forward, angle);
        vec3_normalize_ip(&obj->data.cylinder.axis);
    }
    else if (obj->type == OBJ_CONE)
    {
        if (key_code == XK_w || key_code == XK_s)
            rodrigues_rotate(&obj->data.cone.axis, basis->right, angle);
        else if (key_code == XK_a || key_code == XK_d)
            rodrigues_rotate(&obj->data.cone.axis, basis->up, angle);
        else if (key_code == XK_q || key_code == XK_e)
            rodrigues_rotate(&obj->data.cone.axis, basis->forward, angle);
        vec3_normalize_ip(&obj->data.cone.axis);
    }
}

void	dispatch_rotate(int key_code, t_context *ctx)
{
	t_object	*obj;
	float		angle;
    t_basis     *basis;

	if (key_code == XK_w || key_code == XK_a || key_code == XK_q)
		angle = ROTATE_ANGLE;
	else if (key_code == XK_s || key_code == XK_d || key_code == XK_e)
		angle = -ROTATE_ANGLE;
	else
		return ;
	obj = ctx->s_obj;
    basis = &ctx->scene->cam.basis;
    if (!obj)
        rotate_camera(key_code, basis, angle);
    else
        rotate_object(obj, basis, key_code, angle);
}
