/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isect_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:06:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 18:54:11 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

float	isect_obj(t_ray *ray, t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
		return (isect_sphere(ray, &obj->data.sphere));
	else if (obj->type == OBJ_PLANE)
		return (isect_plane(ray, &obj->data.plane));
	else if (obj->type == OBJ_CYLINDER)
		return (isect_cylinder(ray, &obj->data.cylinder));
	else if (obj->type == OBJ_CONE)
		return (isect_cone(ray, &obj->data.cone));
	return (0.0f);
}
