/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:29:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 16:31:03 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define N_TILES 128

# define TITLE "miniRT"
# define W 800
# define H 600

# include <libft.h>
# include <libtensr.h>
# include <mlx.h>

typedef struct s_tile_dim
{
	int					width;
	int					height;
	int					count;
	int					count_x;
	int					count_y;
}						t_tile_dim;

typedef struct s_image
{
	void				*image;
	char				*addr;
	int					bpp;
	int					endian;
	int					line_len;
	int					width;
	int					height;
}						t_image;

typedef struct s_frame
{
	struct s_tensr		*out;
	struct s_tensr		*buffer;
	struct s_tensr		*scaled;
	struct s_tensr		*clamped;
	struct s_tile_dim	tile_dim;
}						t_frame;

typedef struct s_display
{
	struct s_image		image;
	struct s_frame		frame;
	void				*conn;
	int					width;
	int					height;
	float				aspect;
	void				*window;
}						t_display;

t_display				*display_init(const int width, const int height);
void					display_free(t_display *disp);
bool					frame_init(t_frame *frame, const int width,
							const int height);
bool				    frame_blit(t_display *disp);
void					frame_free(t_frame *frame);

#endif
