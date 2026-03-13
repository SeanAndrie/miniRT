/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:17:36 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/11 22:20:31 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/scene.h>
#include <core/object.h>

void    camera_free(t_camera *camera)
{
    if (!camera)
        return ;
    if (camera->view)
    {
        tensr_free(camera->view);
        camera->view = NULL;
    }
    if (camera->orient)
    {
        tensr_free(camera->orient);
        camera->orient = NULL;
    }
}
