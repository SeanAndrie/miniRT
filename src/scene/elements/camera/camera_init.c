/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:02:47 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 18:29:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>

t_bool camera_init(t_camera *cam, const int width, const int height,
		const float aspect)
{
	if (!cam)
		return (FALSE);
	if (!camera_basis(cam))
		return (FALSE);
	if (!camera_coords(cam, width, height, aspect))
		return (FALSE);
	if (!rdir_init(&cam->rdir, width, height))
		return (FALSE);
	return (TRUE);
}
