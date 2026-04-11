/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:55:15 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:15:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>

t_bool	camera_coords(t_camera *cam, const int width, const int height,
		const float aspect)
{
	float	con;

	if (!cam)
		return (FALSE);
	con = tanf(cam->fov / 2);
	cam->coords.u_range = tensr_linspace(-(aspect * con), (aspect * con), width,
			DT_F32);
	if (!cam->coords.u_range)
		return (FALSE);
	tensr_expand_dims(cam->coords.u_range, 0);
	tensr_expand_dims(cam->coords.u_range, 2);
	cam->coords.v_range = tensr_linspace(con, -con, height, DT_F32);
	if (!cam->coords.v_range)
		return (tensr_free(cam->coords.u_range), FALSE);
	tensr_expand_dims(cam->coords.v_range, 1);
	tensr_expand_dims(cam->coords.v_range, 2);
	return (TRUE);
}
