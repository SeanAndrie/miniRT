/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:11:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 17:51:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <elements/scene.h>
#include <libtensr.h>
#include <setup/display.h>

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

t_bool	render_init(t_pool *pool, t_display *disp, t_scene *scene)
{
	if (!pool || !disp || !scene)
		return (FALSE);
	normalize_rgb(scene);
	if (!camera_init(&scene->cam, disp->width, disp->height, disp->aspect))
		return (FALSE);
	if (!frame_init(&disp->frame, disp->width, disp->height))
		return (FALSE);
	if (MULTITHREADED)
	{
		ft_printf("Multithreading : ON\n");
		if (!pool_init(pool, disp, scene))
			return (FALSE);
	}
	return (TRUE);
}
