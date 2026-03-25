/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:29:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 00:22:44 by sgadinga         ###   ########.fr       */
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
	struct s_vec3		up;
	struct s_vec3		right;
	struct s_vec3		forward;
}						t_basis;

typedef struct s_dev_coord
{
	struct s_tensr		*u_range;
	struct s_tensr		*v_range;
}						t_dev_coord;

typedef struct s_camera
{
	float				fov;
	struct s_vec3		point;
	struct s_basis		basis;
	struct s_dev_coord	coords;
	struct s_tensr		*ray_dirs;
}						t_camera;

typedef struct s_ambient
{
	float				ratio;
	struct s_vec3		rgb;
}						t_ambient;

typedef struct s_light
{
	float				ratio;
	struct s_vec3		rgb;
	struct s_vec3		point;
    struct s_light      *next;
}						t_light;

typedef struct s_scene
{
	struct s_ambient	amb;
	struct s_camera		cam;
	struct s_light		*lights;
	struct s_object		*objects;
}						t_scene;

void					coords_free(t_dev_coord *coords);
void					scene_free(t_scene *scene);
void					scene_info(t_scene *scene);
t_scene					*scene_init(const char *fname, const char *ext);

bool                    light_append(t_light **head, t_light *light);
bool                    light_prepend(t_light **head, t_light *light);
void                    light_free(t_light **head);

#endif
