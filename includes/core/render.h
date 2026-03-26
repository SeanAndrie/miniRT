/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 23:12:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 00:39:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define SPECULAR_SHINE 45.0f

# include <context.h>
# include <libtensr_rt.h>

typedef struct s_ray
{
	struct s_vec3			orig;
	struct s_vec3			dir;
}							t_ray;

typedef struct s_isect
{
	float					t;
	struct s_object			*obj;
}							t_isect;

typedef struct s_hit
{
	float					t;
	struct s_vec3			rgb;
	struct s_vec3			point;
	struct s_vec3			normal;
	struct s_object			*obj;
}							t_hit;

typedef struct s_tile_map
{
	int						tx;
	int						ty;
	int						actual_w;
	int						actual_h;
}							t_tile_map;

bool						render(t_display *disp, t_scene *scene);
bool						render_init(t_display *disp, t_scene *scene);

bool						render_trace(t_ray *ray, t_hit *hit,
								t_scene *scene);

float						isect_obj(t_ray *ray, t_object *obj);

float						isect_plane(t_ray *ray, t_plane *pl);
float						isect_sphere(t_ray *ray, t_sphere *sp);
float						isect_cylinder(t_ray *ray, t_cylinder *cy);
float						isect_cone(t_ray *ray, t_cone *co);

t_vec3						normal_sphere(t_vec3 point, t_sphere *sp);
t_vec3						normal_plane(t_vec3 ray_dir, t_plane *pl);
t_vec3						normal_cylinder(t_vec3 point, t_cylinder *cy,
								float t);
t_vec3						normal_cone(t_vec3 point, t_cone *co, float t);

t_vec3						ray_at(t_ray ray, float t);
t_ray						ray_create(t_camera *cam, int x, int y);

t_vec3						shade_ambient(t_ambient *amb, t_vec3 rgb);
t_vec3						shade_diffuse(float ratio, t_vec3 light_rgb,
								t_hit *hit, t_vec3 L_hat);
t_vec3						shade_specular(t_scene *scene, t_light *light,
								t_hit *hit, t_vec3 L_hat);

bool						framebuf_to_image(t_display *disp);
t_tensr						*framebuf_tile(t_tensr *framebuf, t_tile_map *tm);

void						color_fill(float *ptr, t_vec3 *rgb);
t_project					get_projection(t_vec3 v, t_vec3 u_hat);

#endif
