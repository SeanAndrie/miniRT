/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:11:38 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 15:38:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>

size_t	obj_len(t_object *head)
{
	size_t		len;
	t_object	*curr;

	len = 0;
	curr = head;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
