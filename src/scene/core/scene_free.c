/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:04:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 23:16:42 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <elements/scene.h>
#include <libft.h>
#include <libtensr.h>

void	scene_free(t_scene *scene)
{
	if (!scene)
		return ;
	camera_free(&scene->cam);
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
