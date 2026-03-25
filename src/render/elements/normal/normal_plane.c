/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:03:53 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/23 17:44:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <float.h>

t_vec3	normal_plane(t_vec3 ray_dir, t_plane *pl)
{
	float	denom;

	denom = vec3_dot(ray_dir, pl->normal);
	if (denom > 0.0f)
		return (vec3_neg(pl->normal));
	return (pl->normal);
}
