/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:34:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 19:47:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <elements/object.h>

t_bool obj_view(t_array *arr, t_object *head)
{
	size_t		i;
	t_object	*curr;

	if (!arr || !head)
		return (FALSE);
	arr->len = obj_len(head);
	arr->data = malloc(sizeof(t_object *) * arr->len);
	if (!arr->data)
		return (FALSE);
	curr = head;
	i = 0;
	while (curr && i < arr->len)
	{
		((t_object **)arr->data)[i++] = curr;
		curr = curr->next;
	}
	arr->dtype = DT_CUSTOM;
	return (TRUE);
}
