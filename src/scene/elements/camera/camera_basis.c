/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_basis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:35:06 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:14:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <libvec3.h>

static t_bool	basis_alloc(t_basis *basis)
{
	int		ndim;
	size_t	*shape;

	if (!basis)
		return (FALSE);
	ndim = 3;
	shape = (size_t[]){1, 1, 3};
	basis->forward_t = tensr_alloc(ndim, shape, DT_F32);
	if (!basis->forward_t)
		return (FALSE);
	basis->right_t = tensr_alloc(ndim, shape, DT_F32);
	if (!basis->right_t)
	{
		tensr_free(basis->forward_t);
		return (FALSE);
	}
	basis->up_t = tensr_alloc(ndim, shape, DT_F32);
	if (!basis->up_t)
	{
		tensr_free(basis->right_t);
		tensr_free(basis->forward_t);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	camera_basis(t_camera *cam)
{
	t_basis	*basis;
	t_vec3	world_up;

	if (!cam)
		return (FALSE);
	basis = &cam->basis;
	world_up = (t_vec3){0, 1, 0};
	if (fabsf(vec3_dot(basis->forward, world_up)) > 0.9999f)
		world_up = (t_vec3){0, 0, 1};
	if (fabsf(vec3_dot(basis->forward, world_up)) > 0.9999f)
		world_up = (t_vec3){1, 0, 0};
	basis->right = vec3_normalize(vec3_cross(world_up, basis->forward));
	basis->up = vec3_normalize(vec3_cross(basis->forward, basis->right));
	if (!basis_alloc(basis))
		return (FALSE);
	return (TRUE);
}
