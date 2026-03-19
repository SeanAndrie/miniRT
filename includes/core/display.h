/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:29:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 11:09:28 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define W 1920
# define H 1080
# define TITLE "miniRT"
# define TARGET_TILES 64

typedef struct s_tensr	t_tensr;

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

bool					display_init(t_display *dis, const int width,
							const int height, char *title);
void					display_free(t_display *dis);

#endif
