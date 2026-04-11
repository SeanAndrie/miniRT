/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 02:05:02 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/03 23:37:33 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <setup/parse.h>

t_bool	parse_ambient(char *line, const size_t n_params, t_scene *scene)
{
	char	**params;

	if (!line || !scene || scene->amb.allocd || n_params == 0)
		return (FALSE);
	params = parse_data(line, n_params);
	if (!params)
		return (FALSE);
	if (!parse_scalar(params[0], 0.0f, 1.0f, &scene->amb.ratio))
		return (tok_free(params, n_params), FALSE);
	if (!parse_vector(params[1], 0.0f, 255.0f, &scene->amb.rgb))
		return (tok_free(params, n_params), FALSE);
	tok_free(params, n_params);
	scene->amb.allocd = TRUE;
	return (TRUE);
}
