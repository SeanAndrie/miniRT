/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:13:39 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 19:40:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>

size_t	light_len(t_light *head)
{
	size_t	len;
	t_light	*curr;

	len = 0;
	curr = head;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
