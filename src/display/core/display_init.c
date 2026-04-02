/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :(        :+    */
/*                                                    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#  +:     +#           */
/*                                                +#    +#    +#            */
/*   Created: 2026/03/15 15:40:27 by sgadinga          #+#   #+    #+#        */
/*   Updated: 2026/03/30 23:30:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <libft.h>
#include <libtensr.h>
#include <setup/display.h>

t_display	*display_init(const int width, const int height)
{
	t_display	*disp;

	disp = malloc(sizeof(t_display));
	if (!disp)
		return (NULL);
	disp->conn = mlx_init();
	if (!disp->conn)
		return (NULL);
	disp->window = mlx_new_window(disp->conn, width, height, TITLE);
	if (!disp->window)
		return (display_free(disp), NULL);
	disp->image.image = mlx_new_image(disp->conn, width, height);
	if (!disp->image.image)
		return (display_free(disp), NULL);
	disp->image.addr = mlx_get_data_addr(disp->image.image, &disp->image.bpp,
			&disp->image.line_len, &disp->image.endian);
	if (!disp->image.addr)
		return (display_free(disp), NULL);
	disp->width = width;
	disp->height = height;
	disp->aspect = (float)width / (float)height;
	return (disp);
}
