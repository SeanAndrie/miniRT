/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:17:19 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/14 14:56:35 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <setup/parse.h>

static void	range_error(const char *nptr, double min, double max)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "%s: warning: ", ERR_BASE);
	ft_dprintf(STDERR_FILENO, "value '%s' is out of range [%.1f, %.1f]\n", nptr,
		min, max);
}

t_bool	parse_scalar(const char *nptr, double min, double max, float *n)
{
	double  v;
	char	*endptr;

	if (!nptr || !*nptr)
		return (FALSE);
	v = ft_strtod(nptr, &endptr);
	if (*endptr != '\0' || errno == ERANGE)
		return (FALSE);
	if (!scalar_in_range(v, min, max))
	{
		range_error(nptr, min, max);
		return (FALSE);
	}
	*n = (float)v;
	return (TRUE);
}
