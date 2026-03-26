/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuf_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:27:50 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 00:37:37 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libtensr.h>
#include <mlx.h>

static inline unsigned int	rgb_to_argb(const uint8_t *src)
{
	return ((0xFF << 24) | (src[0] << 16) | (src[1] << 8) | src[2]);
}

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

static void	tensr_blit(t_tensr *src, char *dst, int line_len)
{
	size_t			x;
	size_t			y;
	uint8_t			*s_ptr;
	char			*d_row;
	unsigned int	*d_pixel;

	s_ptr = (uint8_t *)src->data;
	d_row = dst;
	y = 0;
	while (y < src->layout.shape[0])
	{
		x = 0;
		d_pixel = (unsigned int *)d_row;
		while (x < src->layout.shape[1])
		{
			*d_pixel = rgb_to_argb(s_ptr);
			s_ptr += 3;
			d_pixel++;
			x++;
		}
		d_row += line_len;
		y++;
	}
}

bool	framebuf_to_image(t_display *disp)
{
	t_tensr	*out;

	out = postprocess_framebuf(disp->framebuf);
	if (!out)
		return (false);
	tensr_blit(out, disp->image.addr, disp->image.line_len);
	tensr_free(out);
	return (true);
}
