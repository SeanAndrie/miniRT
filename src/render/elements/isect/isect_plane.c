/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isect_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 00:31:04 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/09 03:12:13 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

float	isect_plane(t_ray *ray, t_plane *pl)
{
	float	t;
	float	denom;

	denom = vec3_dot(ray->dir, pl->normal);
	if (denom > -1e-6f)
    	return (0.0f);
	if (fabsf(denom) < 1e-6f)
		return (0.0f);
	t = vec3_dot(vec3_sub(pl->point, ray->orig), pl->normal) / denom;
	if (t < 1e-4f)
		return (0.0f);
	return (t);
}
