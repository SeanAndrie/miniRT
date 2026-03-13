/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:36:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 01:38:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>
#include <stdio.h>

int main(int ac, char **av)
{
    t_scene *scene;

    if (ac != 2)
    {
        log_error(ERR_NONE, ERR_BASE, "usage: ./minirt <filename>.rt\n");
        return (1);
    }
    scene = scene_init(av[1], SCENE_FILE_EXT);
    if (!scene)
        return (1);
    scene_info(scene);
    scene_free(scene);
    return (0);
}
