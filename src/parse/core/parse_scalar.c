/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:17:19 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/14 10:13:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include <setup/parse.h>

static void	print_float(double val)
{
	int	integer;
	int	fraction;

	if (val < 0)
	{
		ft_dprintf(STDERR_FILENO, "-");
		val = -val;
	}
	if (val > 2147483647.0)
	{
		ft_dprintf(STDERR_FILENO, "inf");
		return ;
	}
	integer = (int)val;
	fraction = (int)((val - integer) * 10000);
	ft_dprintf(STDERR_FILENO, "%d.%01d", integer, fraction);
}

static void	range_error(const char *nptr, double min, double max)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	log_error(ERR_WARNING, ERR_BASE, "value '%s' is out of range [", nptr);
	print_float(min);
	ft_dprintf(STDERR_FILENO, ", ");
	print_float(max);
	ft_dprintf(STDERR_FILENO, "]\n");
}

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
	{
		range_error(nptr, min, max);
		return (FALSE);
	}
	*n = v;
	return (TRUE);
}
