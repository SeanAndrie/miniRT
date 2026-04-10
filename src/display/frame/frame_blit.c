/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_blit.c                                       :+:      :+:    ::::   */
/*                                                    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#  +:     +#           */
/*                                                +#    +#    +#            */
/*   Created: 2026/03/24 23:27:50 by sgadinga          #+#   #+    #+#        */
/*   Updated: 2026/03/31 00:38:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <mlx.h>
#include <setup/display.h>

static inline unsigned int	rgb_to_argb(const uint8_t *src)
{
	return ((0xFF << 24) | (src[0] << 16) | (src[1] << 8) | src[2]);
}

static void	tensr_blit(t_tensr *src, t_image *img)
{
	size_t			x;
	size_t			y;
	uint8_t			*s_ptr;
	char			*d_row;
	unsigned int	*d_pixel;

	s_ptr = (uint8_t *)src->data;
	d_row = (char *)img->addr;
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
		d_row += img->line_len;
		y++;
	}
}

t_bool frame_blit(t_display *disp)
{
    t_frame *frame;

    if (!disp)
        return (FALSE);
    frame = &disp->frame;
    if (!tensr_clamp(frame->buffer, 0.0, 1.0, frame->clamped))
        return (FALSE);
    if (!tensr_scale(frame->clamped, 255.0, frame->scaled))
        return (frame_free(&disp->frame), FALSE);
    if (!tensr_cast(frame->scaled, DT_U8, frame->out))
        return (frame_free(&disp->frame), FALSE);
    tensr_blit(frame->out, &disp->image);
	return (TRUE);
}
