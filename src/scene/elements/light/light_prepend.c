/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_prepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:02:58 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 00:05:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <libft.h>
#include <libvec3.h>

t_bool	light_prepend(t_light **head, t_light *light)
{
	if (!light)
		return (FALSE);
	light->next = *head;
	return (TRUE);
}
