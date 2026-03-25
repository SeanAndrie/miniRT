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

#include <libft.h>
#include <libtensr_rt.h>
#include <elements/scene.h>

bool    light_prepend(t_light **head, t_light *light)
{
    if (!light)
        return (false);
    light->next = *head;
    return (true);
}
