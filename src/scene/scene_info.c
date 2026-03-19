/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:16:51 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/19 12:42:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libtensr.h>
#include <core/scene.h>
#include <core/object.h>

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
            printf("     - radius: %f\n", sp.radius);
            printf("     - center: (%f, %f, %f)\n", sp.center.x, sp.center.y, sp.center.z);
            printf("     - rgb: (%f, %f, %f)\n", sp.rgb.x, sp.rgb.y, sp.rgb.z);
            printf("\n");
        }
        if (curr->type == OBJ_PLANE)
        {
            pl = curr->data.plane;
            printf("+ PLANE\n");
            printf("     - point: (%f, %f, %f)\n", pl.point.x, pl.point.y, pl.point.z);
            printf("     - normal: (%f, %f, %f)\n", pl.normal.x, pl.normal.y, pl.normal.z);
            printf("     - rgb: (%f, %f, %f)\n", pl.rgb.x, pl.rgb.y, pl.rgb.z);
            printf("\n");
        }
        if (curr->type == OBJ_CYLINDER)
        {
            cy = curr->data.cylinder;
            printf("+ CYLINDER\n");
            printf("     - height: %f\n", cy.height);
            printf("     - radius: %f\n", cy.radius);
            printf("     - point: (%f, %f, %f)\n", cy.point.x, cy.point.y, cy.point.z);
            printf("     - axis: (%f, %f, %f)\n", cy.axis.x, cy.axis.y, cy.axis.z);
            printf("     - rgb: (%f, %f, %f)\n", cy.rgb.x, cy.rgb.y, cy.rgb.z);
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
        printf("     - rgb: (%f, %f, %f)\n", amb->rgb.x, amb->rgb.y, amb->rgb.z);
        printf("\n");
    }
    if (cam)
    {
        printf("+ CAMERA\n");
        printf("     - fov: %f\n", cam->fov);
        printf("     - point: (%f, %f, %f)\n", cam->point.x, cam->point.y, cam->point.z);
        printf("     - forward: (%f, %f, %f)\n", cam->basis.forward.x, cam->basis.forward.y, cam->basis.forward.z);
        printf("     - right: (%f, %f, %f)\n", cam->basis.right.x, cam->basis.right.y, cam->basis.right.z);
        printf("     - up: (%f, %f, %f)\n", cam->basis.up.x, cam->basis.up.y, cam->basis.up.z);
        printf("\n");
    }
    if (light)
    {
        printf("+ LIGHT\n");
        printf("     - ratio: %f\n", light->ratio);
        printf("     - point: (%f, %f, %f)\n", light->point.x, light->point.y, light->point.z);
        printf("     - rgb: (%f, %f, %f)\n", light->rgb.x, light->rgb.y, light->rgb.z);
        printf("\n");
    }
    scene_object_info(&scene->head);
}
