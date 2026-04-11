/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:24:01 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 13:14:02 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

t_bool	property_keys(int key_code)
{
	return (key_code == XK_R || key_code == XK_H || key_code == XK_T);
}
