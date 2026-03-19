/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:11:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 16:12:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/render.h>

static void normalize_rgb(t_scene *scene)
{
    t_object   *curr;
    float       scale;

    scale = 1.0f / 255.0f;
    vec3_scale_ip(&scene->amb.rgb, scale);
    vec3_scale_ip(&scene->light.rgb, scale);
    curr = scene->head;
    while (curr)
    {
        if (curr->type == OBJ_SPHERE)
            vec3_scale_ip(&curr->data.sphere.rgb, scale);
        if (curr->type == OBJ_PLANE)
            vec3_scale_ip(&curr->data.plane.rgb, scale);
        if (curr->type == OBJ_CYLINDER)
            vec3_scale_ip(&curr->data.cylinder.rgb, scale);
        curr = curr->next;
    }
}

bool	render_init(t_display *disp, t_scene *scene)
{
	float	con;
	t_dim	*dim;

	if (!disp || !scene)
		return (false);
    normalize_rgb(scene);
	dim = &disp->dim;
	con = tanf(scene->cam.fov / 2);
	scene->cam.u = tensr_linspace(-(dim->aspect * con), (dim->aspect * con),
			dim->width, DT_F32);
	if (!scene->cam.u)
		return (false);
	scene->cam.v = tensr_linspace(con, -con, dim->height, DT_F32);
	if (!scene->cam.v)
		return (tensr_free(scene->cam.u), false);
	disp->framebuf = tensr_full(0.0, 3, (size_t[]){dim->height, dim->width, 3},
			DT_F32);
	if (!disp->framebuf)
    {
        tensr_free(scene->cam.v);
        tensr_free(scene->cam.u);
        return (false);
    }
	return (true);
}
