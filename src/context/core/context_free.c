/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:44:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/25 16:04:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <context.h>

void	context_free(t_context *context)
{
	if (context->disp)
		display_free(context->disp);
	if (context->scene)
		scene_free(context->scene);
}
