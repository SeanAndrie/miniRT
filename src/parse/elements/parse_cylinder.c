/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:49:59 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/03 23:12:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <setup/parse.h>
#include <elements/scene.h>
#include <elements/object.h>

static inline void	quick_free(char **params, t_object *obj)
{
	if (obj)
		free(obj);
	if (params)
		tok_free(params, -1);
}

static bool	create_and_append(t_scene *scene, t_object *obj, t_cylinder *params)
{
	obj_cylinder(obj, params);
	return (obj_append(&scene->objects, obj));
}

bool	parse_cylinder(char *line, const size_t n_params, t_scene *scene)
{
	t_cylinder	cy;
	t_object	*obj;
	char		**params;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(++line, n_params);
	obj = obj_alloc(OBJ_CYLINDER);
	if (!params || !obj)
		return (quick_free(params, obj), false);
	if (!parse_vector(params[0], -INFINITY, INFINITY, &cy.point))
		return (quick_free(params, obj), false);
	if (!parse_orient(params[1], &cy.axis))
		return (quick_free(params, obj), false);
	if (!parse_scalar(params[2], 0.0f, INFINITY, &cy.radius))
		return (quick_free(params, obj), false);
	cy.radius /= 2.0;
	if (!parse_scalar(params[3], 0.0f, INFINITY, &cy.height))
		return (quick_free(params, obj), false);
	if (!parse_vector(params[4], 0.0f, 255.0f, &cy.rgb))
		return (quick_free(params, obj), false);
	tok_free(params, n_params);
    parse_optional(ft_strchr(line, '|'), &obj->opt);
	return (create_and_append(scene, obj, &cy));
}
