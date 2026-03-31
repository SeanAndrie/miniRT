/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:12:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 04:13:55 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/render.h>

void    tile_free(t_tile *tile)
{
    if (!tile)
        return ;
    if (tile->buffer)
    {
        tensr_free(tile->buffer);
        tile->buffer = NULL;
    }
    if (tile->rdir)
    {
        tensr_free(tile->rdir);
        tile->rdir = NULL;
    }
}
