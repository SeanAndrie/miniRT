/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 23:12:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 23:04:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <pthread.h>
# include <libvec3.h>
# include <semaphore.h>
# include <setup/display.h>
# include <elements/scene.h>

typedef struct s_worker t_worker;
typedef struct s_pool   t_pool;

typedef enum e_surface
{
	SURF_SIDE,
	SURF_TOP,
	SURF_BOT
}					t_surface;

typedef struct s_ray
{
	struct s_vec3	orig;
	struct s_vec3	dir;
}					t_ray;

typedef struct s_hit
{
	float			t;
	enum e_surface	loc;
	struct s_ray	ray;
	struct s_vec3	rgb;
	struct s_object	*obj;
	struct s_vec3	point;
	struct s_vec3	normal;
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
	int				width;
	int				height;
}					t_tile;

typedef struct s_worker
{
	struct s_tile	*tiles;
	struct s_scene	*scene;
	pthread_t		thread;
	size_t			start;
	size_t			end;
}					t_worker;

typedef struct s_pool
{
	struct s_tile	*tiles;
	size_t			n_tiles;
	size_t			n_workers;
	struct s_worker	**workers;
	size_t			worker_tiles;
}					t_pool;

t_bool				render(t_display *disp, t_scene *scene);
t_bool				render_threaded(t_pool *pool, t_display *disp,
						t_scene *scene);
t_bool				render_init(t_pool *pool, t_display *disp, t_scene *scene);
t_bool				render_trace(t_ray ray, t_hit *hit, t_scene *scene);

float				isect_obj(t_ray *ray, t_surface *hit_loc, t_object *obj);
float				isect_plane(t_ray *ray, t_plane *pl);
float				isect_sphere(t_ray *ray, t_sphere *sp);
float				isect_cylinder(t_ray *ray, t_surface *hit_loc,
						t_cylinder *cy);
float				isect_cone(t_ray *ray, t_surface *hit_loc, t_cone *co);

t_vec3				normal_sphere(t_vec3 point, t_sphere *sp);
t_vec3				normal_plane(t_vec3 ray_dir, t_plane *pl);
t_vec3				normal_cylinder(t_hit *hit, t_cylinder *cy);
t_vec3				normal_cone(t_hit *hit, t_cone *co);

t_vec3				ray_at(t_ray ray, float t);
t_vec3				ray_reflect(t_vec3 dir, t_vec3 normal);
t_ray				ray_create(t_vec3 orig, const t_tensr *rdir, int x, int y);

t_vec3				shade_apply(t_scene *scene, t_hit *hit);
t_vec3				shade_color(t_scene *scene, t_hit *hit);
t_vec3				shade_checker(t_hit *hit, const float scale);
t_vec3				shade_ambient(t_ambient *amb, t_vec3 rgb);
t_vec3				shade_diffuse(float ratio, t_vec3 light_rgb, t_hit *hit,
						t_vec3 L_hat);
t_vec3				shade_specular(t_scene *scene, t_light *light, t_hit *hit,
						t_vec3 L_hat);
void				color_fill(float *ptr, t_vec3 rgb);

t_bool				tile_create(t_tile *tile, t_tensr *buffer, t_tensr *rdir,
						t_tile_map *tm);
void				tile_free(t_tile *tile, size_t n);

t_bool				pool_init(t_pool *pool, t_display *disp, t_scene *scene);
t_bool				pool_run(t_pool *pool);
t_bool				pool_join(t_pool *pool);
void				pool_free(t_pool *pool);

#endif
