/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:09:21 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 20:49:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
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

static inline void	calculate_k(t_cone *co)
{
	co->k = tanf(co->theta * (M_PI / 180.0f));
	co->k2 = co->k * co->k;
}

static bool	create_and_append(t_scene *scene, t_object *obj, t_cone *params)
{
	obj_cone(obj, params);
	return (obj_append(&scene->objects, obj));
}

bool	parse_cone(char *line, const size_t n_params, t_scene *scene)
{
	t_cone		co;
	t_object	*obj;
	char		**params;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(++line, n_params);
	obj = obj_alloc(OBJ_CONE);
	if (!params || !obj)
		return (quick_free(params, obj), false);
	if (!parse_vector(params[0], -INFINITY, INFINITY, &co.apex))
		return (quick_free(params, obj), false);
	if (!parse_vector(params[1], -INFINITY, INFINITY, &co.axis))
		return (quick_free(params, obj), false);
	if (!parse_scalar(params[2], 0.0f, INFINITY, &co.height))
		return (quick_free(params, obj), false);
	if (!parse_scalar(params[3], 0.0f, 180.0f, &co.theta))
		return (quick_free(params, obj), false);
	calculate_k(&co);
    vec3_normalize_ip(&co.axis);
	if (!parse_vector(params[4], 0.0f, 255.0f, &co.rgb))
		return (quick_free(params, obj), false);
	tok_free(params, n_params);
	return (create_and_append(scene, obj, &co));
}
