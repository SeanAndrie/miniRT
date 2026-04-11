/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_gradient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 01:47:07 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/11 23:08:42 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/display.h>
#include <setup/texture.h>

static double	get_height(t_texture *bump_tex, double u, double v)
{
	t_vec3	c;

	c = texture_color(bump_tex, u, v);
	return (LUMA_RED * c.x + LUMA_GREEN * c.y + LUMA_BLUE * c.z);
}

t_vec3	bump_gradient(t_texture *tex, double u, double v)
{
	double	height;
	double	u_height;
	double	v_height;

	u = u - floor(u);
	v = v - floor(v);
	height = get_height(tex, u, v);
	u_height = (get_height(tex, u + (1.0 / tex->width), v) - height) * 1.5;
	v_height = (get_height(tex, u, v + (1.0 / tex->height)) - height) * 1.5;
	return ((t_vec3){u_height, v_height, 0.0});
}
