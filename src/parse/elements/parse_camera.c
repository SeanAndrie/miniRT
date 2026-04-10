/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:26 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/03 23:38:33 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <libvec3.h>
#include <math.h>
#include <setup/parse.h>

t_bool parse_camera(char *line, const size_t n_params, t_scene *scene)
{
	char	**params;
	float	fov;

	if (!line || !scene || scene->cam.allocd || n_params == 0)
		return (FALSE);
	params = parse_data(line, n_params);
	if (!params)
		return (FALSE);
	if (!parse_vector(params[0], -INFINITY, INFINITY, &scene->cam.point))
		return (tok_free(params, n_params), FALSE);
	if (!parse_orient(params[1], &scene->cam.basis.forward))
		return (tok_free(params, n_params), FALSE);
	if (!parse_scalar(params[2], 0.0f, 180.0f, &fov))
		return (tok_free(params, n_params), FALSE);
	scene->cam.fov = fov * (M_PI / 180.0);
	tok_free(params, n_params);
    scene->cam.allocd = TRUE;
	return (scene->cam.allocd);
}
