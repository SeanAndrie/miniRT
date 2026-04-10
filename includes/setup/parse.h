/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:14:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 23:03:15 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <libft.h>

# define ERR_BASE "miniRT"
# define ERR_MISSING_EXT "%s: missing file extension '%s'\n"
# define ERR_INVALID_EXT "%s: invalid extension '%s', expected '%s'\n"

typedef struct s_vec3		t_vec3;
typedef struct s_scene		t_scene;
typedef struct s_options	t_options;

t_bool						parse_scene(int fd, t_scene *scene);
char						**parse_data(char *line, const size_t n_params);
t_bool						parse_orient(const char *nptr, t_vec3 *vec);
t_bool						parse_vector(const char *nptr, float min, float max,
								t_vec3 *vec);
t_bool						parse_scalar(const char *nptr, float min, float max,
								float *n);
void						parse_optional(char *line, t_options *opt);

t_bool						parse_camera(char *line, size_t n_params,
								t_scene *scene);
t_bool						parse_ambient(char *line, const size_t n_params,
								t_scene *scene);
t_bool						parse_light(char *line, const size_t n_params,
								t_scene *scene);
t_bool						parse_sphere(char *line, const size_t n_params,
								t_scene *scene);
t_bool						parse_plane(char *line, const size_t n_params,
								t_scene *scene);
t_bool						parse_cylinder(char *line, const size_t n_params,
								t_scene *scene);
t_bool						parse_cone(char *line, const size_t n_params,
								t_scene *scene);

t_bool						scalar_in_range(float n, float min, float max);
void						tok_free(char **tok, int n);
t_bool						is_valid_id(const char *id);

#endif
