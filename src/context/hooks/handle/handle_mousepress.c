/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mousepress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:58:35 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 18:49:53 by sgadinga         ###   ########.fr       */
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

static	void object_select(int x, int y, t_context *ctx)
{
    t_camera    *cam;
	t_ray	    ray;
	t_hit	    hit;

    ctx->s_lgt = NULL;
    cam = &ctx->scene->cam;
	// ray = ray_create(&ctx->scene->cam, x, y);
    ray = ray_create(cam->point, cam->rdir.out, x, y);
    if (!render_trace(ray, &hit, ctx->scene))
        return ;
    ctx->s_obj = hit.obj;
    print_type(hit.obj);
}

int	handle_mousepress(int button, int x, int y, t_context *ctx)
{
	if (button == MOUSE_RIGHT)
    {
		ctx->s_obj = NULL;
        ctx->s_lgt = NULL;
    }
	if (button == MOUSE_LEFT)
        object_select(x, y, ctx);
	return (0);
}
