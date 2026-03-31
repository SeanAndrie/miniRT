/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 23:12:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 18:48:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define SPECULAR_SHINE 45.0f

# include <elements/scene.h>
# include <libtensr_rt.h>
# include <setup/display.h>

typedef struct s_ray
{
	struct s_vec3	orig;
	struct s_vec3	dir;
}					t_ray;

typedef struct s_hit
{
	float			t;
	struct s_vec3	rgb;
	struct s_object	*obj;
	struct s_vec3	point;
	struct s_vec3	normal;
	struct s_vec3	ray_dir;
}					t_hit;

typedef struct s_tile_map
{
	int				tx;
	int				ty;
	int				actual_w;
	int				actual_h;
}					t_tile_map;

typedef struct s_tile
{
	struct s_tensr	*rdir;
	struct s_tensr	*buffer;
}					t_tile;

bool				render(t_display *disp, t_scene *scene);
bool				render_init(t_display *disp, t_scene *scene);
// bool				render_trace(t_vec3 orig, t_vec3 dir, t_hit *hit,
// 						t_scene *scene);
bool	            render_trace(t_ray ray, t_hit *hit, t_scene *scene);
bool				frame_blit(t_display *disp);

float				isect_obj(t_ray *ray, t_object *obj);
float				isect_plane(t_ray *ray, t_plane *pl);
float				isect_sphere(t_ray *ray, t_sphere *sp);
float				isect_cylinder(t_ray *ray, t_cylinder *cy);
float				isect_cone(t_ray *ray, t_cone *co);

t_vec3				normal_sphere(t_vec3 point, t_sphere *sp);
t_vec3				normal_plane(t_vec3 ray_dir, t_plane *pl);
t_vec3				normal_cylinder(t_vec3 point, t_cylinder *cy, float t);
t_vec3				normal_cone(t_vec3 point, t_cone *co, float t);

t_vec3				ray_at(t_ray ray, float t);
t_ray   ray_create(t_vec3 orig, const t_tensr *rdir, int x, int y);
// t_ray				ray_create(t_camera *cam, int x, int y);

void				shade_apply(t_scene *scene, t_hit *hit, float *ptr);
t_vec3				shade_ambient(t_ambient *amb, t_vec3 rgb);
t_vec3				shade_diffuse(float ratio, t_vec3 light_rgb, t_hit *hit,
						t_vec3 L_hat);
t_vec3				shade_specular(t_scene *scene, t_light *light, t_hit *hit,
						t_vec3 L_hat);
void				color_fill(float *ptr, t_vec3 *rgb);

bool				tile_create(t_tile *tile, t_tensr *buffer, t_tensr *rdir,
						t_tile_map *tm);
void				tile_free(t_tile *tile);

#endif
