/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:36:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 14:22:55 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int ac, char **av)
{
	t_context	ctx;

	if (ac != 2)
	{
		log_error(ERR_NONE, ERR_BASE, "usage: ./minirt <filename>.rt\n");
		return (1);
	}
	if (!context_init(&ctx, av[1]))
		return (1);
	if (!render_init(&ctx.pool, ctx.disp, ctx.scene))
	{
		context_free(&ctx);
		return (1);
	}
	context_hooks(&ctx);
	mlx_loop(ctx.disp->conn);
	context_free(&ctx);
	return (0);
}
