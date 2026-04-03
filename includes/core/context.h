/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:19:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/04 00:20:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include <core/render.h>
# include <elements/scene.h>
# include <pthread.h>
# include <setup/display.h>

# define SCENE_FILE_EXT ".rt"

# define TRANS_SPEED 1.0f
# define ROTATE_ANGLE 0.1f
# define PROP_INCREMENT 0.5f
# define TWEEN_FACTOR 0.2f

// Close App
# define XK_ESC 0xff1b

// Reset App
# define XK_R 0x0072

// X11 Masks
# define MASK_KEYPRESS 1
# define MASK_KEYRELEASE 2
# define MASK_BUTTONPRESS 4
# define MASK_CONFIGURENOTIFY 262144

// X11 Events
# define EVENT_KEYPRESS 2
# define EVENT_KEYRELEASE 3
# define EVENT_BUTTONPRESS 4
# define EVENT_DESTROYNOTIFY 17
# define EVENT_CONFIGURENOTIFY 22

// Mouse Events
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define MOUSE_SCROLLUP 4
# define MOUSE_SCROLLDOWN 5

// Property Mode
# define XK_P 0x0070
# define XK_H 0x0068
# define XK_T 0x0074

// Light Selection Mode
# define XK_L 0x006c

// Translation/Rotation
# define XK_A 0x0061
# define XK_S 0x0073
# define XK_W 0x0077
# define XK_D 0x0064
# define XK_Q 0x0071
# define XK_E 0x0065

// Rotation toggle
# define XK_SHIFT_L 0xffe1

typedef struct s_tween
{
	t_vec3				*curr;
	t_vec3				target;
	bool				(*update)(struct s_tween *tw, float t);
}						t_tween;

typedef struct s_context
{
	struct s_pool		pool;
	struct s_display	*disp;
	struct s_scene		*scene;
	struct s_object		*s_obj;
	struct s_light		*s_lgt;
	char				*fname;
	size_t				next_i;
	bool				dirty;
	bool				extend;
	bool				property;
	struct s_tween		tw_trans;
	struct s_tween		tw_rotate;
}						t_context;

bool					context_init(t_context *ctx, char *fname);
void					context_hooks(t_context *ctx);
void					context_reset(t_context *ctx);
void					context_free(t_context *context);

int						handle_keyrelease(int key_code, t_context *ctx);
int						handle_keypress(int keycode, t_context *ctx);
int						handle_mousepress(int button, int x, int y,
							t_context *ctx);

void					dispatch_rotate(int key_code, t_context *ctx);
void					dispatch_translate(int key_code, t_context *ctx);
void					dispatch_property(int key_code, t_context *ctx);

int						close_app(t_context *ctx);
void					reset_app(t_context *ctx);

bool					movement_keys(int key_code);
bool					property_keys(int key_code);

void					tween_update(t_context *ctx, const float t);
bool					tween_slerp_update(t_tween *tw, float t);
bool					tween_lerp_update(t_tween *tw, float t);
t_tween					tween_rotation(t_vec3 *pos);
t_tween					tween_translation(t_vec3 *pos);

#endif
