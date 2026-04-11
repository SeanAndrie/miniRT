/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:03:37 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/11 02:19:13 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/display.h>
#include <setup/texture.h>

t_vec3	bump_normal(t_hit *hit)
{
	t_vec3		grad;
	t_texture	*bump_tex;

	bump_tex = hit->obj->opt.bump_texture;
	if (!bump_tex)
		return (hit->normal);
	grad = bump_gradient(bump_tex, hit->u, hit->v);
	hit->normal = vec3_add(hit->normal, vec3_add(vec3_scale(hit->tangent,
					grad.x), vec3_scale(hit->bitangent, grad.y)));
	return (vec3_normalize(hit->normal));
}
