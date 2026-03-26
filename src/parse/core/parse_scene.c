/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:32:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 17:37:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <fcntl.h>
#include <setup/parse.h>

static void	dispatch_error(const char *id)
{
	ft_printf("Error\n");
	log_error(STDERR_FILENO, ERR_BASE, "parsing failure: ");
	if (*id == 'A')
		ft_dprintf(STDERR_FILENO, "ambient light");
	if (*id == 'C')
		ft_dprintf(STDERR_FILENO, "camera");
	if (*id == 'L')
		ft_dprintf(STDERR_FILENO, "light");
	if (ft_strcmp(id, "sp") == 0)
		ft_dprintf(STDERR_FILENO, "sphere");
	if (ft_strcmp(id, "pl") == 0)
		ft_dprintf(STDERR_FILENO, "plane");
	if (ft_strcmp(id, "cy") == 0)
		ft_dprintf(STDERR_FILENO, "cylinder");
	if (ft_strcmp(id, "co") == 0)
		ft_dprintf(STDERR_FILENO, "cone");
	ft_dprintf(STDERR_FILENO, "\n");
}

static bool	parse_dispatch(char *line, const char *id, t_scene *scene)
{
	if (!line || !id || !scene)
		return (dispatch_error(id), false);
	if (*id == 'A' && !parse_ambient(++line, 2, scene))
		return (dispatch_error(id), false);
	if (*id == 'C' && !parse_camera(++line, 3, scene))
		return (dispatch_error(id), false);
	if (*id == 'L' && !parse_light(++line, 3, scene))
		return (dispatch_error(id), false);
	if (ft_strcmp(id, "sp") == 0 && !parse_sphere(++line, 3, scene))
		return (dispatch_error(id), false);
	if (ft_strcmp(id, "pl") == 0 && !parse_plane(++line, 3, scene))
		return (dispatch_error(id), false);
	if (ft_strcmp(id, "cy") == 0 && !parse_cylinder(++line, 5, scene))
		return (dispatch_error(id), false);
	if (ft_strcmp(id, "co") == 0 && !parse_cone(++line, 5, scene))
		return (dispatch_error(id), false);
	return (true);
}

static bool	parse_line(char *line, t_scene *scene)
{
	char	*id;
	char	*end;
	bool	success;

	if (!line || !scene)
		return (false);
	while (*line && ft_isspace(*line))
		line++;
	end = line;
	while (*end && ft_isalpha(*end))
		end++;
	id = ft_substr(line, 0, (end - line));
	if (!id)
		return (false);
	success = parse_dispatch(line, id, scene);
	free(id);
	return (success);
}

bool	parse_scene(int fd, t_scene *scene)
{
	char	*line;

	if (fd < 0 || !scene)
		return (false);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!parse_line(line, scene))
		{
			free(line);
			close(fd);
			return (false);
		}
		free(line);
	}
	close(fd);
	return (true);
}
