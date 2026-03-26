/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:30:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 19:52:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <fcntl.h>
#include <libft.h>
#include <libtensr.h>
#include <setup/parse.h>

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

// static t_object	**create_object_arr(t_scene *scene)
// {
// 	size_t		i;
// 	t_object	*curr;
// 	t_object	**ptrs;
//
// 	scene->n_objects = obj_len(scene->objects);
// 	ptrs = malloc(sizeof(t_object *) * scene->n_objects);
// 	if (!ptrs)
// 		return (NULL);
// 	i = 0;
// 	curr = scene->objects;
// 	while (curr)
// 	{
// 		ptrs[i++] = curr;
// 		curr = curr->next;
// 	}
// 	return (ptrs);
// }

static bool	valid_arguments(const char *fname, const char *fext)
{
	if (!fname)
	{
		log_error(ERR_WARNING, ERR_BASE, "missing scene file\n");
		return (false);
	}
	if (!has_valid_extension(fname, fext))
		return (false);
	return (true);
}

t_scene	*scene_init(const char *fname, const char *fext)
{
	int		fd;
	t_scene	*scene;
	bool	success;

	if (!valid_arguments(fname, fext))
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
	if (scene->objects && !obj_view(&scene->obj_view, scene->objects))
		return (scene_free(scene), NULL);
    if (scene->lights && !light_view(&scene->lgt_view, scene->lights))
		return (scene_free(scene), NULL);
	return (scene);
}
