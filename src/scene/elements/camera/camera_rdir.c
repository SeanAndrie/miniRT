/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:38:02 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 23:39:16 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>

bool	rdir_init(t_rdir *in, const int width, const int height)
{
	int		ndim;
	size_t	*shape;

	if (!in)
		return (false);
	ndim = 3;
	shape = (size_t[]){height, width, 3};
	in->right_s = tensr_full(0.0, ndim, shape, DT_F32);
	in->up_s = tensr_full(0.0, ndim, shape, DT_F32);
	in->sum_s = tensr_full(0.0, ndim, shape, DT_F32);
	in->dir = tensr_full(0.0, ndim, shape, DT_F32);
	in->out = tensr_full(0.0, ndim, shape, DT_F32);
	if (!in->out || !in->dir || !in->sum_s || !in->up_s || !in->right_s)
	{
		rdir_free(in);
		return (false);
	}
	return (true);
}

bool	camera_rdir(t_camera *cam)
{
	t_rdir	*rdir;
	t_basis	*basis;
	t_coord	*coords;

	if (!cam)
		return (false);
	rdir = &cam->rdir;
	basis = &cam->basis;
	coords = &cam->coords;
	if (!tensr_mul(basis->right_t, coords->u_range, rdir->right_s))
		return (false);
	if (!tensr_mul(basis->up_t, coords->v_range, rdir->up_s))
		return (rdir_free(rdir), false);
	if (!tensr_add(rdir->right_s, rdir->up_s, rdir->sum_s))
		return (rdir_free(rdir), false);
	if (!tensr_add(basis->forward_t, rdir->sum_s, rdir->dir))
		return (rdir_free(rdir), false);
	tensr_normalize(rdir->dir, rdir->out);
	return (rdir->out != NULL);
}
