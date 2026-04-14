/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:36:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/14 03:19:32 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int ac, char **av)
{
	t_context	ctx;
	t_bonus		bonus;

	if (ac != 2)
	{
		log_error(ERR_NONE, ERR_BASE, "usage: ./minirt <filename>.rt\n");
		return (1);
	}
	ft_memset(&bonus, TRUE, sizeof(t_bonus));
	if (!context_init(&ctx, av[1], &bonus))
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
