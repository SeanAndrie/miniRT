/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:51 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/03 23:51:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <elements/scene.h>
#include <libtensr.h>
#include <setup/parse.h>

static inline void	quick_free(char **params, t_object *obj)
{
	if (obj)
		free(obj);
	if (params)
		tok_free(params, -1);
}

t_bool	parse_plane(char *line, const size_t n_params, t_scene *scene)
{
	t_plane		pl;
	t_object	*obj;
	char		**params;

	if (!line || !scene || n_params == 0)
		return (FALSE);
	params = parse_data(++line, n_params);
	if (!params)
		return (FALSE);
	obj = obj_alloc(OBJ_PLANE);
	if (!obj)
		return (quick_free(params, obj), FALSE);
	if (!parse_vector(params[0], INT_MIN, INT_MAX, &pl.point))
		return (quick_free(params, obj), FALSE);
	if (!parse_orient(params[1], &pl.normal))
		return (quick_free(params, obj), FALSE);
	if (!parse_vector(params[2], 0.0, 255.0, &pl.rgb))
		return (quick_free(params, obj), FALSE);
	tok_free(params, n_params);
	obj_plane(obj, &pl);
	parse_optional(ft_strchr(line, '|'), &obj->opt);
	return (obj_append(&scene->objects, obj));
}
