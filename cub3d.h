/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:21:01 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/12 13:33:48 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"


int validate_file_extension(char *map_name);
int validate_map(char **map);
int check_map_file(char *map_name);
char **parse_map(char *map_name);

int count_lines(int fd);

void free_map(char **map);

void render_background(mlx_t *mlx);

void error_msg(char *msg);
char	*gnl(int fd);


#endif