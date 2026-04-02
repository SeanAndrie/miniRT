/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:02:57 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/02 02:56:49 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/parse.h>
#include <elements/scene.h>

bool	parse_light(char *line, const size_t n_params, t_scene *scene)
{
    t_light	*light;
	char		**params;

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
    light->next = NULL;
	if (!parse_vector(params[0], -INFINITY, INFINITY, &light->point))
		return (tok_free(params, n_params), free(light), false);
	if (!parse_scalar(params[1], 0.0f, 1.0f, &light->ratio))
		return (tok_free(params, n_params), free(light), false);
	if (!parse_vector(params[2], 0.0f, 255.0f, &light->rgb))
		return (tok_free(params, n_params), free(light), false);
	tok_free(params, n_params);
	return (light_append(&scene->lights, light));
}
