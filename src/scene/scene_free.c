/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:04:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/18 23:15:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/object.h>
#include <core/scene.h>

void    scene_free(t_scene *scene)
{
    if (!scene)
        return ;
    if (scene->cam.u)
    {
        tensr_free(scene->cam.u);
        scene->cam.u = NULL;
    }
    if (scene->cam.v)
    {
        tensr_free(scene->cam.v);
        scene->cam.v = NULL;
    }
    if (scene->head)
    {
        obj_free(&scene->head);
        scene->head = NULL;
    }
    free(scene);
}
