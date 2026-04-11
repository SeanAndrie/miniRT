/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:23:43 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:13:11 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <elements/scene.h>
#include <math.h>

t_vec3	shade_specular(t_scene *scene, t_light *light, t_hit *hit, t_vec3 L_hat)
{
	t_vec3	r_hat;
	t_vec3	v_hat;
	float	scale;

	r_hat = vec3_sub(vec3_scale(hit->normal, 2.0f * vec3_dot(hit->normal,
					L_hat)), L_hat);
	v_hat = vec3_normalize(vec3_sub(scene->cam.point, hit->point));
	scale = fmaxf(0.0f, powf(vec3_dot(r_hat, v_hat), SPECULAR_SHINE));
	return (vec3_scale(light->rgb, scale * light->ratio));
}
