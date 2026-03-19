/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuf_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:56:03 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 17:04:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/render.h>

t_tensr	*framebuf_tile(t_tensr *framebuf, t_tile_map *tm)
{
	t_slice	slices[2];

	slices[0] = (t_slice){.axis = 0, .start = tm->ty, .end = tm->ty
		+ tm->actual_h, .step = 1};
	slices[1] = (t_slice){.axis = 1, .start = tm->tx, .end = tm->tx
		+ tm->actual_w, .step = 1};
	return (tensr_slice(framebuf, 2, slices));
}
