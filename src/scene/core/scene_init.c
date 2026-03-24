/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:30:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/18 17:23:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/parse.h>
#include <core/scene.h>
#include <fcntl.h>
#include <libft.h>

static bool	has_valid_extension(const char *fname, const char *fext)
{
	char	*dot;

	if (!fext)
	{
		log_error(ERR_WARNING, ERR_BASE, "missing file extension.\n");
		return (false);
	}
	dot = ft_strrchr(fname, '.');
	if (!dot || dot == fname)
	{
		log_error(ERR_WARNING, ERR_BASE, ERR_MISSING_EXT, fext);
		return (false);
	}
	if (ft_strcmp(dot, fext) != 0)
	{
		log_error(ERR_WARNING, ERR_BASE, ERR_INVALID_EXT, dot, fext);
		return (false);
	}
	return (true);
}

static int	read_file(const char *fname)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		log_error(ERR_WARNING, ERR_BASE, "'%s' not found\n", fname);
	return (fd);
}

t_scene	*scene_init(const char *fname, const char *fext)
{
	int		fd;
	t_scene	*scene;
	bool	success;

	if (!fname)
	{
		log_error(ERR_WARNING, ERR_BASE, "missing scene file\n");
		return (NULL);
	}
	if (!has_valid_extension(fname, fext))
		return (NULL);
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
	{
		log_error(ERR_WARNING, ERR_BASE, "scene allocation failed\n");
		return (NULL);
	}
	fd = read_file(fname);
	if (fd < 0)
		return (scene_free(scene), NULL);
	success = parse_scene(fd, scene);
	close(fd);
	if (!success)
		return (scene_free(scene), NULL);
	return (scene);
}
