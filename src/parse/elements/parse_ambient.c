/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 02:05:02 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/26 17:31:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/parse.h>
#include <elements/scene.h>

bool	parse_ambient(char *line, const size_t n_params, t_scene *scene)
{
	char	**params;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(line, n_params);
	if (!params)
		return (false);
	if (!parse_scalar(params[0], 0.0f, 1.0f, &scene->amb.ratio))
		return (tok_free(params, n_params), false);
	if (!parse_vector(params[1], 0.0f, 255.0f, &scene->amb.rgb))
		return (tok_free(params, n_params), false);
	tok_free(params, n_params);
	return (true);
}
