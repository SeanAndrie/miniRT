/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#  +:     +#           */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 03:21:19 by sgadinga          #+#   #+    #+#        */
/*   Updated: 2026/04/03 21:37:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <float.h>

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

static bool	in_shadow(t_scene *scene, t_hit *hit, t_vec3 l_hat, t_light *light)
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
				return (true);
		}
		i++;
	}
	return (false);
}

void	shade_apply(t_scene *scene, t_hit *hit, float *ptr)
{
	size_t	i;
	t_vec3	rgb;
	t_array	*arr;
	t_light	*curr;
	t_vec3	l_hat;

	arr = &scene->lgt_view;
	if (hit->obj->opt.cb_scale > 0.0f)
		hit->rgb = shade_checker(hit, hit->obj->opt.cb_scale);
	rgb = shade_ambient(&scene->amb, hit->rgb);
	i = -1;
	while (++i < arr->len)
	{
		curr = ((t_light **)arr->data)[i];
		l_hat = vec3_normalize(vec3_sub(curr->point, hit->point));
		if (vec3_dot(hit->normal, l_hat) > 0.0f && !in_shadow(scene, hit, l_hat,
				curr))
		{
			vec3_add_ip(&rgb, shade_diffuse(curr->ratio, curr->rgb, hit,
					l_hat));
			vec3_add_ip(&rgb, shade_specular(scene, curr, hit, l_hat));
		}
	}
	color_fill(ptr, &rgb);
}
