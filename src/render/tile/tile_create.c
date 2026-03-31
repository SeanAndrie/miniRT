/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:06:17 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 18:22:43 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libtensr.h>

bool	tile_create(t_tile *tile, t_tensr *buffer, t_tensr *rdir,
		t_tile_map *tm)
{
	t_slice	*slices;

	if (!tile || !buffer || !rdir || !tm)
		return (false);
	slices = (t_slice[]){(t_slice){.axis = 0, .start = tm->ty, .end = tm->ty
		+ tm->actual_h, .step = 1}, (t_slice){.axis = 1, .start = tm->tx,
		.end = tm->tx + tm->actual_w, .step = 1}};
	tile->buffer = tensr_slice(buffer, 2, slices);
    if (!tile->buffer)
        return (false);
    tile->rdir = tensr_slice(rdir, 2, slices);
    if (!tile->rdir)
    {
        tensr_free(tile->buffer);
        return (false);
    }
    return (true);
}
