/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:04:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 15:53:04 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <elements/object.h>
#include <elements/scene.h>
#include <libtensr.h>

void	coords_free(t_dev_coord *coords)
{
	if (coords->u_range)
		tensr_free(coords->u_range);
	if (coords->v_range)
		tensr_free(coords->v_range);
}

void	scene_free(t_scene *scene)
{
	if (!scene)
		return ;
	coords_free(&scene->cam.coords);
	if (scene->objects)
    {
        free(scene->obj_view.data);
		obj_free(&scene->objects);
    }
	if (scene->lights)
    {
        free(scene->lgt_view.data);
		light_free(&scene->lights);
    }
	free(scene);
}
