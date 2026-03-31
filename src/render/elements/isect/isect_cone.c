/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isect_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:08:09 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 19:09:21 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft.h>
#include <float.h>
#include <libtensr_rt.h>
#include <core/render.h>
#include <core/render.h>

static bool	is_inside_cone(float l_ax, float d_ax, float height, float t)
{
	float	h;

	h = l_ax + d_ax * t;
	if (h >= 0.0f && h <= height)
		return (true);
	return (false);
}

static float	isect_disk(t_ray *ray, t_plane pl, float radius)
{
	float	t;
	t_vec3	diff;
	t_vec3	hit_p;

	t = isect_plane(ray, &pl);
	hit_p = ray_at(*ray, t);
	diff = vec3_sub(hit_p, pl.point);
	if (vec3_dot(diff, diff) > (radius * radius))
		return (0.0f);
	return (t);
}

static void	isect_cone_cap(t_ray *ray, t_cone *co, float *t)
{
	t_vec3	rgb;
	t_vec3	base;
	float	t_cap;
	float	radius;

	ft_memset(&rgb, 0, sizeof(t_vec3));
	base = vec3_add(co->apex, vec3_scale(co->axis, co->height));
	radius = co->height * co->k;
	t_cap = isect_disk(ray, (t_plane){base, co->axis, rgb}, radius);
	if (t_cap > 1e-4f && (t_cap < *t || *t < 1e-4f))
	{
		*t = t_cap;
		co->hit_loc = SURF_BOT;
	}
}

static float	solve_quadratic(t_vec3 quad, float l_ax, float d_ax, t_cone *co)
{
	float	t;
	float	t0;
	float	t1;
	float	disc;

	disc = (quad.y * quad.y) - (4.0f * quad.x * quad.z);
	if (disc <= 0.0f)
		return (0.0f);
	t = 0.0f;
	t0 = (-quad.y - sqrtf(disc)) / (2.0f * quad.x);
	t1 = (-quad.y + sqrtf(disc)) / (2.0f * quad.x);
	if (t0 > 1e-4f && is_inside_cone(l_ax, d_ax, co->height, t0))
		t = t0;
	else if (t1 > 1e-4f && is_inside_cone(l_ax, d_ax, co->height, t1))
		t = t1;
	return (t);
}

float	isect_cone(t_ray *ray, t_cone *co)
{
	float	t;
	t_vec3	quad;

	co->hit_loc = SURF_SIDE;
	co->l = vec3_project(vec3_sub(ray->orig, co->apex), co->axis);
	co->d = vec3_project(ray->dir, co->axis);
	quad.x = vec3_dot(co->d.perp, co->d.perp) - (co->k2 * (co->d.axial
				* co->d.axial));
	t = 0.0f;
	if (fabsf(quad.x) > 1e-6f)
	{
		quad.y = 2.0f * (vec3_dot(co->l.perp, co->d.perp) - (co->k2
					* (co->l.axial * co->d.axial)));
		quad.z = vec3_dot(co->l.perp, co->l.perp) - (co->k2 * (co->l.axial
					* co->l.axial));
		t = solve_quadratic(quad, co->l.axial, co->d.axial, co);
	}
	isect_cone_cap(ray, co, &t);
	return (t);
}
