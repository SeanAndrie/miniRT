/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudabi.ae>   #+#    #+#              */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:39:47 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 04:30:25 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <math.h>

t_vec3	normal_cone(t_hit *hit, t_cone *co)
{
	float	h;
	t_project	d;
	t_project	l;
	t_vec3	p_on_axis;

	if (hit->loc == SURF_BOT)
		return (co->axis);
	l = vec3_project(vec3_sub(hit->ray.orig, co->apex), co->axis);
	d = vec3_project(hit->ray.dir, co->axis);
	h = l.axial + d.axial * hit->t;
	p_on_axis = vec3_add(co->apex, vec3_scale(co->axis, h * (1.0f + co->k2)));
	return (vec3_normalize(vec3_sub(hit->point, p_on_axis)));
}
