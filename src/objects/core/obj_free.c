/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 01:35:50 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:35:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>

void	obj_free(t_object **head)
{
	t_object	*next;

	while (*head)
	{
		next = (*head)->next;
		if ((*head)->opt.texture)
			free((*head)->opt.texture);
		if ((*head)->opt.texture_path)
			free((*head)->opt.texture_path);
		if ((*head)->opt.bump_texture)
			free((*head)->opt.bump_texture);
		if ((*head)->opt.bump_path)
			free((*head)->opt.bump_path);
		free(*head);
		*head = next;
	}
}
