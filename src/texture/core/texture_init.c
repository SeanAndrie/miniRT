/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 00:58:14 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/11 01:37:40 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context.h>
#include <setup/texture.h>

void	texture_init(t_context *ctx)
{
	t_object	*obj;

	obj = ctx->scene->objects;
	while (obj)
	{
		if (obj->opt.texture_path)
		{
			if (!texture_load(ctx, &obj->opt.texture, &obj->opt.texture_path,
				"texture"))
			{
				free(obj->opt.texture_path);
				obj->opt.texture_path = NULL;
			}
		}
		if (obj->opt.bump_path)
		{
			if (!texture_load(ctx, &obj->opt.bump_texture, &obj->opt.bump_path,
				"bump texture"))
			{
				free(obj->opt.bump_path);
				obj->opt.bump_path = NULL;
			}
		}
		obj = obj->next;
	}
}
