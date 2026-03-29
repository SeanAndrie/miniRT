/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_app.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:54:03 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 15:54:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/context.h>

int close_app(t_context *ctx)
{
    context_free(ctx);
    exit(EXIT_SUCCESS);
    return (0);
}
