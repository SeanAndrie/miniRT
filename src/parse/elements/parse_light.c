/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:02:57 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/25 00:11:25 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/parse.h>
#include <core/scene.h>
#include <errno.h>
#include <libft.h>

bool	parse_light(char *line, const size_t n_params, t_scene *scene)
{
    t_light *light;
	char	*endptr;
	char	**params;

	if (!line || !scene || n_params == 0)
		return (false);
    light = malloc(sizeof(t_light));
	params = parse_data(line, n_params);
	if (!light || !params)
    {
        if (light)
            free(light);
		return (false);
    }
	if (!parse_vector(params[0], &light->point))
		return (tok_free(params, n_params), false);
	light->ratio = ft_strtof(params[1], &endptr);
	if (*endptr != '\0' || errno == ERANGE)
		return (tok_free(params, n_params), false);
	if (!parse_vector(params[2], &light->rgb))
		return (tok_free(params, n_params), false);
	tok_free(params, n_params);
	return (light_append(&scene->lights, light));
}
