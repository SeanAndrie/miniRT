/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 17:21:24 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 17:40:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <core/context.h>

void reset_app(t_context *ctx)
{
   scene_free(ctx->scene);
    ctx->scene = scene_init(ctx->fname, SCENE_FILE_EXT);
    if (!ctx->scene)
        close_app(ctx);
    render_init(ctx->disp, ctx->scene);
    render(ctx->disp, ctx->scene);
}
