/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mousepress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:58:35 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 00:46:37 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libtensr.h>
#include <core/render.h>
#include <core/context.h>

static void print_type(t_object *obj)
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

int handle_mousepress(int button, int x, int y, t_context *ctx)
{
    t_ray   ray;
    t_hit   hit;

    if (button == MOUSE_LEFT)
    {
        ray = ray_create(&ctx->scene->cam, x, y);
        if (render_trace(&ray, &hit, ctx->scene))
        {
            ctx->select = hit.obj;
            print_type(hit.obj);
        }
    }
    if (button == MOUSE_RIGHT)
        ctx->select = NULL;
    return (0);
}
