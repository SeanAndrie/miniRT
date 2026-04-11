/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:31:35 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/10 23:36:09 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

void	uv_sphere(t_hit *hit)
{
	t_sphere	*sp;
	t_vec3		n;

	sp = &hit->obj->data.sphere;
	n = vec3_normalize(vec3_sub(hit->point, sp->center));
	hit->u = 0.5 + atan2(n.z, n.x) / (2.0 * M_PI) + 0.3;
	hit->v = 1.0 - (0.5 - asin(n.y) / M_PI);
	hit->tangent = vec3_normalize((t_vec3){-n.z, 0, n.x});
	hit->bitangent = vec3_cross(hit->normal, hit->tangent);
}
