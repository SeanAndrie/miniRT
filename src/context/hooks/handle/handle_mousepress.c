/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mousepress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:58:35 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/06 03:20:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>
#include <core/render.h>
#include <libtensr.h>
#include <mlx.h>

static void	print_type(t_object *obj)
{
	if (!obj)
		return ;
	if (obj->type == OBJ_SPHERE)
		ft_printf("Sphere");
	if (obj->type == OBJ_PLANE)
		ft_printf("Plane");
	if (obj->type == OBJ_CYLINDER)
		ft_printf("Cylinder");
	if (obj->type == OBJ_CONE)
		ft_printf("Cone");
	ft_printf("\n");
}

static void	dispatch_selection(t_object *obj, t_context *ctx)
{
	ctx->tw_rotate.curr = NULL;
	if (!obj)
	{
		ctx->tw_trans = tween_translation(&ctx->scene->cam.point);
		return ;
	}
	if (obj->type == OBJ_SPHERE)
		ctx->tw_trans = tween_translation(&obj->data.sphere.center);
	else if (obj->type == OBJ_PLANE)
		ctx->tw_trans = tween_translation(&obj->data.plane.point);
	else if (obj->type == OBJ_CYLINDER)
	{
		ctx->tw_trans = tween_translation(&obj->data.cylinder.point);
		ctx->tw_rotate = tween_rotation(&obj->data.cylinder.axis);
	}
	else if (obj->type == OBJ_CONE)
	{
		ctx->tw_trans = tween_translation(&obj->data.cone.apex);
		ctx->tw_rotate = tween_rotation(&obj->data.cone.axis);
	}
}

static void	object_select(int x, int y, t_context *ctx)
{
	t_ray		ray;
	t_hit		hit;
	t_camera	*cam;

	cam = &ctx->scene->cam;
	ray = ray_create(cam->point, cam->rdir.out, x, y);
	if (!render_trace(ray, &hit, ctx->scene))
		return ;
	ctx->s_obj = hit.obj;
	dispatch_selection(ctx->s_obj, ctx);
	print_type(hit.obj);
}

int	handle_mousepress(int button, int x, int y, t_context *ctx)
{
	if (button == MOUSE_RIGHT)
	{
		ctx->s_obj = NULL;
		ctx->s_lgt = NULL;
		ctx->tw_rotate.curr = NULL;
		ctx->tw_trans = tween_translation(&ctx->scene->cam.point);
        ctx->property = false;
	}
	if (button == MOUSE_LEFT)
    {
        ctx->s_lgt = NULL;
		object_select(x, y, ctx);
    }
    ctx->dirty = true;
	return (0);
}
