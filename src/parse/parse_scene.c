/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:32:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 03:39:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <core/scene.h>
#include <core/parse.h>

static bool parse_dispatch(char *line, const char *id, t_scene *scene)
{
    if (!line || !id || !scene)
        return (false);
    if (*id == 'A' && !parse_ambient(++line, 2, scene))
        return (false);
    if (*id == 'C' && !parse_camera(++line, 3, scene))
        return (false);
    if (*id == 'L' && !parse_light(++line, 3, scene))
        return (false);
    if (ft_strcmp(id, "sp") == 0 && !parse_sphere(++line, 3, scene))
        return (false);
    if (ft_strcmp(id, "pl") == 0 && !parse_plane(++line, 3, scene))
        return (false);
    if (ft_strcmp(id, "cy") == 0 && !parse_cylinder(++line, 5, scene))
        return (false);
    return (true);
}

static bool parse_line(char *line, t_scene *scene)
{
    char    *id;
    char    *end;
    bool    success;

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
