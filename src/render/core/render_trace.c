/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 02:47:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/05 17:13:11 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <elements/scene.h>
#include <float.h>
#include <math.h>

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

static void	assign_normal(t_hit *hit)
{
	if (hit->obj->type == OBJ_SPHERE)
		hit->normal = normal_sphere(hit->point, &hit->obj->data.sphere);
	else if (hit->obj->type == OBJ_PLANE)
		hit->normal = normal_plane(hit->ray.dir, &hit->obj->data.plane);
	else if (hit->obj->type == OBJ_CYLINDER)
		hit->normal = normal_cylinder(hit, &hit->obj->data.cylinder);
	else if (hit->obj->type == OBJ_CONE)
		hit->normal = normal_cone(hit, &hit->obj->data.cone);
}

static t_bool fill_hit(t_ray ray, t_hit *hit)
{
	if (!hit->obj)
		return (FALSE);
	hit->ray = ray;
	hit->point = ray_at(hit->ray, hit->t);
	assign_normal(hit);
	assign_rgb(hit);
	return (TRUE);
}

t_bool render_trace(t_ray ray, t_hit *hit, t_scene *scene)
{
	size_t		i;
	t_array		*arr;
	t_object	*curr;
	float		hit_t;

	arr = &scene->obj_view;
	hit->obj = NULL;
	hit->t = FLT_MAX;
	i = 0;
	while (i < arr->len)
	{
		curr = ((t_object **)arr->data)[i];
		hit_t = isect_obj(&ray, &hit->loc, curr);
		if (hit_t > 1e-4f && hit_t < hit->t)
		{
			hit->t = hit_t;
			hit->obj = curr;
		}
		i++;
	}
	return (fill_hit(ray, hit));
}
