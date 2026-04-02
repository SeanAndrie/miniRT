/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 03:34:00 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 03:38:11 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

bool    pool_join(t_pool *pool)
{
    size_t  i;

    if (!pool || !pool->workers)
        return (false);
    i = 0;
    while (i < pool->n_workers)
    {
        if (pthread_join(pool->workers[i]->thread, NULL) != 0)
            return (false);
        i++;
    }
    return (true);
}
