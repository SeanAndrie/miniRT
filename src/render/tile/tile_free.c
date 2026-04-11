/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:12:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 02:38:39 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>
#include <libtensr.h>

void	tile_free(t_tile *tile, size_t n)
{
	size_t	i;

	if (!tile || n == 0)
		return ;
	i = 0;
	while (i < n)
	{
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
		i++;
	}
}
