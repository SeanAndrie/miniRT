/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:11:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 15:36:02 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/render.h>
#include <setup/display.h>
#include <elements/scene.h>

static void	normalize_rgb(t_scene *scene)
{
	t_object	*curr;
	t_light		*light;
	float		scale;

	scale = 1.0f / 255.0f;
	vec3_scale_ip(&scene->amb.rgb, scale);
	light = scene->lights;
	while (light)
	{
		vec3_scale_ip(&light->rgb, scale);
		light = light->next;
	}
	curr = scene->objects;
	while (curr)
	{
		if (curr->type == OBJ_SPHERE)
			vec3_scale_ip(&curr->data.sphere.rgb, scale);
		if (curr->type == OBJ_PLANE)
			vec3_scale_ip(&curr->data.plane.rgb, scale);
		if (curr->type == OBJ_CYLINDER)
			vec3_scale_ip(&curr->data.cylinder.rgb, scale);
		if (curr->type == OBJ_CONE)
			vec3_scale_ip(&curr->data.cone.rgb, scale);
		curr = curr->next;
	}
}

static bool	create_uv_grids(t_camera *cam, t_dim *dim)
{
	float	con;

	con = tanf(cam->fov / 2);
	cam->coords.u_range = tensr_linspace(-(dim->aspect * con), (dim->aspect
				* con), dim->width, DT_F32);
	if (!cam->coords.u_range)
		return (false);
	cam->coords.v_range = tensr_linspace(con, -con, dim->height, DT_F32);
	if (!cam->coords.v_range)
		return (tensr_free(cam->coords.u_range), false);
	return (true);
}

bool	render_init(t_display *disp, t_scene *scene)
{
	t_dim	*dim;

	if (!disp || !scene)
		return (false);
	normalize_rgb(scene);
	dim = &disp->dim;
	if (!create_uv_grids(&scene->cam, dim))
		return (false);
	disp->framebuf = tensr_full(0.0, 3, (size_t[]){dim->height, dim->width, 3},
			DT_F32);
	if (!disp->framebuf)
	{
		coords_free(&scene->cam.coords);
		return (false);
	}
	return (true);
}
