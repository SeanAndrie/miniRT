/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 20:29:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/13 01:27:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_tensr	t_tensr;
typedef struct s_object t_object;

typedef enum s_entity
{
    SCENE_OBECT,
    SCENE_ELEMENT
}           t_entity;

/*---------------------------------------------------------------------*/
/*                         1. SCENE ELEMENTS                           */
/*---------------------------------------------------------------------*/

typedef struct s_ambient
{
	double ratio;        // Ambient light ratio
	struct s_tensr *rgb; // RGB Colors
}						t_ambient;

typedef struct s_camera
{
	double fov;             // Horizontal Field of View (in degrees)
	struct s_tensr *view;   // Coordinates of viewpoint
	struct s_tensr *orient; // Normalized orientation vector
}						t_camera;

typedef struct s_light
{
	double ratio;          // Brightness ratio
	struct s_tensr *rgb;   // RGB Colors
	struct s_tensr *point; // Coordinates of light point
	// struct s_light *next;  // Pointer to next light source
}						t_light;

typedef struct s_scene
{
    struct s_ambient    amb;
    struct s_camera     cam;
    struct s_light      light;
    struct s_object     *head;
}                       t_scene;

void            light_free(t_light *light);
void            camera_free(t_camera *camera);
void            ambient_free(t_ambient *ambient);

void            scene_free(t_scene *scene);
void            scene_info(t_scene *scene);
t_scene         *scene_init(const char *fname, const char *ext);

#endif
