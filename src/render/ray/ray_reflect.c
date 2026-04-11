/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_reflect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 16:07:11 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/05 16:10:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

t_vec3	ray_reflect(t_vec3 dir, t_vec3 normal)
{
	return (vec3_sub(dir, vec3_scale(normal, vec3_dot(dir, normal) * 2)));
}
