# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/09 15:21:04 by fileonar          #+#    #+#              #
#    Updated: 2025/06/10 16:29:58 by fileonar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBMLX = ./MLX42
LIBFT = ./libft
LIB = -lft -L$(LIBFT)/ -lmlx42 -L$(LIBMLX)/build -lglfw
INCLUDES = -I $(LIBMLX)/include -I $(LIBFT)/

NAME = cub3d
HEADER = cub3d.h
SRC = main.c \
	map_checks.c \
	
OBJS = $(SRC:%.c=bin/%.o)

all: $(NAME)

bin:
	@mkdir -p bin

bin/%.o : %.c $(HEADER) | bin
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBMLX)/build/libmlx42.a:
	@git submodule update --init $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

./libft/libft.a:
	@git submodule update --init $(LIBFT)
	@make -C $(LIBFT)

$(NAME): $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a $(OBJS)
	$(CC) $(OBJS) $(LIB) -ldl $(INCLUDES) $(CFLAGS) -o $(NAME)

clean:
	@rm -fr bin

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# ifeq ($(DEBUG),1)
# CFLAGS+=-g3
# clean_when_debug: fclean
# endif