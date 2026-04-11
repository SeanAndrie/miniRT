/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:42:03 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/11 02:18:49 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

#include <mlx.h>
#include <libft.h>
#include <stdbool.h>
#include <libtensr_rt.h>
#include <context.h>
#include <core/render.h>

#define LUMA_RED    0.299
#define LUMA_GREEN  0.587
#define LUMA_BLUE   0.114

typedef struct s_image t_texture;

void	texture_init(t_context *ctx);
bool	texture_load(t_context *ctx, t_texture **tex, char **path, char *label);
t_vec3	texture_color(t_texture *tex, double u, double v);

t_vec3	bump_gradient(t_texture *tex, double u, double v);
t_vec3  bump_normal(t_hit *hit);

#endif