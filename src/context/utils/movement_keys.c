/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:55:12 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 13:13:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

t_bool	movement_keys(int key_code)
{
	return (key_code == XK_A || key_code == XK_S || key_code == XK_W
		|| key_code == XK_D || key_code == XK_Q || key_code == XK_E);
}
