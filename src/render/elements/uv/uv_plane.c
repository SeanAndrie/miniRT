/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 00:14:12 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/24 07:55:26 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

void	uv_plane(t_hit *hit)
{
	t_plane	*pl;
	float	scale;

	pl = &hit->obj->data.plane;
	if (fabs(pl->normal.y) < 0.999)
		hit->tangent = vec3_normalize(vec3_cross((t_vec3){0, 1, 0},
					pl->normal));
	else
		hit->tangent = vec3_normalize(vec3_cross((t_vec3){1, 0, 0},
					pl->normal));
	hit->bitangent = vec3_cross(pl->normal, hit->tangent);
	scale = 0.2f;
	hit->u = vec3_dot(hit->point, hit->tangent) * scale;
	hit->v = vec3_dot(hit->point, hit->bitangent) * scale;
}
