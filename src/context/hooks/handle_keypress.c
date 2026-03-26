/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:47:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 01:20:07 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>
#include <core/render.h>
#include <libtensr_rt.h>
#include <mlx.h>

static bool	translation_keys(int key_code)
{
	return (key_code == XK_a || key_code == XK_s || key_code == XK_w
		|| key_code == XK_d || key_code == XK_q || key_code == XK_e);
}

int	handle_translate(int key_code, t_vec3 *v, t_basis *b, float speed)
{
	if (key_code == XK_w)
		vec3_add_ip(v, vec3_scale(b->forward, speed));
	if (key_code == XK_s)
		vec3_add_ip(v, vec3_scale(b->forward, -speed));
	if (key_code == XK_a)
		vec3_add_ip(v, vec3_scale(b->right, -speed));
	if (key_code == XK_d)
		vec3_add_ip(v, vec3_scale(b->right, speed));
	if (key_code == XK_q)
		vec3_add_ip(v, vec3_scale(b->up, speed));
	if (key_code == XK_e)
		vec3_add_ip(v, vec3_scale(b->up, -speed));
	return (0);
}

static void	translate_dispatch(int key_code, t_context *ctx, float speed)
{
	t_object	*obj;
	t_camera	*cam;
	t_basis		*basis;

	obj = ctx->select;
	cam = &ctx->scene->cam;
	basis = &ctx->scene->cam.basis;
	if (!obj)
	{
		handle_translate(key_code, &cam->point, basis, speed);
		return ;
	}
	if (obj->type == OBJ_SPHERE)
		handle_translate(key_code, &obj->data.sphere.center, basis, speed);
	else if (obj->type == OBJ_CYLINDER)
		handle_translate(key_code, &obj->data.cylinder.point, basis, speed);
	else if (obj->type == OBJ_CONE)
		handle_translate(key_code, &obj->data.cone.apex, basis, speed);
}

int	handle_keypress(int key_code, t_context *ctx)
{
	if (key_code == XK_Esc)
	{
		context_free(ctx);
		exit(EXIT_SUCCESS);
	}
	if (key_code == XK_r)
	{
		scene_free(ctx->scene);
		ctx->scene = scene_init(ctx->fname, SCENE_FILE_EXT);
		if (ctx->scene)
		{
			render_init(ctx->disp, ctx->scene);
			render(ctx->disp, ctx->scene);
		}
	}
	if (translation_keys(key_code))
	{
		translate_dispatch(key_code, ctx, 1.0f);
		render(ctx->disp, ctx->scene);
	}
	return (0);
}
