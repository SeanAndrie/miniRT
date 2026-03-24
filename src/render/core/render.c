/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:35:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 00:44:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libft.h>
#include <libtensr.h>
#include <math.h>
#include <mlx.h>

static bool	in_shadow(t_scene *scene, t_hit *hit, t_vec3 l_hat, t_light *light)
{
	float		hit_t;
	t_object	*curr;
	float		light_dist;
	t_ray		shadow_ray;

	light_dist = vec3_magnitude(vec3_sub(light->point, hit->point));
	shadow_ray.orig = vec3_add(hit->point, vec3_scale(hit->normal, 1e-2f));
	shadow_ray.dir = l_hat;
	curr = scene->objects;
	while (curr)
	{
		if (curr != hit->obj)
		{
			hit_t = isect_obj(&shadow_ray, curr);
			if (hit_t > 1e-4f && hit_t < light_dist)
				return (true);
		}
		curr = curr->next;
	}
	return (false);
}

static void	shade(t_scene *scene, t_hit *hit, float *ptr)
{
	t_vec3	rgb;
	t_vec3	l_hat;
	t_light	*curr;

	curr = scene->lights;
	rgb = shade_ambient(&scene->amb, hit->rgb);
	while (curr)
	{
		l_hat = vec3_normalize(vec3_sub(curr->point, hit->point));
		if (!in_shadow(scene, hit, l_hat, curr))
		{
			vec3_add_ip(&rgb, shade_diffuse(curr->ratio, curr->rgb, hit,
					l_hat));
			vec3_add_ip(&rgb, shade_specular(scene, curr, hit, l_hat));
		}
		color_fill(ptr, &rgb);
		curr = curr->next;
	}
}

static bool	render_tile(t_tensr *framebuf, t_scene *scene, t_tile_map *tm)
{
	t_ray	ray;
	t_hit	hit;
	float	*ptr;
	t_tensr	*tile;
	int		idx[2];

	tile = framebuf_tile(framebuf, tm);
	if (!tile)
		return (false);
	idx[0] = -1;
	while (++idx[0] < tm->actual_h)
	{
		idx[1] = -1;
		while (++idx[1] < tm->actual_w)
		{
			ray = ray_create(&scene->cam, tm->tx + idx[1], tm->ty + idx[0]);
			ptr = (float *)tile->data + tensr_offset(&tile->layout,
					(size_t[]){idx[0], idx[1], 0});
			if (render_trace(&ray, &hit, scene))
				shade(scene, &hit, ptr);
			else
				color_fill(ptr, NULL);
		}
	}
	return (tensr_free(tile), true);
}

bool	render(t_display *disp, t_scene *scene)
{
	t_tile_map	tm;

	if (!disp || !scene || !render_init(disp, scene))
		return (false);
	tm.ty = 0;
	while (tm.ty < disp->dim.height)
	{
		tm.tx = 0;
		while (tm.tx < disp->dim.width)
		{
			tm.actual_w = ft_min(disp->tiles.w, disp->dim.width - tm.tx);
			tm.actual_h = ft_min(disp->tiles.h, disp->dim.height - tm.ty);
			if (!render_tile(disp->framebuf, scene, &tm))
				return (false);
			tm.tx += disp->tiles.w;
		}
		tm.ty += disp->tiles.h;
	}
	if (!framebuf_to_image(disp))
		return (false);
	mlx_put_image_to_window(disp->conn, disp->window, disp->image.image, 0, 0);
	return (true);
}
