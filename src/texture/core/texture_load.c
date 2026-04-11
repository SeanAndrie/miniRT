/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:08:23 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/12 01:49:15 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <setup/texture.h>

t_bool	texture_load(t_context *ctx, t_texture **tex, char **path, char *label)
{
	*tex = ft_calloc(1, sizeof(t_texture));
	if (!*tex)
	{
		ft_dprintf(STDERR_FILENO, "Failed to allocate memory for %s\n", label);
		return (FALSE);
	}
	(*tex)->image = mlx_xpm_file_to_image(ctx->disp->conn, *path,
			&(*tex)->width, &(*tex)->height);
	if (!(*tex)->image)
	{
		free(*tex);
		*tex = NULL;
		ft_dprintf(STDERR_FILENO, "Failed to load %s: %s\n", label, *path);
		return (FALSE);
	}
	(*tex)->addr = mlx_get_data_addr((*tex)->image, &(*tex)->bpp,
			&(*tex)->line_len, &(*tex)->endian);
	if (!(*tex)->addr)
		return (FALSE);
	return (TRUE);
}
