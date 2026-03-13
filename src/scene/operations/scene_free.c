/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:04:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 20:40:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <object.h>
#include <scene.h>

void    scene_free(t_scene *scene)
{
    if (!scene)
        return ;
    ambient_free(&scene->amb);
    camera_free(&scene->cam);
    light_free(&scene->light);
    if (scene->head)
    {
        obj_free(&scene->head);
        scene->head = NULL;
    }
    free(scene);
}
