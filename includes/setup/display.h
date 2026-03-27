/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:29:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 03:56:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define TARGET_TILES 32

# define TITLE "miniRT"
# define W 800
# define H 600

# include <mlx.h>
# include <libtensr.h>

typedef struct s_image
{
	void				*image;
	char				*addr;
	int					bpp;
	int					endian;
	int					line_len;
}						t_image;

typedef struct s_tiles
{
	int					w;
	int					h;
	int					count;
	int					count_x;
	int					count_y;
}						t_tiles;

typedef struct s_dim
{
	int					width;
	int					height;
	float               aspect;
}						t_dim;

typedef struct s_display
{
	struct s_dim		dim;
	struct s_tiles		tiles;
	struct s_image		image;
	void				*conn;
	void				*window;
	t_tensr				*framebuf;
}						t_display;

t_display               *display_init(const int width,
							const int height, char *title);
void					display_free(t_display *disp);

#endif
