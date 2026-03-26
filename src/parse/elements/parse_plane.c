/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:51 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/26 20:48:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <setup/parse.h>
#include <elements/scene.h>
#include <libtensr.h>

static inline void	quick_free(char **params, t_object *obj)
{
	if (obj)
		free(obj);
	if (params)
		tok_free(params, -1);
}

bool	parse_plane(char *line, const size_t n_params, t_scene *scene)
{
	t_plane		pl;
	t_object	*obj;
	char		**params;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(++line, n_params);
	obj = obj_alloc(OBJ_PLANE);
	if (!params || !obj)
		return (quick_free(params, obj), false);
	if (!parse_vector(params[0], -INFINITY, INFINITY, &pl.point))
		return (quick_free(params, obj), false);
	if (!parse_vector(params[1], -INFINITY, INFINITY, &pl.normal))
		return (quick_free(params, obj), false);
    vec3_normalize_ip(&pl.normal);
	if (!parse_vector(params[2], 0.0f, 255.0f, &pl.rgb))
		return (quick_free(params, obj), false);
	tok_free(params, n_params);
	obj_plane(obj, &pl);
	return (obj_append(&scene->objects, obj));
}
