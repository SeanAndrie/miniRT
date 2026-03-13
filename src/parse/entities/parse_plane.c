/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 03:30:51 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 03:40:24 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libtensr.h>
#include <core/scene.h>
#include <core/parse.h>
#include <core/object.h>

static inline void quick_free(char **params, t_plane *pl)
{
    tok_free(params, -1);
    if (!pl)
        return ;
    if (pl->point)
        tensr_free(pl->point);
    if (pl->normal)
        tensr_free(pl->normal);
    if (pl->rgb)
        tensr_free(pl->rgb);
}

bool	parse_plane(char *line, const size_t n_params, t_scene *scene)
{
    t_plane		pl;
    t_object	*obj;
    char		**params;

    if (!line || !scene || n_params == 0)
        return (false);
    params = parse_data(++line, n_params);
    if (!params)
        return (false);
    obj = obj_alloc(OBJ_PLANE);
    if (!obj)
        return (tok_free(params, n_params), false);
    pl.point = parse_vector(params[0]);
    pl.normal = parse_vector(params[1]);
    pl.rgb = parse_vector(params[2]);
    if (!pl.point || !pl.normal || !pl.rgb)
        return (quick_free(params, &pl), false);
    tok_free(params, n_params);
    obj_plane(obj, &pl);
    return (obj_append(&scene->head, obj));
}
