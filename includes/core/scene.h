/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:29:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 03:04:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <core/object.h>

/*---------------------------------------------------------------------*/
/*                         1. SCENE ELEMENTS                           */
/*---------------------------------------------------------------------*/

typedef struct s_basis
{
	t_vec3				up;
	t_vec3				right;
	t_vec3				forward;
}						t_basis;

typedef struct s_camera
{
    struct s_tensr      *u;
    struct s_tensr      *v;
	float				fov;
	t_vec3				point;
	struct s_basis		basis;
}						t_camera;

typedef struct s_ambient
{
	float				ratio;
	t_vec3				rgb;
}						t_ambient;

typedef struct s_light
{
	float				ratio;
	t_vec3				rgb;
	t_vec3				point;
}						t_light;

typedef struct s_scene
{
	struct s_ambient	amb;
	struct s_camera		cam;
	struct s_light		light;
	struct s_object		*head;
}						t_scene;

void					scene_free(t_scene *scene);
void					scene_info(t_scene *scene);
t_scene					*scene_init(const char *fname, const char *ext);

#endif
