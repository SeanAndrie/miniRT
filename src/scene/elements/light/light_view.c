/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:31:00 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 19:51:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <libtensr.h>

t_bool	light_view(t_array *arr, t_light *head)
{
	size_t	i;
	t_light	*curr;

	if (!arr || !head)
		return (FALSE);
	arr->len = light_len(head);
	arr->data = malloc(sizeof(t_light *) * arr->len);
	if (!arr->data)
		return (FALSE);
	i = 0;
	curr = head;
	while (curr && i < arr->len)
	{
		((t_light **)arr->data)[i++] = curr;
		curr = curr->next;
	}
	arr->dtype = DT_CUSTOM;
	return (TRUE);
}
