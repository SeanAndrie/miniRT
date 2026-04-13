/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:49:59 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/14 02:05:34 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <elements/scene.h>
#include <setup/parse.h>

static inline void	quick_free(char **params, t_object *obj)
{
	if (obj)
		free(obj);
	if (params)
		tok_free(params, -1);
}

t_bool	parse_sphere(char *line, const size_t n_params, t_scene *scene)
{
	t_sphere	sp;
	t_object	*obj;
	char		**params;

	if (!line || !scene || n_params == 0)
		return (FALSE);
	params = parse_data(++line, n_params);
	obj = obj_alloc(OBJ_SPHERE);
	if (!params || !obj)
		return (quick_free(params, obj), FALSE);
	if (!parse_vector(params[0], -INFINITY, INFINITY, &sp.center))
		return (quick_free(params, obj), FALSE);
	if (!parse_scalar(params[1], 1.0f, INFINITY, &sp.radius))
		return (quick_free(params, obj), FALSE);
	sp.radius /= 2.0;
	if (!parse_vector(params[2], 0.0f, 255.0f, &sp.rgb))
		return (quick_free(params, obj), FALSE);
	tok_free(params, n_params);
	parse_optional(ft_strchr(line, '|'), &obj->opt);
	obj_sphere(obj, &sp);
	return (obj_append(&scene->objects, obj));
}
