/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:25:34 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/23 19:33:04 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr_rt.h>
#include <core/parse.h>
#include <elements/scene.h>

bool	parse_vector(const char *nptr, t_vec3 *vec)
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
	{
		tok_free(tok, -1);
		return (false);
	}
	vec->x = ft_strtof(tok[0], NULL);
	vec->y = ft_strtof(tok[1], NULL);
	vec->z = ft_strtof(tok[2], NULL);
	tok_free(tok, -1);
	return (true);
}
