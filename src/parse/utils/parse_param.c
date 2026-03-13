/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:51 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/12 19:41:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/parse.h>
#include <core/scene.h>
#include <libtensr.h>

char	*parse_param(char **line, size_t *skip)
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
	if (!sub)
		return (NULL);
	*skip = ft_strlen(sub);
	return (sub);
}
