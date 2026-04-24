/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 23:01:58 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 14:09:03 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define TITLE "miniRT"
# define SCENE_FILE_EXT ".rt"

// Window Dimensions
# define W 854
# define H 480

// Multithreading Settings
# define N_THREADS 8

// Tile size (16x16)
# define N_TILES 256

// Object Property Minimum
# define PROP_MIN 0.0

// Specular Shine Factor
# define SPECULAR_SHINE 45.0f

// Number of reflection bounces
# define REFLECT_DEPTH 3

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

// Bump Mapping Settings
# define BUMP_SCALE 1.5f

// Texture Scale
# define TEXTURE_SCALE 0.2f

#endif
