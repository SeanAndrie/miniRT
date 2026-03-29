/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   property_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:24:01 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 19:08:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

bool	property_keys(int key_code)
{
	return (key_code == XK_r || key_code == XK_h || key_code == XK_t);
}
