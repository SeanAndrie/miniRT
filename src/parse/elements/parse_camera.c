/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:26 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/19 12:51:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/parse.h>
#include <elements/scene.h>
#include <errno.h>
#include <libft.h>
#include <libtensr_rt.h>
#include <math.h>

static void	basis_vectors(t_basis *basis)
{
	t_vec3	world_up;

	world_up = (t_vec3){0, 1, 0};
	if (fabsf(vec3_dot(basis->forward, world_up)) > 0.9999f)
		world_up = (t_vec3){0, 0, 1};
	if (fabsf(vec3_dot(basis->forward, world_up)) > 0.9999f)
		world_up = (t_vec3){1, 0, 0};
	basis->right = vec3_normalize(vec3_cross(world_up, basis->forward));
	basis->up = vec3_normalize(vec3_cross(basis->forward, basis->right));
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
	if (!parse_vector(params[0], &scene->cam.point))
		return (tok_free(params, n_params), false);
	if (!parse_vector(params[1], &scene->cam.basis.forward))
		return (tok_free(params, n_params), false);
	scene->cam.fov = ft_strtof(params[2], &endptr) * M_PI / 180.0;
	if (*endptr != '\0' || errno == ERANGE)
		return (tok_free(params, n_params), false);
	basis_vectors(&scene->cam.basis);
	tok_free(params, n_params);
	return (true);
}
