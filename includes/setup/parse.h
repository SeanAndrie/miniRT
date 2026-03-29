/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:14:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/26 17:30:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <libft.h>
# include <stdbool.h>

# define ERR_BASE "miniRT"
# define ERR_MISSING_EXT "%s: missing file extension '%s'\n"
# define ERR_INVALID_EXT "%s: invalid extension '%s', expected '%s'\n"

typedef struct s_vec3	t_vec3;
typedef struct s_scene	t_scene;

bool					parse_scene(int fd, t_scene *scene);
char					**parse_data(char *line, const size_t n_params);
bool					parse_vector(const char *nptr, float min, float max,
							t_vec3 *vec);
bool					parse_scalar(const char *nptr, float min, float max,
							float *n);

bool					parse_camera(char *line, size_t n_params,
							t_scene *scene);
bool					parse_ambient(char *line, const size_t n_params,
							t_scene *scene);
bool					parse_light(char *line, const size_t n_params,
							t_scene *scene);
bool					parse_sphere(char *line, const size_t n_params,
							t_scene *scene);
bool					parse_plane(char *line, const size_t n_params,
							t_scene *scene);
bool					parse_cylinder(char *line, const size_t n_params,
							t_scene *scene);
bool					parse_cone(char *line, const size_t n_params,
							t_scene *scene);

bool					scalar_in_range(float n, float min, float max);
void					tok_free(char **tok, int n);

#endif
