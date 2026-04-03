/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:55:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 15:19:07 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

static bool	render_tile(t_tile *tile, t_scene *scene)
{
	int		x;
	int		y;
	t_hit	hit;
	t_ray	ray;
	float	*ptr;

	if (!tile || !tile->buffer || !tile->rdir || !scene)
		return (false);
	y = -1;
	while (++y < tile->height)
	{
		x = -1;
		while (++x < tile->width)
		{
			ptr = (float *)tile->buffer->data
				+ tensr_offset(&tile->buffer->layout, (size_t[]){y, x, 0});
			ray = ray_create(scene->cam.point, tile->rdir, x, y);
			if (render_trace(ray, &hit, scene))
				shade_apply(scene, &hit, ptr);
			else
				color_fill(ptr, NULL);
		}
	}
	return (true);
}

static void	*worker_run(void *arg)
{
	t_worker	*worker;
	t_tile		*tiles;
	size_t		i;

	worker = (t_worker *)arg;
	tiles = worker->tiles;
	i = 0;
	while (worker->start + i < worker->end)
	{
		if (!render_tile(&tiles[worker->start + i], worker->scene))
			return (NULL);
		i++;
	}
	return (NULL);
}

bool	pool_run(t_pool *pool)
{
	size_t	i;

	if (!pool || !pool->workers)
		return (false);
	i = 0;
	while (i < pool->n_workers)
	{
		if (pthread_create(&pool->workers[i]->thread, NULL, worker_run,
				pool->workers[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}
