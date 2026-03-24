/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>        #+:+#         #+:+# */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:16:51 by sgadinga          #+#    #+##+        #+*/
/*   Updated: 2026/03/25 00:23:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>
#include <core/scene.h>
#include <libtensr.h>
#include <stdio.h>

static void	print_vec3(const char *label, t_vec3 v)
{
	printf("     - %s: (%f, %f, %f)\n", label, v.x, v.y, v.z);
}

static void	print_sphere(t_sphere *sp)
{
	printf("+ SPHERE\n");
	printf("     - radius: %f\n", sp->radius);
	print_vec3("center", sp->center);
	print_vec3("rgb", sp->rgb);
	printf("\n");
}

static void	print_plane(t_plane *pl)
{
	printf("+ PLANE\n");
	print_vec3("point", pl->point);
	print_vec3("normal", pl->normal);
	print_vec3("rgb", pl->rgb);
	printf("\n");
}

static void	print_cylinder(t_cylinder *cy)
{
	printf("+ CYLINDER\n");
	printf("     - height: %f\n", cy->height);
	printf("     - radius: %f\n", cy->radius);
	print_vec3("point", cy->point);
	print_vec3("axis", cy->axis);
	print_vec3("rgb", cy->rgb);
	printf("\n");
}

static void	print_cone(t_cone *co)
{
	printf("+ CONE\n");
	printf("     - height: %f\n", co->height);
	printf("     - theta (half angle): %f\n", co->theta);
	print_vec3("apex", co->apex);
	print_vec3("axis", co->axis);
	print_vec3("rgb", co->rgb);
	printf("\n");
}

static void	scene_object_info(t_object **head)
{
	t_object	*curr;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr)
	{
		if (curr->type == OBJ_SPHERE)
			print_sphere(&curr->data.sphere);
		else if (curr->type == OBJ_PLANE)
			print_plane(&curr->data.plane);
		else if (curr->type == OBJ_CYLINDER)
			print_cylinder(&curr->data.cylinder);
		else if (curr->type == OBJ_CONE)
			print_cone(&curr->data.cone);
		curr = curr->next;
	}
}

static void	print_camera(t_camera *cam)
{
	printf("+ CAMERA\n");
	printf("     - fov: %f\n", cam->fov);
	print_vec3("point", cam->point);
	print_vec3("forward", cam->basis.forward);
	print_vec3("right", cam->basis.right);
	print_vec3("up", cam->basis.up);
	printf("\n");
}

static void	print_light(t_light *light)
{
	printf("     - ratio: %f\n", light->ratio);
	print_vec3("point", light->point);
	print_vec3("rgb", light->rgb);
}

static void	scene_light_info(t_light **head)
{
	t_light	*curr;

	if (!head || !*head)
	{
		printf("+ LIGHT: none\n\n");
		return ;
	}
	curr = *head;
	while (curr)
	{
		printf("+ LIGHT\n");
		print_light(curr);
		printf("\n");
		curr = curr->next;
	}
}

void	scene_info(t_scene *scene)
{
	if (!scene)
		return ;
	printf("=== SCENE INFO ===\n\n");
	if (scene->amb.ratio > 0.0f)
	{
		printf("+ AMBIENT LIGHT\n");
		print_vec3("rgb", scene->amb.rgb);
		printf("\n");
	}
	print_camera(&scene->cam);
	scene_light_info(&scene->lights);
	scene_object_info(&scene->objects);
}
