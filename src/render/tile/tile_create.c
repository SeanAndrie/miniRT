/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:06:17 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 04:35:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libtensr.h>

t_bool	tile_create(t_tile *tile, t_tensr *buffer, t_tensr *rdir,
		t_tile_map *tm)
{
	t_slice	*slices;

	if (!tile || !buffer || !rdir || !tm)
		return (FALSE);
	slices = (t_slice[]){(t_slice){.axis = 0, .start = tm->ty, .end = tm->ty
		+ tm->actual_h, .step = 1}, (t_slice){.axis = 1, .start = tm->tx,
		.end = tm->tx + tm->actual_w, .step = 1}};
	tile->buffer = tensr_slice(buffer, 2, slices);
	if (!tile->buffer)
		return (FALSE);
	tile->rdir = tensr_slice(rdir, 2, slices);
	if (!tile->rdir)
	{
		tensr_free(tile->buffer);
		return (FALSE);
	}
	tile->width = tm->actual_w;
	tile->height = tm->actual_h;
	return (TRUE);
}
