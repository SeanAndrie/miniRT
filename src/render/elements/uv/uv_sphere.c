/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:31:35 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/24 07:55:33 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

void	uv_sphere(t_hit *hit)
{
	t_vec3	n;

	n = hit->normal;
	hit->u = atan2(n.z, n.x) / (2.0 * M_PI) + 0.5f;
	hit->v = asin(n.y) / M_PI + 0.5f;
	hit->tangent = vec3_normalize((t_vec3){-n.z, 0, n.x});
	hit->bitangent = vec3_cross(hit->normal, hit->tangent);
}
