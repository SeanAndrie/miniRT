/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:46:21 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/11 23:39:05 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

void	uv_cylinder(t_hit *hit)
{
	t_cylinder *cy;
	t_vec3 base;
	t_vec3 radial;
	t_vec3 up;
	float height;

	cy = &hit->obj->data.cylinder;
	base = vec3_sub(cy->point, vec3_scale(cy->axis, cy->height * 0.5f));
	height = vec3_dot(vec3_sub(hit->point, base), cy->axis);
	radial = vec3_sub(vec3_sub(hit->point, base), vec3_scale(cy->axis, height));
	if (fabs(cy->axis.y) < 0.999)
		up = (t_vec3){0, 1, 0};
	else
		up = (t_vec3){1, 0, 0};
	hit->tangent = vec3_normalize(vec3_cross(up, cy->axis));
	hit->bitangent = vec3_cross(cy->axis, hit->tangent);
	hit->u = fmodf(atan2f(vec3_dot(radial, hit->bitangent), vec3_dot(radial,
				hit->tangent)) / (2.0f * M_PI) + 1.0f, 1.0f);
	hit->v = height / (2.0f * M_PI * cy->radius);
}
