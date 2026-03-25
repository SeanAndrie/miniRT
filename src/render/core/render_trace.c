/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 02:47:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 00:16:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <core/render.h>

static void	assign_rgb(t_hit *hit)
{
	if (hit->obj->type == OBJ_SPHERE)
		hit->rgb = hit->obj->data.sphere.rgb;
	else if (hit->obj->type == OBJ_PLANE)
		hit->rgb = hit->obj->data.plane.rgb;
	else if (hit->obj->type == OBJ_CYLINDER)
		hit->rgb = hit->obj->data.cylinder.rgb;
	else if (hit->obj->type == OBJ_CONE)
		hit->rgb = hit->obj->data.cone.rgb;
}

static void	assign_normal(t_vec3 ray_dir, t_hit *hit)
{
	if (hit->obj->type == OBJ_SPHERE)
		hit->normal = normal_sphere(hit->point, &hit->obj->data.sphere);
	else if (hit->obj->type == OBJ_PLANE)
		hit->normal = normal_plane(ray_dir, &hit->obj->data.plane);
	else if (hit->obj->type == OBJ_CYLINDER)
		hit->normal = normal_cylinder(hit->point, &hit->obj->data.cylinder,
				hit->t);
	else if (hit->obj->type == OBJ_CONE)
		hit->normal = normal_cone(hit->point, &hit->obj->data.cone, hit->t);
}

static bool	fill_hit(t_ray *ray, t_hit *hit)
{
	if (!hit->obj)
		return (false);
	hit->point = ray_at(*ray, hit->t);
	assign_normal(ray->dir, hit);
	assign_rgb(hit);
	return (true);
}

bool	render_trace(t_ray *ray, t_hit *hit, t_scene *scene)
{
	t_object	*curr;
	float		hit_t;

	hit->obj = NULL;
	hit->t = FLT_MAX;
	curr = scene->objects;
	while (curr)
	{
		hit_t = isect_obj(ray, curr);
		if (hit_t > 1e-4f && hit_t < hit->t)
		{
			hit->t = hit_t;
			hit->obj = curr;
		}
		curr = curr->next;
	}
	if (!fill_hit(ray, hit))
		return (false);
	return (true);
}
