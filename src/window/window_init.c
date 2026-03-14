/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:22:41 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/14 01:39:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <utils/window.h>

bool    window_init(t_mlx *mlx, const int width, const int height, char *title)
{
    if (!mlx || !mlx->conn)
        return (false);
    mlx->win = mlx_new_window(mlx->conn, width, height, title);
    if (!mlx->win)
        return (false);
    return (true);
}
