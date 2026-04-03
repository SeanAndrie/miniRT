/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:25:34 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/03 17:03:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr_rt.h>
#include <setup/parse.h>
#include <elements/scene.h>
#include <stdio.h>

bool	parse_vector(const char *nptr, float min, float max, t_vec3 *vec)
{
	int		i;
	char	**tok;

	if (!nptr || !*nptr)
		return (false);
	tok = ft_split(nptr, ',');
	if (!tok)
		return (false);
	i = 0;
	while (tok[i])
        i++;
	if (i > 3 || i < 3)
		return (tok_free(tok, -1), false);
	vec->x = ft_strtof(tok[0], NULL);
	if (!scalar_in_range(vec->x, min, max))
		return (tok_free(tok, -1), false);
	vec->y = ft_strtof(tok[1], NULL);
	if (!scalar_in_range(vec->y, min, max))
		return (tok_free(tok, -1), false);
	vec->z = ft_strtof(tok[2], NULL);
	if (!scalar_in_range(vec->z, min, max))
		return (tok_free(tok, -1), false);
	tok_free(tok, -1);
	return (true);
}
