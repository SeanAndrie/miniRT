/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:17:19 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 17:29:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <setup/parse.h>

bool    parse_scalar(const char *nptr, float min, float max, float *n)
{
    float   v;
    char    *endptr;

    if (!nptr || !*nptr)
        return (false);
    v = ft_strtof(nptr, &endptr);
    if (*endptr != '\0' || errno == ERANGE)
        return (false);
    if (!scalar_in_range(v, min, max))
        return (false);
    *n = v;
    return (true);
}
