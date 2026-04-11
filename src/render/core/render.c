/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 00:58:25 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/05 17:25:55 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libft.h>
#include <math.h>

static inline t_vec3	extract_dir(const t_tensr *rdir, int x, int y)
{
	size_t	offset;

	offset = tensr_offset(&rdir->layout, (size_t[]){x, y, 0});
	return (*(t_vec3 *)((float *)rdir->data + offset));
}

static inline void	update_basis(t_basis *basis)
{
	ft_memcpy(basis->forward_t->data, &basis->forward, sizeof(t_vec3));
	ft_memcpy(basis->right_t->data, &basis->right, sizeof(t_vec3));
	ft_memcpy(basis->up_t->data, &basis->up, sizeof(t_vec3));
}

static t_bool	render_tile(t_frame *frame, t_scene *scene, t_tile_map *tm)
{
	int		x;
	int		y;
	t_hit	hit;
	t_tile	tile;
	float	*ptr;

	if (!tile_create(&tile, frame->buffer, scene->cam.rdir.out, tm))
		return (FALSE);
	y = -1;
	while (++y < tm->actual_h)
	{
		x = -1;
		while (++x < tm->actual_w)
		{
			ptr = (float *)tile.buffer->data
				+ tensr_offset(&tile.buffer->layout, (size_t[]){y, x, 0});
			if (render_trace(ray_create(scene->cam.point, tile.rdir, x, y),
					&hit, scene))
				color_fill(ptr, shade_apply(scene, &hit));
			else
				color_fill(ptr, (t_vec3){0, 0, 0});
		}
	}
	return (tile_free(&tile, 1), TRUE);
}

t_bool	render(t_display *disp, t_scene *scene)
{
	t_tile_map	tm;

	update_basis(&scene->cam.basis);
	if (!camera_rdir(&scene->cam))
		return (FALSE);
	tm.ty = 0;
	while (tm.ty < disp->height)
	{
		tm.tx = 0;
		while (tm.tx < disp->width)
		{
			tm.actual_w = ft_min(disp->frame.tile_dim.width, disp->width
					- tm.tx);
			tm.actual_h = ft_min(disp->frame.tile_dim.height, disp->height
					- tm.ty);
			if (!render_tile(&disp->frame, scene, &tm))
				return (FALSE);
			tm.tx += disp->frame.tile_dim.width;
		}
		tm.ty += disp->frame.tile_dim.height;
	}
	if (!frame_blit(disp))
		return (FALSE);
	mlx_put_image_to_window(disp->conn, disp->window, disp->image.image, 0, 0);
	return (TRUE);
}

t_bool	render_threaded(t_pool *pool, t_display *disp, t_scene *scene)
{
	if (!pool || !disp || !scene)
		return (FALSE);
	update_basis(&scene->cam.basis);
	if (!camera_rdir(&scene->cam))
		return (FALSE);
	if (!pool_run(pool))
		return (FALSE);
	pool_join(pool);
	if (!frame_blit(disp))
		return (FALSE);
	mlx_put_image_to_window(disp->conn, disp->window, disp->image.image, 0, 0);
	return (TRUE);
}
