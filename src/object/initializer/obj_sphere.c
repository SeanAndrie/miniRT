/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:32:50 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:32:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>

void    obj_sphere(t_object *obj, t_sphere *params)
{
    if (!obj || !params)
        return ;
    obj->data.sphere = *params;
}
