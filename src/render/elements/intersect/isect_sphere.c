/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isect_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:46:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 12:28:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

float	isect_sphere(t_ray *ray, t_sphere *sp)
{
	t_vec3	L;
	float	t0;
	float	t1;
	t_vec3	quad;
	float	disc;

	L = vec3_sub(ray->orig, sp->center);
	quad.x = vec3_dot(ray->dir, ray->dir);
	quad.y = 2.0f * vec3_dot(ray->dir, L);
	quad.z = vec3_dot(L, L) - (sp->radius * sp->radius);
	disc = (quad.y * quad.y) - (4.0f * quad.x * quad.z);
	if (disc < 0.0f)
		return (0.0f);
	t0 = (-quad.y - sqrtf(disc)) / (2.0f * quad.x);
	t1 = (-quad.y + sqrtf(disc)) / (2.0f * quad.x);
	if (t0 > 1e-4f)
		return (t0);
	else if (t1 > 1e-4f)
		return (t1);
	return (0.0f);
}
