/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isect_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:09:36 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 20:43:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <float.h>
#include <libft.h>
#include <math.h>

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

static void	isect_cylinder_caps(t_ray *ray, t_cylinder *cy, float *t)
{
	t_vec3	bot;
	t_vec3	top;
	t_vec3	rgb;
	float	t_cap;

	ft_memset(&rgb, 0, sizeof(t_vec3));
	bot = vec3_sub(cy->point, vec3_scale(cy->axis, cy->height * 0.5f));
	top = vec3_add(cy->point, vec3_scale(cy->axis, cy->height * 0.5f));
	t_cap = isect_disk(ray, (t_plane){bot, vec3_scale(cy->axis, -1.0f), rgb},
			cy->radius);
	if (t_cap > 1e-4f && (t_cap < *t || *t < 1e-4f))
	{
		*t = t_cap;
		cy->hit_loc = SURF_BOT;
	}
	t_cap = isect_disk(ray, (t_plane){top, cy->axis, rgb}, cy->radius);
	if (t_cap > 1e-4f && (t_cap < *t || *t < 1e-4f))
	{
		*t = t_cap;
		cy->hit_loc = SURF_TOP;
	}
}

static bool	is_between_caps(float l_ax, float d_ax, float half_h, float t)
{
	float	h;

	h = l_ax + d_ax * t;
	if (h >= -half_h && h <= half_h)
		return (true);
	return (false);
}

static float	solve_quadratic(t_vec3 quad, float l_ax, float d_ax,
		t_cylinder *cy)
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
	if (t0 > 1e-4f && is_between_caps(l_ax, d_ax, cy->height / 2.0f, t0))
		t = t0;
	else if (t1 > 1e-4f && is_between_caps(l_ax, d_ax, cy->height / 2.0f, t1))
		t = t1;
	return (t);
}

float	isect_cylinder(t_ray *ray, t_cylinder *cy)
{
	float	t;
	t_vec3	quad;

	cy->hit_loc = SURF_SIDE;
	cy->l = get_projection(vec3_sub(ray->orig, cy->point), cy->axis);
	cy->d = get_projection(ray->dir, cy->axis);
	quad.x = vec3_dot(cy->d.perp, cy->d.perp);
	t = 0.0f;
	if (fabsf(quad.x) > 1e-6f)
	{
		quad.y = 2.0f * vec3_dot(cy->d.perp, cy->l.perp);
		quad.z = vec3_dot(cy->l.perp, cy->l.perp) - (cy->radius * cy->radius);
		t = solve_quadratic(quad, cy->l.axial, cy->d.axial, cy);
	}
	isect_cylinder_caps(ray, cy, &t);
	return (t);
}
