/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:47:39 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:34:42 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/object.h>

void	obj_data_free(t_object *obj)
{
	if (!obj)
		return ;
	if (obj->type == OBJ_SPHERE)
	{
		tensr_free(obj->data.sphere.center);
		tensr_free(obj->data.sphere.rgb);
	}
	else if (obj->type == OBJ_PLANE)
	{
		tensr_free(obj->data.plane.point);
		tensr_free(obj->data.plane.normal);
		tensr_free(obj->data.plane.rgb);
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		tensr_free(obj->data.cylinder.point);
		tensr_free(obj->data.cylinder.axis);
		tensr_free(obj->data.cylinder.rgb);
	}
}

void    obj_free(t_object **head)
{
    t_object *next;

    while (*head)
    {
        next = (*head)->next;
		obj_data_free(*head);
        free(*head);
        *head = next;
    }
}
