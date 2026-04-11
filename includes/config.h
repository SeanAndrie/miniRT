/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 23:01:58 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 02:04:11 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define TITLE "miniRT"
# define SCENE_FILE_EXT ".rt"

// Window Dimensions
# define W 1280
# define H 720

// Multithreading Settings
# define MULTITHREADED TRUE
# define N_THREADS 8

// Tile size (N_TILES x N_TILES)
# define N_TILES 256

// Specular Shine Factor
# define SPECULAR_SHINE 45.0f

// Interface Settings
# define TEXT_COLOR 0xFFFFFF
# define LINE_HEIGHT 20

// Tween Settings
# define TWEEN_FACTOR 0.2f
# define TRANS_SPEED 1.2f
# define ROTATE_ANGLE 0.2f
# define PROP_INCREMENT 0.5f

// Texture Settings
# define LUMA_RED 0.299
# define LUMA_GREEN 0.587
# define LUMA_BLUE 0.114

#endif
