/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:49:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 03:38:06 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libtensr.h>
#include <core/scene.h>
#include <core/parse.h>
#include <core/object.h>

static inline void quick_free(char **params, t_sphere *sp)
{
    tok_free(params, -1);
    if (!sp)
        return ;
    if (sp->center)
        tensr_free(sp->center);
    if (sp->rgb)
        tensr_free(sp->rgb);
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
    if (!params)
        return (false);
    obj = obj_alloc(OBJ_SPHERE);
    if (!obj)
        return (tok_free(params, n_params), false);
    sp.center = parse_vector(params[0]);
    sp.radius = ft_strtod(params[1], &endptr) / 2.0;
    sp.rgb = parse_vector(params[2]);
    if (!sp.center || !sp.rgb || *endptr != '\0' || errno == ERANGE)
        return (quick_free(params, &sp), false);
    tok_free(params, n_params);
    obj_sphere(obj, &sp);
    return (obj_append(&scene->head, obj));
}
