/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemet_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:55:12 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 15:55:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

bool	movement_keys(int key_code)
{
	return (key_code == XK_a || key_code == XK_s || key_code == XK_w
		|| key_code == XK_d || key_code == XK_q || key_code == XK_e);
}
