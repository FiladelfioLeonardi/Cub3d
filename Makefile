# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/09 15:21:04 by fileonar          #+#    #+#              #
#    Updated: 2025/06/10 15:01:47 by fileonar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
LIBMLX = ./MLX42
CFLAGS = -Wall -Werror -Wextra
LIB = -lft -Llibft/ -lmlx42 -L$(LIBMLX)/build -lglfw
HEADER = -I $(LIBMLX)/include -I libft/

NAME = cub3d
HEADER = cub3d.h
SRC = main.c
	
OBJS = $(SRC:%.c=bin/%.o)

all: $(NAME) 

bin/%.o : %.c $(HEADER) | bin
	$(CC) -c -o $@ $< $(CFLAGS) $(HEADER)

$(LIBMLX)/build/libmlx42.a:
	@git submodule update --init $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

./libft/libft.a:
	@git submodule update --init ./libft
	@make -C ./libft

$(NAME): $(LIBMLX)/build/libmlx42.a ./libft/libft.a $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB) -ldl $(HEADER) $(CFLAGS)

clean:
	@rm -fr bin/*
	@echo "washing my balls rn"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "dont forget to clean your 4skin"

re: fclean all

.PHONY: all clean fclean re clean_when_debug

# ifeq ($(DEBUG),1)
# CFLAGS+=-g3
# clean_when_debug: fclean
# endif