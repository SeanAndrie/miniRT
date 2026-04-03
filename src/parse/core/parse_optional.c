/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:53:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 18:05:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elements/object.h>
#include <setup/parse.h>
#include <stdio.h>

static void parse_params(char **params, size_t count, t_options *opt)
{
    size_t  i;
    char    *value;

    i = 0;
    while (i < count && params[i])
    {
        value = ft_strchr(params[i], ':');
        if (value && ft_strncmp(params[i], "cb", 2) == 0)
            opt->cb_scale = ft_strtof(++value, NULL);
        i++;
    }
}

void    parse_optional(char *line, t_options *opt)
{
    size_t  count;
    char    **params;

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
