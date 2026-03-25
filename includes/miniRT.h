/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:37:03 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/24 01:57:06 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <core/parse.h>
# include <core/render.h>
# include <libft.h>
# include <mlx.h>

# define SCENE_FILE_EXT ".rt"

typedef struct s_app
{
	struct s_display	*disp;
	struct s_scene		*scene;
}						t_app;

#endif
