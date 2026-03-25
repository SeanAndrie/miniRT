/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:36:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 03:51:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	app_free(t_app *app)
{
	if (app->disp)
		display_free(app->disp);
	if (app->scene)
		scene_free(app->scene);
}

static bool	app_start(t_app *app, const char *fname)
{
	app->scene = scene_init(fname, SCENE_FILE_EXT);
	if (!app->scene)
		return (false);
	scene_info(app->scene);
	app->disp = display_init(W, H, TITLE);
	if (!app->disp)
	{
		scene_free(app->scene);
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_app	app;

	if (ac != 2)
	{
		log_error(ERR_NONE, ERR_BASE, "usage: ./minirt <filename>.rt\n");
		return (1);
	}
	if (!app_start(&app, av[1]))
		return (1);
	if (!render(app.disp, app.scene))
	{
		app_free(&app);
		return (1);
	}
	mlx_loop(app.disp->conn);
	app_free(&app);
	return (0);
}
