/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:21:48 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 21:43:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

static t_basis	sphere_basis(void)
{
	t_basis	b;

	ft_memset(&b, 0, sizeof(t_basis));
	b.right = (t_vec3){1, 0, 0};
	b.up = (t_vec3){0, 1, 0};
	b.forward = (t_vec3){0, 0, 1};
	return (b);
}

static t_basis	obj_basis(t_object *obj)
{
	t_basis	b;
	t_vec3	tmp;
	t_vec3	axis;

	ft_memset(&b, 0, sizeof(t_basis));
	if (obj->type == OBJ_SPHERE)
		return (sphere_basis());
	if (obj->type == OBJ_CYLINDER)
		axis = obj->data.cylinder.axis;
	else if (obj->type == OBJ_PLANE)
		axis = obj->data.plane.normal;
	else if (obj->type == OBJ_CONE)
		axis = obj->data.cone.axis;
	else
		axis = (t_vec3){0, 1, 0};
	if (axis.y < 0.99f && axis.y > -0.99f)
		tmp = (t_vec3){0, 1, 0};
	else
		tmp = (t_vec3){1, 0, 0};
	b.right = vec3_normalize(vec3_cross(axis, tmp));
	b.forward = vec3_cross(b.right, axis);
	b.up = axis;
	return (b);
}

static t_vec3	obj_origin(t_object *obj, t_vec3 hitp)
{
	t_vec3	p;
	t_basis	b;

	b = obj_basis(obj);
	if (obj->type == OBJ_SPHERE)
		p = vec3_sub(hitp, obj->data.sphere.center);
	else if (obj->type == OBJ_PLANE)
		p = vec3_sub(hitp, obj->data.plane.point);
	else if (obj->type == OBJ_CYLINDER)
		p = vec3_sub(hitp, obj->data.cylinder.point);
	else if (obj->type == OBJ_CONE)
		p = vec3_sub(hitp, obj->data.cone.apex);
	else
		p = hitp;
	return ((t_vec3){.x = vec3_dot(p, b.right), .y = vec3_dot(p, b.up),
		.z = vec3_dot(p, b.forward)});
}

t_vec3	shade_checker(t_hit *hit, const float scale)
{
	int		cx;
	int		cy;
	int		cz;
	t_vec3	local;

	local = obj_origin(hit->obj, hit->point);
	cx = (int)floorf(local.x * scale + 1e-4f);
	cy = (int)floorf(local.y * scale + 1e-4f);
	cz = (int)floorf(local.z * scale + 1e-4f);
	if ((cx + cy + cz) % 2 == 0)
		return (hit->rgb);
	return (vec3_scale(hit->rgb, 0.1f));
}
