/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 15:31:01 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/05 16:49:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/parse.h>

t_bool is_valid_id(const char *id)
{
	if (*id == ' ' || *id == 'A' || *id == 'C' || *id == 'L')
		return (TRUE);
	if (ft_strcmp(id, "sp") == 0 || ft_strcmp(id, "pl") == 0 || ft_strcmp(id,
			"cy") == 0 || ft_strcmp(id, "co") == 0)
		return (TRUE);
	return (FALSE);
}
