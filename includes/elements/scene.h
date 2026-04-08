/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:29:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/08 14:10:55 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <libtensr.h>
# include <object.h>

/*---------------------------------------------------------------------*/
/*                         1. SCENE ELEMENTS                           */
/*---------------------------------------------------------------------*/

typedef struct s_array	t_array;

typedef struct s_basis
{
	struct s_vec3		up;
	struct s_vec3		right;
	struct s_vec3		forward;
	struct s_tensr		*up_t;
	struct s_tensr		*right_t;
	struct s_tensr		*forward_t;
}						t_basis;

typedef struct s_coord
{
	struct s_tensr		*u_range;
	struct s_tensr		*v_range;
}						t_coord;

typedef struct s_rdir
{
	struct s_tensr		*out;
	struct s_tensr		*dir;
	struct s_tensr		*up_s;
	struct s_tensr		*sum_s;
	struct s_tensr		*right_s;
}						t_rdir;

typedef struct s_camera
{
	float				fov;
	struct s_rdir		rdir;
	struct s_vec3		point;
	struct s_basis		basis;
	struct s_coord		coords;
    bool                allocd;
}						t_camera;

typedef struct s_ambient
{
	float				ratio;
	struct s_vec3		rgb;
    bool                allocd;
}						t_ambient;

typedef struct s_light
{
	float				ratio;
	struct s_vec3		rgb;
	struct s_vec3		point;
	struct s_light		*next;
}						t_light;

typedef struct s_scene
{
	struct s_ambient	amb;
	struct s_camera		cam;
	struct s_light		*lights;
	struct s_object		*objects;
	struct s_array		obj_view;
	struct s_array		lgt_view;
}						t_scene;

t_scene					*scene_init(const char *fname, const char *ext);
void					scene_info(t_scene *scene);
void					scene_free(t_scene *scene);

bool					camera_init(t_camera *cam, const int width,
							const int height, const float aspect);
bool					camera_basis(t_camera *cam);
bool					camera_rdir(t_camera *cam);
bool					rdir_init(t_rdir *in, const int width,
							const int height);
bool					camera_coords(t_camera *cam, const int width,
							const int height, const float aspect);

void					camera_free(t_camera *cam);
void					rdir_free(t_rdir *in);
void					basis_free(t_basis *basis);
void					coords_free(t_coord *coords);

bool					light_view(t_array *arr, t_light *head);
bool					light_append(t_light **head, t_light *light);
bool					light_prepend(t_light **head, t_light *light);
size_t					light_len(t_light *head);
void					light_free(t_light **head);

#endif
