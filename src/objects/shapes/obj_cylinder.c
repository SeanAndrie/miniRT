/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:41:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:31:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>

void    obj_cylinder(t_object *obj, t_cylinder *params)
{
    if (!obj || !params)
        return ;
    obj->data.cylinder = *params;
}
