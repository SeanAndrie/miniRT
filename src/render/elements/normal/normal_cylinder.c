/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:13:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 21:26:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <math.h>

t_vec3	normal_cylinder(t_vec3 point, t_cylinder *cy, float t)
{
	float	h;
	t_vec3	p_on_axis;

	if (cy->hit_loc == SURF_TOP)
		return (cy->axis);
	if (cy->hit_loc == SURF_BOT)
		return (vec3_neg(cy->axis));
	h = cy->l.axial + cy->d.axial * t;
	p_on_axis = vec3_add(cy->point, vec3_scale(cy->axis, h));
	return (vec3_normalize(vec3_sub(point, p_on_axis)));
}
