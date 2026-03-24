/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:12:08 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 16:39:42 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

t_project	get_projection(t_vec3 v, t_vec3 u_hat)
{
	t_project	proj;

	proj.axial = vec3_dot(v, u_hat);
	proj.perp = vec3_sub(v, vec3_scale(u_hat, proj.axial));
	return (proj);
}
