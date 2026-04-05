# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 01:40:38 by sgadinga          #+#    #+#              #
#    Updated: 2026/04/05 17:28:05 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minirt
CC := cc
INCS := -Iincludes -Iincludes/setup -Iincludes/elements -Iincludes/core -Ilibft/includes -Ilibtensr/includes -Iminilibx-linux
CFLAGS := -Wall -Wextra -Werror -std=gnu11 $(INCS)

MLX_FLAGS := -lXext -lX11 -lm -lz

LIBS := -Llibft -Llibtensr -Lminilibx-linux -lmlx -ltensr -lft

SRC_DIR := src
OBJ_DIR := obj

SCENE_DIR := scene
PARSE_DIR := parse
RENDER_DIR := render
OBJECT_DIR := objects
DISPLAY_DIR := display

CONTEXT_DIR := context

SCENE_SRCS := $(addprefix $(SCENE_DIR)/, \
	$(addprefix core/, scene_init.c scene_info.c scene_free.c) \
	$(addprefix elements/light/, light_append.c light_prepend.c light_free.c light_len.c light_view.c) \
	$(addprefix elements/camera/, camera_init.c camera_basis.c camera_coords.c camera_rdir.c camera_free.c))

PARSE_SRCS := $(addprefix $(PARSE_DIR)/core/, parse_scene.c parse_data.c parse_vector.c parse_orient.c parse_scalar.c parse_optional.c) \
	$(addprefix $(PARSE_DIR)/elements/, parse_ambient.c parse_camera.c parse_light.c parse_sphere.c parse_plane.c parse_cylinder.c parse_cone.c) \
	$(addprefix $(PARSE_DIR)/utils/, tok_free.c scalar_in_range.c is_valid_id.c)

RENDER_SRCS := $(addprefix $(RENDER_DIR)/, \
	$(addprefix core/, render.c render_init.c render_trace.c) \
	$(addprefix elements/isect/, isect_obj.c isect_sphere.c isect_plane.c isect_cylinder.c isect_cone.c) \
	$(addprefix elements/normal/, normal_sphere.c normal_plane.c normal_cylinder.c normal_cone.c) \
	$(addprefix ray/, ray_at.c ray_reflect.c ray_create.c) \
	$(addprefix shade/, shade_apply.c shade_color.c shade_ambient.c shade_diffuse.c shade_specular.c shade_checker.c) \
	$(addprefix pool/, pool_init.c pool_run.c pool_join.c pool_free.c) \
	$(addprefix tile/, tile_create.c tile_free.c))

OBJECT_SRCS := $(addprefix $(OBJECT_DIR)/, \
	$(addprefix core/, obj_alloc.c obj_free.c obj_prepend.c obj_append.c obj_len.c obj_view.c) \
	$(addprefix shapes/, obj_sphere.c obj_plane.c obj_cylinder.c obj_cone.c))

DISPLAY_SRCS := $(addprefix $(DISPLAY_DIR)/, \
	$(addprefix core/, display_init.c display_free.c) \
	$(addprefix frame/, frame_blit.c frame_free.c frame_init.c))

CONTEXT_SRCS := $(addprefix $(CONTEXT_DIR)/, \
	$(addprefix core/, context_init.c context_hooks.c context_reset.c context_free.c) \
	$(addprefix hooks/handle/, handle_keypress.c handle_mousepress.c handle_keyrelease.c) \
	$(addprefix hooks/dispatch/, dispatch_translate.c dispatch_rotate.c dispatch_property.c) \
	$(addprefix hooks/tween/, tween_update.c tween_lerp_update.c tween_slerp_update.c tween_translation.c tween_rotation.c) \
    $(addprefix utils/, close_app.c reset_app.c movement_keys.c property_keys.c))

SRCS := $(addprefix $(SRC_DIR)/, main.c $(PARSE_SRCS) $(OBJECT_SRCS) $(SCENE_SRCS) $(DISPLAY_SRCS) $(RENDER_SRCS) $(CONTEXT_SRCS))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: libft/libft.a libtensr/libtensr.a minilibx-linux/libmlx.a $(NAME)

minilibx-linux/libmlx.a:
	@make -C minilibx-linux

libtensr/libtensr.a:
	@make -C libtensr

libft/libft.a:
	@make -C libft

$(NAME): libft/libft.a libtensr/libtensr.a minilibx-linux/libmlx.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean
	@make -C libtensr clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@make -C libtensr fclean
	@make -C minilibx-linux clean

re: fclean all

.PHONY: re fclean clean all
