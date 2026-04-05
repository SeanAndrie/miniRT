/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:49:40 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/06 03:24:03 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

static void	interface_translate(t_display *disp, const int x, int *y,
		const int line_h)
{
    *y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"+------ TRANSLATION ------+");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"W/S: Forward/Backward");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"A/D: Left/Right");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR, "Q/E: Up/Down");
	*y += line_h;
}

static void	interface_rotation(t_display *disp, const int x, int *y,
		const int line_h)
{
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"+-------- ROTATION --------+");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"W/S: Rotate on right axis");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"A/D: Rotate on up axis");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"Q/E: Rotate on forward axis");
	*y += line_h;
}

static void	interface_general(t_display *disp, const int x, int *y,
		const int line_h)
{
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"+---------- GENERAL ---------+");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"P: Toggle Property Mode");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"L Shift (Hold): Rotation Mode");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR, "R: Reset App");
	*y += line_h;
	mlx_string_put(disp->conn, disp->window, x, *y, TEXT_COLOR,
		"ESC: Close App");
	*y += line_h;
}

void	interface_render(t_context *ctx, const int line_h)
{
	int	y;
	int	x;

	if (!ctx || line_h == 0)
		return ;
	y = 30;
	x = 20;
	interface_object(ctx, x, &y, line_h);
	interface_general(ctx->disp, x, &y, line_h);
	if (!ctx->property)
	{
		if (ctx->extend && !ctx->s_lgt)
			interface_rotation(ctx->disp, x, &y, line_h);
		else
			interface_translate(ctx->disp, x, &y, line_h);
	}
}
