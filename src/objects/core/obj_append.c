/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:45:49 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:34:24 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>

bool	obj_append(t_object **head, t_object *obj)
{
	t_object	*last;

	if (!obj)
		return (false);
	if (!*head)
	{
		*head = obj;
		return (true);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = obj;
	return (true);
}
