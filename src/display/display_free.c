/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:49:20 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/18 17:00:46 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libtensr.h>
#include <core/display.h>

void    display_free(t_display *dis)
{
    if (!dis || !dis->conn)
        return ;
    if (dis->framebuf)
    {
        tensr_free(dis->framebuf);
        dis->framebuf = NULL;
    }
    if (dis->image.image)
    {
        mlx_destroy_image(dis->conn, dis->image.image);
        dis->image.image = NULL;
    }
    if (dis->window)
    {
        mlx_destroy_window(dis->conn, dis->window);
        dis->window = NULL;
    }
    mlx_destroy_display(dis->conn);
    free(dis->conn);
    dis->conn = NULL;
}
