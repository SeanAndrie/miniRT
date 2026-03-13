/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:26 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 23:30:04 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libtensr.h>
#include <core/parse.h>
#include <core/scene.h>

static inline void quick_free(char **params, t_camera *cam)
{
    tok_free(params, -1);
    camera_free(cam);
}

bool	parse_camera(char *line, const size_t n_params, t_scene *scene)
{
	char	*endptr;
	char	**params;

	if (!line || !scene || n_params == 0)
		return (false);
	params = parse_data(line, n_params);
	if (!params)
		return (false);
	scene->cam.view = parse_vector(params[0]);
	if (!scene->cam.view)
        return (tok_free(params, -1), false);
	scene->cam.orient = parse_vector(params[1]);
	if (!scene->cam.orient)
        return (quick_free(params, &scene->cam), false);
	scene->cam.fov = ft_strtod(params[2], &endptr);
	if (*endptr != '\0' || errno == ERANGE)
        return (quick_free(params, &scene->cam), false);
	tok_free(params, n_params);
	return (true);
}
