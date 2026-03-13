# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/10 01:40:38 by sgadinga          #+#    #+#              #
#    Updated: 2026/03/13 03:39:40 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minirt
CC := cc
INCS := -Iincludes -Iincludes/core -Ilibft/includes -Ilibtensr/includes -Iminilibx-linux
CFLAGS := -Wall -Werror -Wextra $(INCS)

MLX_FLAGS := -lXext -lX11 -lm -lz

LIBS := -Llibft -Llibtensr -Lminilibx-linux -lmlx -ltensr -lft

SRC_DIR := src
OBJ_DIR := obj

OBJECT_DIR := object
SCENE_DIR := scene
PARSE_DIR := parse

OBJECT_SRCS := $(addprefix $(OBJECT_DIR)/, \
					$(addprefix constructor/, obj_alloc.c) \
					$(addprefix initializer/, obj_sphere.c obj_plane.c obj_cylinder.c) \
					$(addprefix operations/, obj_prepend.c obj_append.c obj_free.c))

SCENE_SRCS := $(addprefix $(SCENE_DIR)/, \
					$(addprefix constructor/, scene_init.c) \
					$(addprefix operations/, scene_info.c scene_free.c ambient_free.c camera_free.c light_free.c))

PARSE_SRCS := $(addprefix $(PARSE_DIR)/, parse_scene.c \
				$(addprefix utils/, parse_param.c parse_data.c parse_vector.c tok_free.c) \
				$(addprefix entities/, parse_ambient.c parse_camera.c parse_light.c parse_sphere.c parse_plane.c parse_cylinder.c))

SRCS := $(addprefix $(SRC_DIR)/, main.c $(PARSE_SRCS) $(OBJECT_SRCS) $(SCENE_SRCS))
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
