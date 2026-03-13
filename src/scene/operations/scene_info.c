/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:16:51 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 01:27:24 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libtensr.h>
#include <core/scene.h>
#include <core/object.h>

// REMOVE THIS FILE BEFORE SUBMITTING

static void scene_object_info(t_object **head)
{
    t_sphere    sp;
    t_plane     pl;
    t_cylinder  cy;
    t_object    *curr;

    if (!head || !*head)
        return ;
    curr = *head;
    while (curr)
    {
        if (curr->type == OBJ_SPHERE)
        {
            sp = curr->data.sphere;
            printf("+ SPHERE\n");
            printf("     - radius: %lf\n", sp.radius);
            printf("     - center:\n");
            tensr_print(sp.center);
            printf("     - rgb:\n");
            tensr_print(sp.rgb);
            printf("\n");
        }
        if (curr->type == OBJ_PLANE)
        {
            pl = curr->data.plane;
            printf("+ PLANE\n");
            printf("     - point:\n");
            tensr_print(pl.point);
            printf("     - normal:\n");
            tensr_print(pl.normal);
            printf("     - rgb:\n");
            tensr_print(pl.rgb);
            printf("\n");
        }
        if (curr->type == OBJ_CYLINDER)
        {
            cy = curr->data.cylinder;
            printf("+ CYLINDER\n");
            printf("     - height: %lf\n", cy.height);
            printf("     - radius: %lf\n", cy.radius);
            printf("     - point:\n");
            tensr_print(cy.point);
            printf("     - axis:\n");
            tensr_print(cy.axis);
            printf("     - rgb:\n");
            tensr_print(cy.rgb);
            printf("\n");
        }
        curr = curr->next;
    }
}

void    scene_info(t_scene *scene)
{
    t_ambient   *amb;
    t_camera    *cam;
    t_light     *light;

    if (!scene)
        return ;
    amb = &scene->amb;
    cam = &scene->cam;
    light = &scene->light;
    printf("=== SCENE INFO ===\n\n");
    if (amb)
    {
        printf("+ AMBIENT LIGHT\n");
        printf("     - ratio: %lf\n", amb->ratio);
        printf("     - rgb:\n");
        tensr_print(amb->rgb);
        printf("\n");
    }
    if (cam)
    {
        printf("+ CAMERA\n");
        printf("     - fov: %lf\n", cam->fov);
        printf("     - view:\n");
        tensr_print(cam->view);
        printf("     - orient:\n");
        tensr_print(cam->orient);
        printf("\n");
    }
    if (light)
    {
        printf("+ LIGHT\n");
        printf("     - ratio: %lf\n", light->ratio);
        printf("     - point:\n");
        tensr_print(light->point);
        printf("     - orient:\n");
        tensr_print(light->rgb);
        printf("\n");
    }
    scene_object_info(&scene->head);
}
