/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:07:35 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:21:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>
#include <libtensr.h>
#include <scene.h>

void    light_free(t_light *light)
{
    if (!light)
        return ;
    if (light->point)
    {
        tensr_free(light->point);
        light->point = NULL;
    }
    if (light->rgb)
    {
        tensr_free(light->rgb);
        light->rgb = NULL;
    }
}
