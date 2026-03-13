/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:02:57 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 01:15:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <core/scene.h>
#include <core/parse.h>

static inline void quick_free(char **params, t_light *light)
{
    tok_free(params, -1);
    light_free(light);
}

bool    parse_light(char *line, const size_t n_params, t_scene *scene)
{
    char    *endptr;
    char    **params;
    
    if (!line || !scene || n_params == 0)
        return (false);
    params = parse_data(line, n_params);
    if (!params)
        return (false);
    scene->light.point = parse_vector(params[0]);
    if (!scene->light.point)
        return (tok_free(params, -1), false);
    scene->light.ratio = ft_strtod(params[1], &endptr);
    if (!scene->light.ratio)
        return (quick_free(params, &scene->light), false);
    scene->light.rgb = parse_vector(params[2]);
    if (!scene->light.rgb)
        return (quick_free(params, &scene->light), false);
    tok_free(params, n_params);
    return (true);
}

