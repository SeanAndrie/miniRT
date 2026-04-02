/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:44:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 03:44:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context.h>

void	context_free(t_context *ctx)
{
    pool_free(&ctx->pool);
	if (ctx->disp)
		display_free(ctx->disp);
	if (ctx->scene)
		scene_free(ctx->scene);
}
