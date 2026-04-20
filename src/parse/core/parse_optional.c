/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:53:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:36:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <errno.h>
#include <setup/parse.h>

static int	parse_float_param(char *value, float *dest)
{
	char	*endptr;

	*dest = ft_strtof(value, &endptr);
	if (*endptr != '\0' || errno == ERANGE)
		return (0);
	return (1);
}

static void	parse_str_param(char *value, char **dest)
{
	char	*end;

	*dest = ft_strdup(value);
	if (*dest)
	{
		end = *dest + ft_strlen(*dest) - 1;
		while (end > *dest && (*end == '\n' || *end == '\r' || *end == ' '
				|| *end == '\t'))
			*end-- = '\0';
	}
}

static void	parse_params(char **params, size_t count, t_options *opt)
{
	size_t	i;
	char	*value;

	i = 0;
	while (i < count && params[i])
	{
		value = ft_strchr(params[i], ':');
		if (value && ft_strncmp(params[i], "cb", 2) == 0)
			parse_float_param(++value, &opt->cb_scale);
		else if (value && ft_strncmp(params[i], "rf", 2) == 0)
			parse_float_param(++value, &opt->reflectivity);
		else if (value && ft_strncmp(params[i], "sc", 2) == 0)
			parse_str_param(++value, &opt->specularity);
		else if (value && ft_strncmp(params[i], "bm", 2) == 0)
			parse_str_param(++value, &opt->bump_path);
		else if (value && ft_strncmp(params[i], "tx", 2) == 0)
			parse_str_param(++value, &opt->texture_path);
		i++;
	}
}

void	parse_optional(char *line, t_options *opt)
{
	size_t	count;
	char	**params;

	if (!line || !opt)
		return ;
	line++;
	params = ft_split(line, ' ');
	if (!params)
		return ;
	count = 0;
	while (params[count])
		count++;
	if (count == 0)
		return ;
	parse_params(params, count, opt);
	tok_free(params, count);
}
