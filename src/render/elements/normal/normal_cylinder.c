/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:13:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 04:30:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <math.h>

t_vec3	normal_cylinder(t_hit *hit, t_cylinder *cy)
{
	float		h;
	t_project	d;
	t_project	l;
	t_vec3		p_on_axis;

	if (hit->loc == SURF_TOP)
		return (cy->axis);
	if (hit->loc == SURF_BOT)
		return (vec3_neg(cy->axis));
	l = vec3_project(vec3_sub(hit->ray.orig, cy->point), cy->axis);
	d = vec3_project(hit->ray.dir, cy->axis);
	h = l.axial + d.axial * hit->t;
	p_on_axis = vec3_add(cy->point, vec3_scale(cy->axis, h));
	return (vec3_normalize(vec3_sub(hit->point, p_on_axis)));
}
