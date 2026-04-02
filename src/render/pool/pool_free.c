/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:52:33 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 02:53:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

void    pool_free(t_pool *pool)
{
    if (!pool)
        return ;
    if (pool->workers)
        free(pool->workers);
    if (pool->tiles)
        tile_free(pool->tiles, pool->n_tiles);
}
