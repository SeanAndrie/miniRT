/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:59:40 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 00:01:34 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libtensr_rt.h>
#include <core/scene.h>

bool    light_append(t_light **head, t_light *light)
{
    t_light *last;

    if (!light)
        return (false);
    if (!*head)
    {
        *head = light;
        return (true);
    }
    last = *head;
    while (last->next)
        last = last->next;
    last->next = light;
    return (true);
}
