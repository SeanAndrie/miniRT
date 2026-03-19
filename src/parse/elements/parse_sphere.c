/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:49:59 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/19 11:35:06 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libtensr.h>
#include <core/scene.h>
#include <core/parse.h>
#include <core/object.h>

static inline void quick_free(char **params, t_object *obj)
{
    if (obj)
        free(obj);
    if (params)
        tok_free(params, -1);
}

bool    parse_sphere(char *line, const size_t n_params, t_scene *scene)
{
    t_sphere    sp;
    t_object    *obj;
    char        *endptr;
    char        **params;

    if (!line || !scene || n_params == 0)
        return (false);
    params = parse_data(++line, n_params);
    obj = obj_alloc(OBJ_SPHERE);
    if (!params || !obj)
        return (quick_free(params, obj), false);
    if (!parse_vector(params[0], &sp.center))
        return (quick_free(params, obj), false);
    sp.radius = ft_strtof(params[1], &endptr) / 2.0;
    if (*endptr != '\0' || errno == ERANGE)
        return (quick_free(params, obj), false);
    if (!parse_vector(params[2], &sp.rgb))
        return (quick_free(params, obj), false);
    tok_free(params, n_params);
    obj_sphere(obj, &sp);
    return (obj_append(&scene->head, obj));
}
