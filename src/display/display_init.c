/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:40:27 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 01:55:35 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/display.h>
#include <libft.h>
#include <libtensr.h>
#include <math.h>
#include <mlx.h>

static t_tiles	calculate_tiles(t_dim *dim)
{
	t_tiles	t;

	t.w = ft_max(1, dim->width / (int)sqrtf(TARGET_TILES));
	t.h = ft_max(1, dim->height / (int)sqrtf(TARGET_TILES));
	t.count_x = (dim->width + t.w - 1) / t.w;
	t.count_y = (dim->height + t.h - 1) / t.h;
	t.count = t.count_x * t.count_y;
	return (t);
}

t_display	*display_init(const int width, const int height, char *title)
{
	t_display	*disp;

	if (!title)
		return (false);
	disp = ft_calloc(1, sizeof(t_display));
	if (!disp)
		return (NULL);
	disp->conn = mlx_init();
	if (!disp->conn)
		return (NULL);
	disp->window = mlx_new_window(disp->conn, width, height, title);
	if (!disp->window)
		return (display_free(disp), NULL);
	disp->image.image = mlx_new_image(disp->conn, width, height);
	if (!disp->image.image)
		return (display_free(disp), NULL);
	disp->image.addr = mlx_get_data_addr(disp->image.image, &disp->image.bpp,
			&disp->image.line_len, &disp->image.endian);
	if (!disp->image.addr)
		return (display_free(disp), NULL);
	disp->dim.width = width;
	disp->dim.height = height;
	disp->dim.aspect = (float)disp->dim.width / (float)disp->dim.height;
	disp->tiles = calculate_tiles(&disp->dim);
	return (disp);
}
