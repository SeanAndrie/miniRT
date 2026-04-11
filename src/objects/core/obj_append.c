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

#include <elements/object.h>

t_bool	obj_append(t_object **head, t_object *obj)
{
	t_object	*last;

	if (!obj)
		return (FALSE);
	if (!*head)
	{
		*head = obj;
		return (TRUE);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = obj;
	return (TRUE);
}
