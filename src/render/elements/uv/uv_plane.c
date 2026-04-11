/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 00:14:12 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/11 23:31:34 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

void	uv_plane(t_hit *hit)
{
	t_plane	*pl;
	t_vec3	T;
	t_vec3	B;
	float	scale;

	pl = &hit->obj->data.plane;
	if (fabs(pl->normal.y) < 0.999)
		T = vec3_normalize(vec3_cross((t_vec3){0, 1, 0}, pl->normal));
	else
		T = vec3_normalize(vec3_cross((t_vec3){1, 0, 0}, pl->normal));
	B = vec3_cross(pl->normal, T);
	hit->tangent = T;
	hit->bitangent = B;
	scale = 0.2f;
	hit->u = vec3_dot(hit->point, T) * scale;
	hit->v = vec3_dot(hit->point, B) * scale;
}
