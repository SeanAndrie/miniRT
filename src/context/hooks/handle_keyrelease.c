/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 03:39:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 03:47:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

int	handle_keyrelease(int key_code, t_context *ctx)
{
	if (key_code == XK_Shift_L)
        ctx->rotate = false;
	return (0);
}
