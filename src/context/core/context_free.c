/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:44:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/14 04:47:31 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context.h>

void	context_free(t_context *ctx)
{
	if (!ctx)
		return ;
	if (ctx->disp)
		display_free(ctx->disp);
	if (ctx->scene)
	{
		if (ctx->scene->bonus && ctx->scene->bonus->multithreaded)
			pool_free(&ctx->pool);
		scene_free(ctx->scene);
	}
}
