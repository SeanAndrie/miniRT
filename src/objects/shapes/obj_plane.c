/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:40:09 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:32:02 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>

void    obj_plane(t_object *obj, t_plane *params)
{
    if (!obj || !params)
        return ;
    obj->data.plane = *params;
}
