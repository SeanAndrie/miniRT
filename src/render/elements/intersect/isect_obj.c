/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isect_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:06:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 17:07:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

float	isect_obj(t_ray *ray, t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
		return (isect_sphere(ray, &obj->data.sphere));
	return (0.0);
}
