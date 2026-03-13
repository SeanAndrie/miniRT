/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:49:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 03:38:06 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libtensr.h>
#include <core/object.h>
#include <core/parse.h>
#include <core/scene.h>

static inline void	quick_free(char **params, t_cylinder *cy)
{
	tok_free(params, -1);
	if (!cy)
		return ;
	if (cy->point)
		tensr_free(cy->point);
	if (cy->axis)
		tensr_free(cy->axis);
	if (cy->rgb)
		tensr_free(cy->rgb);
}

bool	parse_cylinder(char *line, const size_t n_params, t_scene *scene)
{
	t_cylinder	cy;
	t_object	*obj;
	char		*endptr;
	char		**params;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(++line, n_params);
	if (!params)
		return (false);
	obj = obj_alloc(OBJ_CYLINDER);
	if (!obj)
		return (tok_free(params, n_params), false);
	cy.point = parse_vector(params[0]);
	cy.axis = parse_vector(params[1]);
	cy.radius = ft_strtod(params[2], &endptr) / 2.0;
	cy.height = ft_strtod(params[3], &endptr);
	cy.rgb = parse_vector(params[4]);
	if (!cy.point || !cy.axis || !cy.rgb || *endptr != '\0' || errno == ERANGE)
		return (quick_free(params, &cy), false);
	tok_free(params, n_params);
	obj_cylinder(obj, &cy);
	return (obj_append(&scene->head, obj));
}
