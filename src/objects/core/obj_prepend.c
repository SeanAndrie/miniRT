/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_prepend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:50:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:34:50 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>

t_bool obj_prepend(t_object **head, t_object *obj)
{
	if (!obj)
		return (FALSE);
	obj->next = *head;
	return (TRUE);
}
