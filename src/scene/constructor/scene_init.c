/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:30:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 01:29:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>
#include <core/parse.h>
#include <core/scene.h>

static bool	has_valid_extension(const char *fname, const char *ext)
{
	char	*dot;

	if (!ext)
	{
		log_error(ERR_WARNING, ERR_BASE, "missing file extension.\n");
		return (false);
	}
	dot = ft_strrchr(fname, '.');
	if (!dot || dot == fname)
	{
		log_error(ERR_WARNING, ERR_BASE, ERR_MISSING_EXT, ext);
		return (false);
	}
	if (ft_strcmp(dot, ext) != 0)
	{
		log_error(ERR_WARNING, ERR_BASE, ERR_INVALID_EXT, dot, ext);
		return (false);
	}
	return (true);
}

static int read_file(const char *fname)
{
    int fd;

    fd = open(fname, O_RDONLY);
    if (fd < 0)
		log_error(ERR_WARNING, ERR_BASE, "'%s' not found\n", fname);
    return (fd);
}

t_scene	*scene_init(const char *fname, const char *ext)
{
    int     fd;
	t_scene	*scene;
    bool    success;

	if (!fname)
	{
		log_error(ERR_WARNING, ERR_BASE, "missing scene file\n");
		return (NULL);
	}
	if (!has_valid_extension(fname, ext))
		return (NULL);
	scene = malloc(sizeof(t_scene));
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
