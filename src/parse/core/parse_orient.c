/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_orient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:34:03 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 23:12:39 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr_rt.h>
#include <math.h>
#include <setup/parse.h>

bool	parse_orient(const char *nptr, t_vec3 *vec)
{
	t_vec3	temp;

	if (!nptr || !vec)
		return (false);
	if (!parse_vector(nptr, -1.0f, 1.0f, &temp))
		return (false);
	if (vec3_dot(temp, temp) < 1e-6f) // zero vector check
		return (false);
	*vec = vec3_normalize(temp);
	return (true);
}
