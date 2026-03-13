/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:49:47 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 20:38:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_tensr	t_tensr;

/*---------------------------------------------------------------------*/
/*                      1. SCENE OBJECTS                               */
/*---------------------------------------------------------------------*/

typedef struct s_sphere
{
	double radius;          // Sphere Radius
	struct s_tensr *center; // Coordinates of sphere center
	struct s_tensr *rgb;    // RGB Colors
}						t_sphere;

typedef struct s_plane
{
	struct s_tensr *point;  // Coordinates of point in plane
	struct s_tensr *normal; // Normalized normal vector
	struct s_tensr *rgb;    // RGB Colors
}						t_plane;

typedef struct s_cylinder
{
	double height;         // Cylinder Height
	double radius;         // Cylinder Radius
	struct s_tensr *point; // Coordinates of cylinder center
	struct s_tensr *axis;  // Normalized axis vector of cylinder
	struct s_tensr *rgb;   // RGB Colors
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

void	                obj_data_free(t_object *obj);
void					obj_free(t_object **head);
t_object				*obj_alloc(t_type obj_type);

#endif
