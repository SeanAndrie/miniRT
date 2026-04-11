/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:34:30 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/05 17:33:24 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <libft.h>

t_object	*obj_alloc(t_type obj_type)
{
	t_object	*obj;

	if (obj_type == OBJ_UNKNOWN)
		return (NULL);
	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	ft_memset(&obj->opt, 0, sizeof(t_options));
	obj->type = obj_type;
	obj->next = NULL;
	return (obj);
}
