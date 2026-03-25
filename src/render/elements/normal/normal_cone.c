/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudabi.ae>   #+#    #+#              */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:39:47 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 21:26:31 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <math.h>

t_vec3	normal_cone(t_vec3 point, t_cone *co, float t)
{
	float	h;
	t_vec3	p_on_axis;

	if (co->hit_loc == SURF_BOT)
		return (co->axis);
	h = co->l.axial + co->d.axial * t;
	p_on_axis = vec3_add(co->apex, vec3_scale(co->axis, h * (1.0f + co->k2)));
	return (vec3_normalize(vec3_sub(point, p_on_axis)));
}
