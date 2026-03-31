/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:55:15 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 18:01:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <float.h>

bool	camera_coords(t_camera *cam, const int width, const int height,
		const float aspect)
{
	float con;

	if (!cam)
		return (false);
	con = tanf(cam->fov / 2);
	cam->coords.u_range = tensr_linspace(-(aspect * con), (aspect * con),
			width, DT_F32);
	if (!cam->coords.u_range)
		return (false);
	tensr_expand_dims(cam->coords.u_range, 0);
	tensr_expand_dims(cam->coords.u_range, 2);
    // tensr_metadata("u_range", cam->coords.u_range);
	cam->coords.v_range = tensr_linspace(con, -con, height, DT_F32);
	if (!cam->coords.v_range)
		return (tensr_free(cam->coords.u_range), false);
	tensr_expand_dims(cam->coords.v_range, 1);
	tensr_expand_dims(cam->coords.v_range, 2);
    // tensr_metadata("v_range", cam->coords.v_range);
	return (true);
}
