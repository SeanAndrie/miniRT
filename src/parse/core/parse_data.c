/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:47:12 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 21:11:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/parse.h>
#include <elements/scene.h>

char	**parse_data(char *line, const size_t n_params)
{
	size_t	i;
	size_t	skip;
	char	**params;

	if (!line || n_params == 0)
		return (false);
	params = malloc(sizeof(char *) * (n_params + 1));
	if (!params)
		return (NULL);
	i = 0;
	while (*line && i < n_params)
	{
		while (*line && ft_isspace(*line))
			line++;
		params[i] = parse_param(&line, &skip);
		if (!params[i])
			return (tok_free(params, i), NULL);
		line += skip;
		i++;
	}
	params[i] = NULL;
	return (params);
}
