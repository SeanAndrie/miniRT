/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:36:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 12:41:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libtensr.h>
#include <miniRT.h>

int	main(int ac, char **av)
{
    t_display   disp;
	t_scene	    *scene;

	if (ac != 2)
	{
		log_error(ERR_NONE, ERR_BASE, "usage: ./minirt <filename>.rt\n");
		return (1);
	}
	scene = scene_init(av[1], SCENE_FILE_EXT);
	if (!scene)
		return (1);
    scene_info(scene);
    if (!display_init(&disp, W, H, TITLE))
        return (scene_free(scene), 1);
    if (!render_init(&disp, scene))
    {
        display_free(&disp);
	    scene_free(scene);
        return (1);
    }
    if (!render(&disp, scene))
    {
        display_free(&disp);
	    scene_free(scene);
        return (1);
    }
    mlx_loop(disp.conn);
    display_free(&disp);
	scene_free(scene);
	return (0);
}
