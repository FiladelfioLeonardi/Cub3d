/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:44:35 by amecani           #+#    #+#             */
/*   Updated: 2025/06/28 17:40:42 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	uploading_textures(mlx_texture_t *walls[4])
{
	walls[0] = mlx_load_png("textures/texture1.png");
	walls[1] = mlx_load_png("textures/texture2.png");
	walls[2] = mlx_load_png("textures/texture3.png");
	walls[3] = mlx_load_png("textures/texture4.png");
}

void	pos(t_vec *vec, char **map)
{
	int		x = 0;
	int		y = 0;

	while (map[y][x] != 'S' && map[y][x] != 'E'
		&& map[y][x] != 'W' && map[y][x] != 'N')
	{
		if (map[y][++x] == '\0')
		{
			x = 0;
			y++;
		}
	}

	vec[0].x = (double)x + 0.5;
	vec[0].y = (double)y + 0.5;

	if (map[y][x] == 'N')
	{
		vec[1] = (t_vec){0.0, -1.0};
		vec[2] = (t_vec){FOV, 0.0};
	}
	else if (map[y][x] == 'E')
	{
		vec[1] = (t_vec){-1.0, 0.0};
		vec[2] = (t_vec){0.0, FOV * -1.0};
	}
	else if (map[y][x] == 'W')
	{
		vec[1] = (t_vec){1.0, 0.0};
		vec[2] = (t_vec){0.0, FOV};
	}
	else
	{
		vec[1] = (t_vec){0.0, 1.0};
		vec[2] = (t_vec){FOV * -1.0, 0.0};
	}
}
