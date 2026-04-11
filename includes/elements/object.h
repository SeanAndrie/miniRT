/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:49:47 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:42:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <libft.h>
# include <libvec3.h>

/*---------------------------------------------------------------------*/
/*                      1. SCENE OBJECTS                               */
/*---------------------------------------------------------------------*/

typedef struct s_array	t_array;
typedef struct s_image	t_texture;

typedef struct s_options
{
	float				cb_scale;
	float				reflectivity;
	char				*texture_path;
	t_texture			*texture;
	char				*bump_path;
	t_texture			*bump_texture;
	char				*specularity;
}						t_options;

typedef struct s_sphere
{
	float				radius;
	struct s_vec3		center;
	struct s_vec3		rgb;
}						t_sphere;

typedef struct s_plane
{
	struct s_vec3		point;
	struct s_vec3		normal;
	struct s_vec3		rgb;
}						t_plane;

typedef struct s_cylinder
{
	float				height;
	float				radius;
	struct s_vec3		point;
	struct s_vec3		axis;
	struct s_vec3		rgb;
}						t_cylinder;

typedef struct s_cone
{
	float				height;
	float				theta;
	struct s_vec3		apex;
	struct s_vec3		axis;
	struct s_vec3		rgb;
	float				k2;
	float				k;
}						t_cone;

typedef enum e_type
{
	OBJ_PLANE,
	OBJ_SPHERE,
	OBJ_CYLINDER,
	OBJ_CONE,
	OBJ_UNKNOWN,
}						t_type;

typedef union u_data
{
	struct s_cone		cone;
	struct s_plane		plane;
	struct s_sphere		sphere;
	struct s_cylinder	cylinder;
}						t_data;

typedef struct s_object
{
	enum e_type			type;
	union u_data		data;
	struct s_options	opt;
	struct s_object		*next;
}						t_object;

/*---------------------------------------------------------------------*/
/*                  2. SCENE OBJECT LIST OPERATIONS                    */
/*---------------------------------------------------------------------*/

void					obj_plane(t_object *obj, t_plane *params);
void					obj_sphere(t_object *obj, t_sphere *params);
void					obj_cylinder(t_object *obj, t_cylinder *params);
void					obj_cone(t_object *obj, t_cone *params);

t_object				*obj_alloc(t_type obj_type);
t_bool					obj_view(t_array *arr, t_object *head);

size_t					obj_len(t_object *head);
t_bool					obj_append(t_object **head, t_object *obj);
t_bool					obj_prepend(t_object **head, t_object *obj);
void					obj_free(t_object **head);

#endif
