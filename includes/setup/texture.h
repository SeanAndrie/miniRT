/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:42:03 by zsalih            #+#    #+#             */
/*   Updated: 2026/04/12 02:00:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <libtensr.h>
# include <core/context.h>

typedef struct s_image	t_texture;

void					texture_init(t_context *ctx);
t_bool					texture_load(t_context *ctx, t_texture **tex,
							char **path, char *label);
t_vec3					texture_color(t_texture *tex, double u, double v);

t_vec3					bump_gradient(t_texture *tex, double u, double v);
t_vec3					bump_normal(t_hit *hit);

#endif
