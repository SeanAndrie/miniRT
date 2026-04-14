/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 01:38:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/14 10:16:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <setup/texture.h>

void	color_fill(float *ptr, t_vec3 rgb)
{
	ptr[0] = rgb.x;
	ptr[1] = rgb.y;
	ptr[2] = rgb.z;
}

static t_bool	in_shadow(t_scene *scene, t_hit *hit, t_vec3 l_hat,
		t_light *light)
{
	size_t		i;
	float		hit_t;
	t_object	*curr;
	float		light_dist;
	t_ray		shadow_ray;

	light_dist = vec3_magnitude(vec3_sub(light->point, hit->point));
	shadow_ray.orig = vec3_add(hit->point, vec3_scale(hit->normal, 1e-2f));
	shadow_ray.dir = l_hat;
	i = 0;
	while (i < scene->obj_view.len)
	{
		curr = ((t_object **)scene->obj_view.data)[i];
		if (curr != hit->obj)
		{
			hit_t = isect_obj(&shadow_ray, &hit->loc, curr);
			if (hit_t > 1e-4f && hit_t < light_dist)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static void	surface_modifiers(t_hit *hit, t_scene *scene)
{
	double	u;
	double	v;

	if (scene->bonus->checkerboard && hit->obj->opt.cb_scale > 0.0f)
		hit->rgb = shade_checker(hit, hit->obj->opt.cb_scale);
	if (scene->bonus->bump_map && hit->obj->opt.texture)
	{
		u = hit->u - floor(hit->u);
		v = hit->v - floor(hit->v);
		hit->rgb = texture_color(hit->obj->opt.texture, u, v);
	}
}

static void	accumulate_light(t_scene *scene, t_hit *hit, t_vec3 *rgb)
{
	size_t	i;
	t_light	*curr;
	t_vec3	l_hat;
	t_array	*arr;

	arr = &scene->lgt_view;
	i = 0;
	while (i < arr->len)
	{
		curr = ((t_light **)arr->data)[i];
		l_hat = vec3_normalize(vec3_sub(curr->point, hit->point));
		if (vec3_dot(hit->normal, l_hat) <= 0.0f || in_shadow(scene, hit, l_hat,
				curr))
			continue ;
		vec3_add_ip(rgb, shade_diffuse(curr->ratio, curr->rgb, hit, l_hat));
		if (hit->obj->opt.texture && !hit->obj->opt.specularity)
			break ;
		if (scene->bonus->specular)
			vec3_add_ip(rgb, shade_specular(scene, curr, hit, l_hat));
		i++;
	}
}

t_vec3	shade_color(t_scene *scene, t_hit *hit)
{
	t_vec3	rgb;

	surface_modifiers(hit, scene);
	if (scene->bonus->bump_map && hit->obj->opt.bump_texture)
		hit->normal = bump_normal(hit);
	rgb = shade_ambient(&scene->amb, hit->rgb);
	accumulate_light(scene, hit, &rgb);
	return (rgb);
}
