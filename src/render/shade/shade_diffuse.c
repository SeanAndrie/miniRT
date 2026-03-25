/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:51:52 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 21:08:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <float.h>

t_vec3	shade_diffuse(float ratio, t_vec3 light_rgb, t_hit *hit, t_vec3 L_hat)
{
	float	lambert;

	lambert = fmaxf(0.0f, vec3_dot(hit->normal, L_hat));
	return (vec3_scale(vec3_mul(hit->rgb, light_rgb), lambert * ratio));
}
