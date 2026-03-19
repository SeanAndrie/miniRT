/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:49:47 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 03:04:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <libtensr_rt.h>

/*---------------------------------------------------------------------*/
/*                      1. SCENE OBJECTS                               */
/*---------------------------------------------------------------------*/

typedef struct s_sphere
{
	float				radius;
	t_vec3				center;
	t_vec3				rgb;
}						t_sphere;

typedef struct s_plane
{
	t_vec3				point;
	t_vec3				normal;
	t_vec3				rgb;
}						t_plane;

typedef struct s_cylinder
{
	float				height;
	float				radius;
	t_vec3				point;
	t_vec3				axis;
	t_vec3				rgb;
}						t_cylinder;

typedef enum e_type
{
	OBJ_PLANE,
	OBJ_SPHERE,
	OBJ_CYLINDER,
	OBJ_UNKNOWN,
}						t_type;

typedef union u_data
{
	struct s_plane		plane;
	struct s_sphere		sphere;
	struct s_cylinder	cylinder;
}						t_data;

typedef struct s_object
{
	enum e_type			type;
	union u_data		data;
	struct s_object		*next;
}						t_object;

/*---------------------------------------------------------------------*/
/*                  2. SCENE OBJECT LIST OPERATIONS                    */
/*---------------------------------------------------------------------*/

void					obj_plane(t_object *obj, t_plane *params);
void					obj_sphere(t_object *obj, t_sphere *params);
void					obj_cylinder(t_object *obj, t_cylinder *params);

bool					obj_append(t_object **head, t_object *obj);
bool					obj_prepend(t_object **head, t_object *obj);

void					obj_data_free(t_object *obj);
void					obj_free(t_object **head);
t_object				*obj_alloc(t_type obj_type);

#endif
