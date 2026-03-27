/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:19:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/27 04:19:14 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include <elements/scene.h>
# include <setup/display.h>

# define SCENE_FILE_EXT ".rt"

typedef struct s_context
{
	struct s_display	*disp;
	struct s_scene		*scene;
	struct s_object		*select;
	char				*fname;
	bool				rotate;
}						t_context;

# define TRANS_SPEED 1.0f
# define ROTATE_ANGLE 0.1f

// X11 KeySym
# define XK_r 0x0072
# define XK_Esc 0xff1b

// X11 Masks
# define KeyPressMask 1L << 0
# define KeyReleaseMask 1L << 1
# define ButtonPressMask 1L << 2

// X11 Events
# define KeyPress 2
# define KeyRelease 3
# define ButtonPress 4
# define DestroyNotify 17

// Mouse Events
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define MOUSE_SCROLLUP 4
# define MOUSE_SCROLLDOWN 5

// Translation
# define XK_a 0x0061
# define XK_s 0x0073
# define XK_w 0x0077
# define XK_d 0x0064
# define XK_q 0x0071
# define XK_e 0x0065

// Rotation
# define XK_Left 0xff51
# define XK_Right 0xff53

// Rotation toggle
# define XK_Shift_L 0xffe1

bool					context_init(t_context *ctx, char *fname);
void					context_hooks(t_context *ctx);
void					context_free(t_context *context);

int						handle_keyrelease(int key_code, t_context *ctx);
int						handle_keypress(int keycode, t_context *ctx);
int						handle_mousepress(int button, int x, int y,
							t_context *ctx);

void					dispatch_rotate(int key_code, t_context *ctx);
void					dispatch_translate(int key_code, t_context *ctx);

#endif
