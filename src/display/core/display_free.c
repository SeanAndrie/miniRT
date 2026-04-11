/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:49:20 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 22:25:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <mlx.h>
#include <setup/display.h>

void	display_free(t_display *disp)
{
	if (!disp || !disp->conn)
		return ;
	frame_free(&disp->frame);
	if (disp->image.image)
		mlx_destroy_image(disp->conn, disp->image.image);
	if (disp->window)
		mlx_destroy_window(disp->conn, disp->window);
	mlx_destroy_display(disp->conn);
	free(disp->conn);
	free(disp);
}
