/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:14:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 03:02:39 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <libft.h>

# define ERR_BASE "miniRT"
# define ERR_MISSING_EXT "missing file extension '%s'\n"
# define ERR_INVALID_EXT "invalid ext '%s', expected '%s'\n"

typedef struct s_vec3	t_vec3;
typedef struct s_scene	t_scene;

bool					parse_scene(int fd, t_scene *scene);
char					*parse_param(char **line, size_t *skip);
bool					parse_vector(const char *nptr, t_vec3 *v);
char					**parse_data(char *line, const size_t n_params);

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

void					tok_free(char **tok, int n);

#endif
