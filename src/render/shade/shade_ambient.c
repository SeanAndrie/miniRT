/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:34:33 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 16:08:31 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

t_vec3	shade_ambient(t_ambient *amb, t_vec3 rgb)
{
	return (vec3_scale(vec3_mul(amb->rgb, rgb), amb->ratio));
}
