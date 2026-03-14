/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:36:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/14 01:46:02 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <miniRT.h>

static bool	mlx_start(t_mlx *mlx)
{
	if (!mlx)
		return (false);
	ft_memset(mlx, 0, sizeof(t_mlx));
	mlx->conn = mlx_init();
	if (!mlx->conn)
		return (false);
	if (!window_init(mlx, WIDTH, HEIGHT, TITLE))
	{
		log_error(ERR_RUNTIME, ERR_BASE, "mlx: failed to initialize window\n");
		free(mlx->conn);
		return (false);
	}
	if (!image_init(mlx, WIDTH, HEIGHT))
	{
		log_error(ERR_RUNTIME, ERR_BASE, "mlx: failed to initialize image\n");
		free(mlx->win);
		free(mlx->conn);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_scene	*scene;

	if (ac != 2)
	{
		log_error(ERR_NONE, ERR_BASE, "usage: ./minirt <filename>.rt\n");
		return (1);
	}
	scene = scene_init(av[1], SCENE_FILE_EXT);
	if (!scene)
		return (1);
	if (!mlx_start(&mlx))
	{
		scene_free(scene);
		return (1);
	}
	mlx_put_image_to_window(mlx.conn, mlx.win, mlx.img.img, 0, 0);
	mlx_loop(mlx.conn);
	mlx_free(&mlx);
	scene_free(scene);
	return (0);
}
