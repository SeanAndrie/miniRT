/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 02:47:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 17:05:49 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include <core/render.h>

static bool	fill_hit(t_ray *ray, t_isect *is, t_hit *hit)
{
	if (!is->obj)
		return (false);
	hit->t = is->t;
	hit->point = ray_at(*ray, hit->t);
	if (is->obj->type == OBJ_SPHERE)
	{
		hit->normal = normal_sphere(hit->point, &is->obj->data.sphere);
		hit->rgb = is->obj->data.sphere.rgb;
	}
	return (true);
}

bool	render_trace(t_ray *ray, t_hit *hit, t_scene *scene)
{
	t_isect		is;
	t_object	*curr;
	float		hit_t;

	is.obj = NULL;
	is.t = FLT_MAX;
	curr = scene->head;
	while (curr)
	{
		hit_t = isect_obj(ray, curr);
		if (hit_t > 1e-4f && hit_t < is.t)
        {
            is.t = hit_t;
            is.obj = curr;
        }
		curr = curr->next;
	}
	return (fill_hit(ray, &is, hit));
}
