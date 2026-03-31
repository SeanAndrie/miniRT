/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_basis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:35:06 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 17:32:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <libtensr_rt.h>
#include <elements/scene.h>

static bool basis_alloc(t_basis *basis)
{
    int     ndim;
    size_t  *shape;

    if (!basis)
        return (false);
    ndim = 3;
    shape = (size_t[]){1, 1, 3};
    basis->forward_t = tensr_alloc(ndim, shape, DT_F32);
    if (!basis->forward_t)
        return (false);
    basis->right_t = tensr_alloc(ndim, shape, DT_F32);
    if (!basis->right_t)
    {
        tensr_free(basis->forward_t);
        return (false);
    }
    basis->up_t = tensr_alloc(ndim, shape, DT_F32);
    if (!basis->up_t)
    {
        tensr_free(basis->right_t);
        tensr_free(basis->forward_t);
        return (false);
    }
    return (true);
}

bool    camera_basis(t_camera *cam)
{
    t_basis *basis;
    t_vec3  world_up;

    if (!cam)
        return (false);
    basis = &cam->basis;
	world_up = (t_vec3){0, 1, 0};
	if (fabsf(vec3_dot(basis->forward, world_up)) > 0.9999f)
		world_up = (t_vec3){0, 0, 1};
	if (fabsf(vec3_dot(basis->forward, world_up)) > 0.9999f)
		world_up = (t_vec3){1, 0, 0};
	basis->right = vec3_normalize(vec3_cross(basis->forward, world_up));
	basis->up = vec3_normalize(vec3_cross(basis->right, basis->forward));
    if (!basis_alloc(basis))
        return (false);
    tensr_metadata("forward", basis->forward_t);
    tensr_metadata("right", basis->right_t);
    tensr_metadata("up", basis->up_t);
    return (true);
}
