/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:25:34 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 19:43:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <core/parse.h>
#include <core/scene.h>

t_tensr	*parse_vector(const char *nptr)
{
	double	vec[3];
	t_array	vec_a;
	char	**tok;
	int		i;

	if (!nptr || !*nptr)
		return (NULL);
	tok = ft_split(nptr, ',');
	if (!tok)
		return (NULL);
	i = 0;
	while (tok[i])
		i++;
	if (i > 3)
    {
        tok_free(tok, -1);
        return (false);
    }
	i = -1;
	while (++i < 3)
		vec[i] = ft_strtod(tok[i], NULL);
	tok_free(tok, -1);
	vec_a = arr_f64(vec, 3);
	return (tensr_from_arr(&vec_a, 1, (size_t[]){3}, DT_F64));
}
