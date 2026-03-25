# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 01:40:38 by sgadinga          #+#    #+#              #
#    Updated: 2026/03/25 00:20:01 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minirt
CC := cc
INCS := -Iincludes -Iincludes/core -Iincludes/elements -Ilibft/includes -Ilibtensr/includes -Iminilibx-linux
CFLAGS := -Wall -Werror -Wextra $(INCS) -O3

MLX_FLAGS := -lXext -lX11 -lm -lz

LIBS := -Llibft -Llibtensr -Lminilibx-linux -lmlx -ltensr -lft

SRC_DIR := src
OBJ_DIR := obj

OBJECT_DIR := objects
PARSE_DIR := parse
SCENE_DIR := scene
DISPLAY_DIR := display
RENDER_DIR := render

OBJECT_SRCS := $(addprefix $(OBJECT_DIR)/core/, obj_alloc.c obj_free.c obj_prepend.c obj_append.c) \
				$(addprefix $(OBJECT_DIR)/shapes/, obj_sphere.c obj_plane.c obj_cylinder.c obj_cone.c)

PARSE_SRCS := $(addprefix $(PARSE_DIR)/core/, parse_scene.c parse_param.c parse_data.c parse_vector.c tok_free.c) \
				$(addprefix $(PARSE_DIR)/elements/, parse_ambient.c parse_camera.c parse_light.c parse_sphere.c parse_plane.c parse_cylinder.c parse_cone.c)

SCENE_SRCS := $(addprefix $(SCENE_DIR)/, \
			    $(addprefix core/, scene_init.c scene_info.c scene_free.c) \
				$(addprefix light/, light_append.c light_prepend.c light_free.c))

DISPLAY_SRCS := $(addprefix $(DISPLAY_DIR)/, display_init.c display_free.c)

RENDER_SRCS := $(addprefix $(RENDER_DIR)/, \
				 $(addprefix core/, render.c render_init.c render_trace.c) \
			   	 $(addprefix elements/intersect/, isect_obj.c isect_sphere.c isect_plane.c isect_cylinder.c isect_cone.c) \
				 $(addprefix elements/normal/, normal_sphere.c normal_plane.c normal_cylinder.c normal_cone.c) \
				 $(addprefix ray/, ray_at.c ray_create.c) \
				 $(addprefix shade/, shade_ambient.c shade_diffuse.c shade_specular.c) \
				 $(addprefix utils/, get_projection.c color_fill.c framebuf_to_image.c framebuf_tile.c))

SRCS := $(addprefix $(SRC_DIR)/, main.c $(PARSE_SRCS) $(OBJECT_SRCS) $(SCENE_SRCS) $(DISPLAY_SRCS) $(RENDER_SRCS))
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
