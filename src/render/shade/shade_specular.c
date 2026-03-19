/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:23:43 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 16:44:21 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <core/render.h>

t_vec3  shade_specular(t_scene *scene, t_hit *hit, t_vec3 L_hat, float shine)
{
    t_vec3  R_hat;
    t_vec3  V_hat;
    float   scale;
    
    R_hat = vec3_sub(vec3_scale(hit->normal, 2.0f * vec3_dot(hit->normal, L_hat)), L_hat);
    V_hat = vec3_normalize(vec3_sub(scene->cam.point, hit->point));
    scale = fmaxf(0.0f, powf(vec3_dot(R_hat, V_hat), shine));
    return (vec3_scale(scene->light.rgb, scale * scene->light.ratio));
}
