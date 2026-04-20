/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:07:52 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/05 18:07:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <setup/parse.h>

t_bool	parse_light(char *line, const size_t n_params, t_scene *scene)
{
	t_light	*light;
	char	**params;

	if (!line || !scene || n_params == 0)
		return (FALSE);
	light = malloc(sizeof(t_light));
	if (!light)
		return (FALSE);
	params = parse_data(line, n_params);
	if (!params)
		return (free(light), FALSE);
	light->next = NULL;
	if (!parse_vector(params[0], INT_MIN, INT_MAX, &light->point))
		return (tok_free(params, n_params), free(light), FALSE);
	if (!parse_scalar(params[1], 0.0, 1.0, &light->ratio))
		return (tok_free(params, n_params), free(light), FALSE);
	if (!parse_vector(params[2], 0.0, 255.0, &light->rgb))
		return (tok_free(params, n_params), free(light), FALSE);
	tok_free(params, n_params);
	return (light_append(&scene->lights, light));
}
