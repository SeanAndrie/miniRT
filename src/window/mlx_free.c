/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:04:56 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/14 01:13:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <utils/window.h>

void    mlx_free(t_mlx *mlx)
{
    if (!mlx)
        return ;
    if (mlx->img_v)
        tensr_free(mlx->img_v);
    if (mlx->img.img)
        free(mlx->img.img);
    if (mlx->conn)
        free(mlx->conn);
}
