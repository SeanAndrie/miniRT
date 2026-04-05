/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:25:34 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/05 17:44:08 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <libtensr_rt.h>
#include <setup/parse.h>
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
		return (tok_free(tok, i), false);
	if (!parse_scalar(tok[0], min, max, &vec->x))
		return (tok_free(tok, i), false);
	if (!parse_scalar(tok[1], min, max, &vec->y))
		return (tok_free(tok, i), false);
	if (!parse_scalar(tok[2], min, max, &vec->z))
		return (tok_free(tok, i), false);
	tok_free(tok, i);
	return (true);
}
