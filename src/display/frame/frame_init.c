/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 00:52:49 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 00:52:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <setup/display.h>

static t_tile_dim	calculate_tile_dims(const int width, const int height)
{
	t_tile_dim	dim;

	dim.width = ft_max(1, width / (int)sqrtf(N_TILES));
	dim.height = ft_max(1, height / (int)sqrtf(N_TILES));
	dim.count_x = (width + dim.width - 1) / dim.width;
	dim.count_y = (height + dim.height - 1) / dim.height;
	dim.count = dim.count_x * dim.count_y;
	return (dim);
}

t_bool	frame_init(t_frame *frame, const int width, const int height)
{
	int		ndim;
	size_t	*shape;

	if (!frame)
		return (FALSE);
	ndim = 3;
	shape = (size_t[]){height, width, 3};
	frame->buffer = tensr_full(0.0, ndim, shape, DT_F32);
	if (!frame->buffer)
		return (FALSE);
	frame->clamped = tensr_full(0.0, ndim, shape, DT_F32);
	if (!frame->clamped)
		return (frame_free(frame), FALSE);
	frame->scaled = tensr_full(0.0, ndim, shape, DT_F32);
	if (!frame->scaled)
		return (frame_free(frame), FALSE);
	frame->out = tensr_full(0, ndim, shape, DT_U8);
	if (!frame->out)
		return (frame_free(frame), FALSE);
	frame->tile_dim = calculate_tile_dims(width, height);
	return (TRUE);
}
