/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:26 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/30 23:02:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libtensr_rt.h>
#include <setup/parse.h>
#include <elements/scene.h>

bool	parse_camera(char *line, const size_t n_params, t_scene *scene)
{
	char	**params;
	float	fov;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(line, n_params);
	if (!params)
		return (false);
	if (!parse_vector(params[0], -INFINITY, INFINITY, &scene->cam.point))
		return (tok_free(params, n_params), false);
	if (!parse_vector(params[1], -INFINITY, INFINITY,
			&scene->cam.basis.forward))
		return (tok_free(params, n_params), false);
	if (!parse_scalar(params[2], 0.0f, 180.0f, &fov))
		return (tok_free(params, n_params), false);
	scene->cam.fov = fov * (M_PI / 180.0);
	tok_free(params, n_params);
	return (true);
}
