/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:17:19 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 18:05:21 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <setup/parse.h>

t_bool	parse_scalar(const char *nptr, float min, float max, float *n)
{
	float	v;
	char	*endptr;

	if (!nptr || !*nptr)
		return (FALSE);
	v = ft_strtof(nptr, &endptr);
	if (*endptr != '\0' || errno == ERANGE)
		return (FALSE);
	if (!scalar_in_range(v, min, max))
		return (FALSE);
	*n = v;
	return (TRUE);
}
