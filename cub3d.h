/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:21:01 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/30 11:15:29 by amecani          ###   ########.fr       */
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

#define WIDTH 800
#define HEIGHT 600
# define FOV 0.66
#define ROTATION_S	0.04
#define SPEED		0.04
// # define FOV 999

//* Replace parsing

typedef struct s_vec
{
	double	x;
	double	y;
}	t_vec;

typedef struct s_all
{
	char			**mappa;
	t_vec			vec[3];
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*walls[4];
}	t_all;

typedef struct s_texture
{
	int		pix[2];
	int		height;
	int		end;
	int		width;
	double	wall_x;
	double	step;
	int		start;
	double	pos;
}	t_texture;
typedef struct s_nearest_wall
{
	int    axis_hit;
	double w_hit;
	double w_distance;
}	t_nearest_wall;

typedef struct s_values //! Shndrydhi fare
{
	double distance[2]; // Distance to the wall
	double	dir[2]; // Direction vector
	double camx; // Camera X position
	double steps[2]; // Steps lmao
	int pos[2]; // pretty self-explanatory
	int side_hit[2];
	int   charge[2]; // Charge for horizontal and vertical walls
	int hit; // Hit status for horizontal and vertical walls
}	t_values;



int validate_file_extension(char *map_name);
int validate_map(char **map);
int check_map_file(char *map_name);
char **parse_map(char *map_name);

int count_lines(int fd);

void free_map(char **map);

void render_background(mlx_t *mlx);

void error_msg(char *msg);
char *gnl(int fd);

void handle_key(mlx_key_data_t keydata, void *param);

//Raycaxting
void raycasting(t_all *all);
void	uploading_textures(mlx_texture_t *walls[4]);
int32_t	ft_pixel(int32_t	r, int32_t g, int32_t b, int32_t a);
void	pos(t_vec *vec, char **map);
void	background(mlx_image_t *img);
void	loop(void *param);
#endif