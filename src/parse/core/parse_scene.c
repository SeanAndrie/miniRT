/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:32:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/05 17:04:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <fcntl.h>
#include <setup/parse.h>

static void	dispatch_error(const char *id)
{
	log_error(STDERR_FILENO, ERR_BASE, "parsing failure: ");
	if (*id == 'A')
		ft_dprintf(STDERR_FILENO, "(1 per scene) ambient light");
	else if (*id == 'C')
		ft_dprintf(STDERR_FILENO, "(1 per scene) camera");
	else if (*id == 'L')
		ft_dprintf(STDERR_FILENO, "light");
	else if (ft_strcmp(id, "sp") == 0)
		ft_dprintf(STDERR_FILENO, "sphere");
	else if (ft_strcmp(id, "pl") == 0)
		ft_dprintf(STDERR_FILENO, "plane");
	else if (ft_strcmp(id, "cy") == 0)
		ft_dprintf(STDERR_FILENO, "cylinder");
	else if (ft_strcmp(id, "co") == 0)
		ft_dprintf(STDERR_FILENO, "cone");
}

static bool	parse_dispatch(char *line, const char *id, t_scene *scene)
{
	if (!line || !id || !scene)
		return (false);
	if (*id != ' ' && !is_valid_id(id))
	{
		ft_dprintf(STDERR_FILENO, "invalid identifier '%s'", id);
		return (false);
	}
	if (*id == 'A' && !parse_ambient(++line, 2, scene))
		return (dispatch_error(id), false);
	else if (*id == 'C' && !parse_camera(++line, 3, scene))
		return (dispatch_error(id), false);
	else if (*id == 'L' && !parse_light(++line, 3, scene))
		return (dispatch_error(id), false);
	else if (ft_strcmp(id, "sp") == 0 && !parse_sphere(++line, 3, scene))
		return (dispatch_error(id), false);
	else if (ft_strcmp(id, "pl") == 0 && !parse_plane(++line, 3, scene))
		return (dispatch_error(id), false);
	else if (ft_strcmp(id, "cy") == 0 && !parse_cylinder(++line, 5, scene))
		return (dispatch_error(id), false);
	else if (ft_strcmp(id, "co") == 0 && !parse_cone(++line, 5, scene))
		return (dispatch_error(id), false);
	return (true);
}

static bool	parse_line(char *line, t_scene *scene)
{
	char	*id;
	char	*end;
	bool	result;

	if (!line || !scene)
		return (false);
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0' || *line == '/' || *line == '#')
		return (true);
	end = line;
	while (*end && ft_isalpha(*end))
		end++;
	id = ft_substr(line, 0, (end - line));
	if (!id)
		return (false);
	result = parse_dispatch(line, id, scene);
	free(id);
	return (result);
}

bool	parse_scene(int fd, t_scene *scene)
{
	char	*line;
	int		line_no;

	if (fd < 0 || !scene)
		return (false);
	line_no = 0;
	while (true)
	{
		line_no++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!parse_line(line, scene))
		{
			free(line);
			close(fd);
			ft_dprintf(STDERR_FILENO, " | line no. %d\n", line_no);
			return (false);
		}
		free(line);
	}
	close(fd);
	return (true);
}
