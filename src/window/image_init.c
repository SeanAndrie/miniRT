/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:20:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/14 01:11:08 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <utils/window.h>

static bool	create_layout(const int ndim, const size_t *shape, t_layout *l)
{
	int	i;

	if (ndim < 0 || !shape || !l)
		return (false);
	if (!layout_alloc(ndim, l))
		return (false);
	i = -1;
	while (++i < ndim)
		l->shape[i] = shape[i];
	i = ndim - 2;
	l->stride[ndim - 1] = 1;
	while (i >= 0)
	{
		l->stride[i] = l->stride[i + 1] * l->shape[i + 1];
		i--;
	}
	return (true);
}

bool    image_init(t_mlx *mlx, const int width, const int height)
{
	t_layout	l;
	t_img		*img;

	if (!mlx || !mlx->conn)
		return (false);
	mlx->img.img = mlx_new_image(mlx->conn, width, height);
	if (!mlx->img.img)
		return (false);
	img = &mlx->img;
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len,
			&img->endian);
	if (!img->addr)
		return (false);
	if (!create_layout(3, (size_t[]){width, height, 3}, &l))
		return (NULL);
	mlx->img_v = tensr_view(NULL, img->addr, &l);
	if (!mlx->img_v)
		return (false);
	mlx->img_v->dtype = DT_U8;
	mlx->img_v->elemsize = 1;
    return (true);
}
