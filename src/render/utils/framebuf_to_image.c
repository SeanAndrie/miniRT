/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuf_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:14:19 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 13:23:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libtensr.h>

static t_tensr	*postprocess_framebuf(t_tensr *framebuf)
{
	t_tensr	*out;
	t_tensr	*scaled;
	t_tensr	*clamped;

	clamped = tensr_clamp(framebuf, 0.0, 1.0);
	if (!clamped)
		return (false);
	scaled = tensr_scale(clamped, 255.0);
	tensr_free(clamped);
	out = tensr_cast(scaled, DT_U8);
	tensr_free(scaled);
	return (out);
}

bool	framebuf_to_image(t_display *disp)
{
	int		i;
	uint8_t	*src;
	char	*dst;
	t_tensr	*out;

	out = postprocess_framebuf(disp->framebuf);
	if (!out)
		return (false);
	src = (uint8_t *)out->data;
	dst = disp->image.addr;
	i = 0;
	while (i < disp->dim.width * disp->dim.height)
	{
		*(unsigned int *)(dst + i * (disp->image.bpp
					/ 8)) = (0xFF << 24) | (src[i * 3 + 0] << 16) | (src[i * 3
				+ 1] << 8) | (src[i * 3 + 2]);
        i++;
	}
    tensr_free(out);
    return (true);
}
