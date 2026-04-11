/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:19:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:44:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include <config.h>
# include <pthread.h>
# include <core/render.h>

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

// Toggle UI
# define XK_U 0x0075

typedef struct s_tween
{
	struct s_vec3		*curr;
	struct s_vec3		target;
	enum e_bool			(*update)(struct s_tween *tw, float t);
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
	enum e_bool			dirty;
	enum e_bool			extend;
	enum e_bool			property;
	enum e_bool			show_ui;
	struct s_tween		tw_trans;
	struct s_tween		tw_rotate;
}						t_context;

t_bool					context_init(t_context *ctx, char *fname);
int						context_loop(t_context *ctx);
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

t_bool					movement_keys(int key_code);
t_bool					property_keys(int key_code);

void					tween_update(t_context *ctx, const float t);
t_bool					tween_slerp_update(t_tween *tw, float t);
t_bool					tween_lerp_update(t_tween *tw, float t);
t_tween					tween_rotation(t_vec3 *pos);
t_tween					tween_translation(t_vec3 *pos);

void					interface_render(t_context *ctx, const int line_h);
void					interface_object(t_context *ctx, int x, int *y,
							const int line_h);

#endif
