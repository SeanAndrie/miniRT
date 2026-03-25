/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:34:30 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 00:04:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <elements/object.h>

t_object	*obj_alloc(t_type obj_type)
{
	t_object	*obj;

	if (obj_type == OBJ_UNKNOWN)
		return (NULL);
	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->type = obj_type;
	obj->next = NULL;
	return (obj);
}
