/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_diffuse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:51:52 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 16:40:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <core/render.h>

t_vec3  shade_diffuse(t_light *light, t_hit *hit, t_vec3 L_hat)
{
    float   lambert;

    lambert = fmaxf(0.0f, vec3_dot(hit->normal, L_hat));
    return (vec3_scale(vec3_mul(hit->rgb, light->rgb), lambert * light->ratio));
}
