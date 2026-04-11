/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 01:30:18 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/12 01:44:06 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/texture.h>

static int	texel_color(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

t_vec3	texture_color(t_texture *tex, double u, double v)
{
	int	x;
	int	y;
	int	color;

	u = u - floor(u);
	v = v - floor(v);
	x = (int)(u * (tex->width - 1));
	y = (int)((1.0 - v) * (tex->height - 1));
	color = texel_color(tex, x, y);
	return ((t_vec3){((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF)
		/ 255.0, (color & 0xFF) / 255.0});
}
