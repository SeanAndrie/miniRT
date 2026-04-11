/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:21:04 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 04:32:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

static t_bool	create_tiles(t_tile *tiles, t_display *disp, t_tensr *rdir)
{
	size_t		i;
	t_tile_map	tm;

	if (!tiles || !disp || !rdir)
		return (FALSE);
	i = 0;
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
			if (!tile_create(&tiles[i++], disp->frame.buffer, rdir, &tm))
				return (tile_free(tiles, i), FALSE);
			tm.tx += disp->frame.tile_dim.width;
		}
		tm.ty += disp->frame.tile_dim.height;
	}
	return (TRUE);
}

static t_bool	create_workers(t_pool *pool, t_scene *scene)
{
	size_t		i;
	t_worker	*block;

	if (!pool || !scene)
		return (FALSE);
	block = (t_worker *)((char *)pool->workers + (sizeof(t_worker *)
				* pool->n_workers));
	i = 0;
	while (i < pool->n_workers)
	{
		pool->workers[i] = &block[i];
		pool->workers[i]->scene = scene;
		pool->workers[i]->tiles = pool->tiles;
		pool->workers[i]->start = i * pool->worker_tiles;
		if (i == pool->n_workers - 1)
			pool->workers[i]->end = pool->n_tiles;
		else
			pool->workers[i]->end = (i + 1) * pool->worker_tiles;
		i++;
	}
	return (TRUE);
}

t_bool	pool_init(t_pool *pool, t_display *disp, t_scene *scene)
{
	if (!pool || !disp || !scene)
		return (FALSE);
	pool->n_tiles = disp->frame.tile_dim.count;
	pool->n_workers = N_THREADS;
	pool->worker_tiles = pool->n_tiles / pool->n_workers;
	pool->tiles = malloc(sizeof(t_tile) * pool->n_tiles);
	if (!pool->tiles || !create_tiles(pool->tiles, disp, scene->cam.rdir.out))
		return (FALSE);
	pool->workers = malloc((sizeof(t_worker *) * pool->n_workers)
			+ (sizeof(t_worker) * pool->n_workers));
	if (!pool->workers || !create_workers(pool, scene))
		return (FALSE);
	return (TRUE);
}
