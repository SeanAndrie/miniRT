/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 00:14:12 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/12 01:57:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

void	uv_plane(t_hit *hit)
{
	t_plane	*pl;
	t_vec3	t;
	t_vec3	b;
	float	scale;

	pl = &hit->obj->data.plane;
	if (fabs(pl->normal.y) < 0.999)
		t = vec3_normalize(vec3_cross((t_vec3){0, 1, 0}, pl->normal));
	else
		t = vec3_normalize(vec3_cross((t_vec3){1, 0, 0}, pl->normal));
	b = vec3_cross(pl->normal, t);
	hit->tangent = t;
	hit->bitangent = b;
	scale = 0.2f;
	hit->u = vec3_dot(hit->point, t) * scale;
	hit->v = vec3_dot(hit->point, b) * scale;
}
