/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 02:05:02 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/19 12:41:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/parse.h>
#include <core/scene.h>
#include <errno.h>
#include <libtensr.h>

bool	parse_ambient(char *line, const size_t n_params, t_scene *scene)
{
	char	*endptr;
	char	**params;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(line, n_params);
	if (!params)
		return (false);
	scene->amb.ratio = ft_strtof(params[0], &endptr);
	if (*endptr != '\0' || errno == ERANGE)
		return (tok_free(params, n_params), false);
	if (!parse_vector(params[1], &scene->amb.rgb))
		return (false);
	tok_free(params, n_params);
	return (true);
}
