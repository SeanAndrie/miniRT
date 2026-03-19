/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:02:57 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/19 12:54:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errno.h>
#include <core/scene.h>
#include <core/parse.h>

bool    parse_light(char *line, const size_t n_params, t_scene *scene)
{
    char    *endptr;
    char    **params;
    
    if (!line || !scene || n_params == 0)
        return (false);
    params = parse_data(line, n_params);
    if (!params)
        return (false);
    if (!parse_vector(params[0], &scene->light.point))
        return (tok_free(params, n_params), false);
    scene->light.ratio = ft_strtof(params[1], &endptr);
    if (*endptr != '\0' || errno == ERANGE)
        return (tok_free(params, n_params), false);
    if (!parse_vector(params[2], &scene->light.rgb))
        return (tok_free(params, n_params), false);
    tok_free(params, n_params);
    return (true);
}
