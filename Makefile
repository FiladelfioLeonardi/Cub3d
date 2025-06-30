# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/09 15:21:04 by fileonar          #+#    #+#              #
#    Updated: 2025/06/30 17:01:45 by fefo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -g3

LIBMLX = ./MLX42
LIBFT = ./libft
LIB = -lft -L$(LIBFT)/ -lmlx42 -L$(LIBMLX)/build -lglfw
INCLUDES = -I $(LIBMLX)/include -I $(LIBFT)/

NAME = cub3d
HEADER = cub3d.h
SRC = main.c \
	map_checks.c \
	utils.c \
	gnl.c \
	render.c \
	handle_hooks.c \
	raycasting.c \
	printing_walls.c \
	setting_up.c
	
OBJS = $(SRC:%.c=bin/%.o)

all: $(NAME)
	@echo "All object files compiled successfully."

bin:
	@mkdir -p bin

bin/%.o : %.c $(HEADER) | bin
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBMLX)/build/libmlx42.a:
	@git submodule update --init $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

./libft/libft.a:
	@git submodule update --init $(LIBFT)
	@make -C $(LIBFT)

$(NAME): $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a $(OBJS)
	@$(CC) $(OBJS) $(LIB) -ldl -lm $(INCLUDES) $(CFLAGS) -o $(NAME)

clean:
	@rm -fr bin
	@make -C $(LIBFT) clean
	@echo "Cleaned ALL object files."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re

# ifeq ($(DEBUG),1)
# CFLAGS+=-g3
# clean_when_debug: fclean
# endif