/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:25:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 12:29:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/render.h>

t_ray	ray_create(t_camera *cam, int x, int y)
{
	t_ray	ray;
	t_vec3	up_s;
	t_vec3	right_s;
	t_basis	*basis;

	basis = &cam->basis;
	ray.orig = cam->point;
	right_s = vec3_scale(basis->right, ((float *)cam->u->data)[x]);
	up_s = vec3_scale(basis->up, ((float *)cam->v->data)[y]);
	ray.dir = vec3_normalize(vec3_add(basis->forward, vec3_add(right_s, up_s)));
	return (ray);
}
