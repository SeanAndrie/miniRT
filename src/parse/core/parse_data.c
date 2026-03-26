/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:47:12 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 16:46:25 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/scene.h>
#include <setup/parse.h>

static char	*parse_param(char **line, size_t *skip)
{
	char	*sub;
	char	*end;

	*skip = 0;
	if (!line || !*line)
		return (NULL);
	end = *line;
	while (*end && (ft_isdigit(*end) || *end == ',' || *end == '.'
			|| *end == '+' || *end == '-'))
		end++;
	sub = ft_substr(*line, 0, (end - *line));
	if (!sub || !*sub)
		return (NULL);
	*skip = ft_strlen(sub);
	return (sub);
}

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
