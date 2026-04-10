/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:09:21 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 23:13:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <elements/scene.h>
#include <float.h>
#include <math.h>
#include <setup/parse.h>

static inline void	quick_free(char **params, t_object *obj)
{
	if (obj)
		free(obj);
	if (params)
		tok_free(params, -1);
}

static inline void	calculate_k(t_cone *co)
{
	co->k = tanf(co->theta * (M_PI / 180.0f));
	co->k2 = co->k * co->k;
}

static t_bool create_and_append(t_scene *scene, t_object *obj, t_cone *params)
{
	obj_cone(obj, params);
	return (obj_append(&scene->objects, obj));
}

t_bool parse_cone(char *line, const size_t n_params, t_scene *scene)
{
	t_cone		co;
	t_object	*obj;
	char		**params;

	if (!line || !scene || n_params == 0)
		return (FALSE);
	params = parse_data(++line, n_params);
	obj = obj_alloc(OBJ_CONE);
	if (!params || !obj)
		return (quick_free(params, obj), FALSE);
	if (!parse_vector(params[0], -INFINITY, INFINITY, &co.apex))
		return (quick_free(params, obj), FALSE);
	if (!parse_orient(params[1], &co.axis))
		return (quick_free(params, obj), FALSE);
	if (!parse_scalar(params[2], 0.0f, INFINITY, &co.height))
		return (quick_free(params, obj), FALSE);
	if (!parse_scalar(params[3], 0.0f, 180.0f, &co.theta))
		return (quick_free(params, obj), FALSE);
	calculate_k(&co);
	if (!parse_vector(params[4], 0.0f, 255.0f, &co.rgb))
		return (quick_free(params, obj), FALSE);
	tok_free(params, n_params);
	parse_optional(ft_strchr(line, '|'), &obj->opt);
	return (create_and_append(scene, obj, &co));
}
