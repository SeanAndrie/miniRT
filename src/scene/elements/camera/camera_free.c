/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:48:34 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 01:10:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>

void	coords_free(t_coord *coords)
{
	if (coords->u_range)
	{
		tensr_free(coords->u_range);
		coords->u_range = NULL;
	}
	if (coords->v_range)
	{
		tensr_free(coords->v_range);
		coords->v_range = NULL;
	}
}

void	basis_free(t_basis *basis)
{
	if (basis->forward_t)
	{
		tensr_free(basis->forward_t);
		basis->forward_t = NULL;
	}
	if (basis->right_t)
	{
		tensr_free(basis->right_t);
		basis->right_t = NULL;
	}
	if (basis->up_t)
	{
		tensr_free(basis->up_t);
		basis->up_t = NULL;
	}
}

void	rdir_free(t_rdir *in)
{
	if (in->up_s)
	{
		tensr_free(in->up_s);
		in->up_s = NULL;
	}
	if (in->right_s)
	{
		tensr_free(in->right_s);
		in->right_s = NULL;
	}
	if (in->sum_s)
	{
		tensr_free(in->sum_s);
		in->sum_s = NULL;
	}
	if (in->dir)
	{
		tensr_free(in->dir);
		in->dir = NULL;
	}
	if (in->out)
	{
		tensr_free(in->out);
		in->out = NULL;
	}
}

void	camera_free(t_camera *cam)
{
	coords_free(&cam->coords);
	basis_free(&cam->basis);
	rdir_free(&cam->rdir);
}
