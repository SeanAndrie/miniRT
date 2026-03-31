/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:11:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 00:22:30 by sgadinga         ###   ########.fr       */
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

bool	render_init(t_display *d, t_scene *s)
{
	if (!d || !s)
		return (false);
	normalize_rgb(s);
	if (!camera_init(&s->cam, d->width, d->height, d->aspect))
		return (false);
    if (!frame_init(&d->frame, d->width, d->height))
        return (false);
    return (true);
}
