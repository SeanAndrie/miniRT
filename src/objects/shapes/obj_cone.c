/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:07:05 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 03:03:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/object.h>

void	obj_cone(t_object *obj, t_cone *params)
{
	if (!obj || !params)
		return ;
	obj->data.cone = *params;
}
