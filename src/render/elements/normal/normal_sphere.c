/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:53:20 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 12:28:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/render.h>

t_vec3  normal_sphere(t_vec3 point, t_sphere *sp)
{
    return (vec3_normalize(vec3_sub(point, sp->center)));
}
