/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:32:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/14 02:01:46 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <fcntl.h>
#include <setup/parse.h>

static void	dispatch_error(const char *id)
{
	log_error(ERR_NONE, ERR_BASE, "error: parsing failure: ");
	if (*id == 'A')
		ft_dprintf(STDERR_FILENO, "ambient light");
	else if (*id == 'C')
		ft_dprintf(STDERR_FILENO, "camera");
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

static t_bool	parse_dispatch(char *line, const char *id, t_scene *scene)
{
	if (!line || !id || !scene)
		return (FALSE);
	if (*id != ' ' && !is_valid_id(id))
	{
        ft_dprintf(STDERR_FILENO, "Error\n");
        log_error(ERR_NONE, ERR_BASE, "error: invalid identifier '%s'", id);
		return (FALSE);
	}
	if (*id == 'A' && !parse_ambient(++line, 2, scene))
		return (dispatch_error(id), FALSE);
	else if (*id == 'C' && !parse_camera(++line, 3, scene))
		return (dispatch_error(id), FALSE);
	else if (*id == 'L' && !parse_light(++line, 3, scene))
		return (dispatch_error(id), FALSE);
	else if (ft_strcmp(id, "sp") == 0 && !parse_sphere(++line, 3, scene))
		return (dispatch_error(id), FALSE);
	else if (ft_strcmp(id, "pl") == 0 && !parse_plane(++line, 3, scene))
		return (dispatch_error(id), FALSE);
	else if (ft_strcmp(id, "cy") == 0 && !parse_cylinder(++line, 5, scene))
		return (dispatch_error(id), FALSE);
	else if (ft_strcmp(id, "co") == 0 && !parse_cone(++line, 5, scene))
		return (dispatch_error(id), FALSE);
	return (TRUE);
}

static t_bool	parse_line(char *line, t_scene *scene)
{
	char	*id;
	char	*end;
	t_bool	result;

	if (!line || !scene)
		return (FALSE);
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0' || *line == '/' || *line == '#')
		return (TRUE);
	end = line;
	while (*end && ft_isalpha(*end))
		end++;
	id = ft_substr(line, 0, (end - line));
	if (!id)
		return (FALSE);
	result = parse_dispatch(line, id, scene);
	free(id);
	return (result);
}

static t_bool	required_elements_allocd(t_scene *scene)
{
	t_bool	ret;

	ret = TRUE;
	if (!scene->cam.allocd)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE, "camera is missing (1 per scene)\n");
		ret = FALSE;
	}
	if (!scene->amb.allocd)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE,
			"ambient light is missing (1 per scene)\n");
		ret = FALSE;
	}
	return (ret);
}

t_bool	parse_scene(int fd, t_scene *scene)
{
	char	*line;
	int		line_no;

	if (fd < 0 || !scene)
		return (FALSE);
	line_no = 0;
	while (TRUE)
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
			return (FALSE);
		}
		free(line);
	}
	close(fd);
	if (!required_elements_allocd(scene))
		return (FALSE);
	return (TRUE);
}
