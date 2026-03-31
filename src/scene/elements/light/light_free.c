/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 00:18:36 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 00:20:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <elements/scene.h>

void    light_free(t_light **head)
{
    t_light *next;

    while (*head)
    {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
}
