/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:59:17 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/16 23:30:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/parse.h>

void	tok_free(char **tok, int n)
{
	if (!tok)
		return ;
	if (n > 0)
	{
		while (--n >= 0)
			free(tok[n]);
	}
	else if (n == -1)
	{
		while (tok[++n])
			free(tok[n]);
	}
	free(tok);
}
