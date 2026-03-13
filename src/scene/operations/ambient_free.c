/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:15:01 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 20:19:50 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/scene.h>
#include <core/object.h>

void    ambient_free(t_ambient *ambient)
{
    if (!ambient)
        return ;
    if (ambient->rgb)
    {
        tensr_free(ambient->rgb);
        ambient->rgb = NULL;
    }
}
