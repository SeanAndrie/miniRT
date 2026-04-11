/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:02:12 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 02:45:25 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

static void	object_type(t_context *ctx, int x, int *y, const int line_h)
{
	if (!ctx->s_obj)
	{
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"None");
		*y += line_h;
		return ;
	}
	if (ctx->s_obj->type == OBJ_SPHERE)
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"Sphere");
	else if (ctx->s_obj->type == OBJ_PLANE)
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"Plane");
	else if (ctx->s_obj->type == OBJ_CYLINDER)
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"Cylinder");
	else if (ctx->s_obj->type == OBJ_CONE)
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"Cone");
	*y += line_h;
}

static void	property_mode(t_context *ctx, int x, int *y, const int line_h)
{
	if (ctx->property)
	{
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"Property Mode: ON");
	}
	else
	{
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"Property Mode: OFF");
	}
	*y += line_h;
}

static void	object_params(t_context *ctx, int x, int *y, const int line_h)
{
	if (!ctx->s_obj)
		return ;
	if (ctx->s_obj->type == OBJ_SPHERE)
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"(L Shift) + R: Increase/decrease radius");
	if (ctx->s_obj->type == OBJ_CYLINDER)
	{
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"(L Shift) + R: Increase/decrease radius");
		*y += line_h;
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"(L Shift) + H: Increase/decrease height");
	}
	if (ctx->s_obj->type == OBJ_CONE)
	{
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"(L Shift) + R: Increase/decrease radius");
		*y += line_h;
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"(L Shift) + H: Increase/decrease height");
		*y += line_h;
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
			"(L Shift) + T: Increase/decrease theta");
	}
	*y += line_h;
}

static void	light_select(t_context *ctx, int x, int *y, int offset)
{
	char	*s_idx;

	s_idx = ft_itoa(ctx->next_i);
	mlx_string_put(ctx->disp->conn, ctx->disp->window, x + offset, *y,
		TEXT_COLOR, "light [");
	if (s_idx)
	{
		mlx_string_put(ctx->disp->conn, ctx->disp->window, x + offset + 45, *y,
			TEXT_COLOR, s_idx);
		free(s_idx);
	}
	mlx_string_put(ctx->disp->conn, ctx->disp->window, x + offset + 55, *y,
		TEXT_COLOR, "]");
}

void	interface_object(t_context *ctx, int x, int *y, const int line_h)
{
	int	offset;

	offset = 60;
	mlx_string_put(ctx->disp->conn, ctx->disp->window, x, *y, TEXT_COLOR,
		"Selected: ");
	if (!ctx->s_lgt)
	{
		object_type(ctx, x + offset, y, line_h);
		property_mode(ctx, x, y, line_h);
		if (ctx->property)
			object_params(ctx, x, y, line_h);
	}
	else
	{
		light_select(ctx, x, y, offset);
		*y += line_h;
	}
}
