/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 22:42:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/23 22:42:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libtensr_rt.h>

void	color_fill(float *ptr, t_vec3 *rgb)
{
	if (rgb)
	{
		ptr[0] = rgb->x;
		ptr[1] = rgb->y;
		ptr[2] = rgb->z;
	}
	else
	{
		ptr[0] = 0.0f;
		ptr[1] = 0.0f;
		ptr[2] = 0.0f;
	}
}
