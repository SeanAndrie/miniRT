/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:20:48 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 23:39:07 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/display.h>
#include <math.h>

static t_tile_dim calculate_tile_dims(const int width, const int height)
{
    t_tile_dim  dim;

    dim.w = ft_max(1, width / (int)sqrtf(N_TILES));
    dim.h = ft_max(1, height / (int)sqrtf(N_TILES));
    dim.count_x = (width + dim.w - 1) / dim.w;
    dim.count_y = (height + dim.h - 1) / dim.h;
    dim.count = dim.count_x * dim.count_y;
    return (dim);
}

bool    frame_init(t_frame *frame, const int width, const int height)
{
    int     ndim;
    size_t  *shape;

    if (!frame)
        return (false);
    ndim = 3;
    shape = (size_t[]){height, width, 3};
    frame->buffer = tensr_full(0.0, ndim, shape, DT_F32);
    if (!frame->buffer)
        return (false);
    frame->clamped = tensr_full(0.0, ndim, shape, DT_F32);
    if (!frame->clamped)
        return (frame_free(frame), false);
    frame->scaled = tensr_full(0.0, ndim, shape, DT_F32);
    if (!frame->scaled)
        return (frame_free(frame), false);
    frame->out = tensr_full(0, ndim, shape, DT_U8);
    if (!frame->out)
        return (frame_free(frame), false);
    frame->tile_dim = calculate_tile_dims(width, height);
    return (true);
}
