/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:14:11 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 03:26:54 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

static t_vec3	render_reflect(t_ray ray, t_scene *scene, int depth);
static t_vec3	render_reflect_hit(t_hit *hit, t_scene *scene, int depth);

static t_vec3	render_reflect(t_ray ray, t_scene *scene, int depth)
{
	t_hit	hit;

	if (depth <= 0 || !render_trace(ray, &hit, scene))
		return ((t_vec3){0, 0, 0});
	return (render_reflect_hit(&hit, scene, depth));
}

static t_vec3	render_reflect_hit(t_hit *hit, t_scene *scene, int depth)
{
	t_vec3	rgb;
	t_ray	ref_ray;
	float	ref_factor;

	ref_factor = hit->obj->opt.reflectivity;
	rgb = shade_color(scene, hit);
	if (ref_factor <= 0.0f || depth <= 0)
		return (rgb);
	ref_ray.orig = vec3_add(hit->point, vec3_scale(hit->normal, 1e-4f));
	ref_ray.dir = ray_reflect(hit->ray.dir, hit->normal);
	return (vec3_add(vec3_scale(rgb, 1.0f - ref_factor),
			vec3_scale(render_reflect(ref_ray, scene, depth - 1), ref_factor)));
}

t_vec3	shade_apply(t_scene *scene, t_hit *hit)
{
	if (!scene || !hit)
		return ((t_vec3){0, 0, 0});
	if (hit->obj->opt.reflectivity > 0.0f)
		return (render_reflect_hit(hit, scene, REFLECT_DEPTH));
	return (shade_color(scene, hit));
}
