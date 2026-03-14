/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:21:25 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/14 01:36:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <mlx.h>
# include <stddef.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "miniRT"

typedef struct s_tensr t_tensr;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				endian;
	int				line_len;
}					t_img;

typedef struct s_mlx
{
    t_img           img;
    void            *win;
	void			*conn;
    t_tensr         *img_v;
}					t_mlx;

void    mlx_free(t_mlx *mlx);

bool    image_init(t_mlx *mlx, const int height, const int width);
bool    window_init(t_mlx *mlx, const int width, const int height, char *title);

#endif
