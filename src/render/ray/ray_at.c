/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:25:42 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 12:28:02 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

t_vec3 ray_at(t_ray ray, float t)
{
    return (vec3_add(ray.orig, vec3_scale(ray.dir, t)));
}
