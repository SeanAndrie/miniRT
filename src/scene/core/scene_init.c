/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:30:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 03:02:25 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <sys/stat.h>
#include <setup/parse.h>
#include <elements/scene.h>

static bool	has_valid_extension(const char *fname, const char *fext)
{
	char	*dot;

	if (!fext)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE, "missing file extension.\n");
		return (false);
	}
	dot = ft_strrchr(fname, '.');
	if (!dot || dot == fname)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE, ERR_MISSING_EXT, fname, fext);
		return (false);
	}
	if (ft_strcmp(dot, fext) != 0)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE, ERR_INVALID_EXT, fname, dot, fext);
		return (false);
	}
	return (true);
}

static int	read_file(const char *fname, const char *fext)
{
	int			fd;
	struct stat	path_stat;

	if (stat(fname, &path_stat) != 0)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE, "%s: no such file found\n", fname);
		return (-1);
	}
	if (access(fname, X_OK) != 0)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE, "%s: permission denied\n", fname);
		return (-1);
	}
	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		log_error(ERR_WARNING, ERR_BASE, "%s: no such file found\n", fname);
	}
	if (!has_valid_extension(fname, fext))
		return (false);
	return (fd);
}

t_scene	*scene_init(const char *fname, const char *fext)
{
	int		fd;
	t_scene	*scene;
	bool	success;

	if (!fname || !fext)
		return (NULL);
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
	{
		log_error(ERR_WARNING, ERR_BASE, "scene allocation failed\n");
		return (NULL);
	}
	fd = read_file(fname, fext);
	if (fd < 0)
		return (scene_free(scene), NULL);
	success = parse_scene(fd, scene);
	close(fd);
	if (!success)
		return (scene_free(scene), NULL);
	if (scene->objects && !obj_view(&scene->obj_view, scene->objects))
		return (scene_free(scene), NULL);
	if (scene->lights && !light_view(&scene->lgt_view, scene->lights))
		return (scene_free(scene), NULL);
	return (scene);
}
