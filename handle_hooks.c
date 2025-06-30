/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:02:02 by amecani           #+#    #+#             */
/*   Updated: 2025/06/30 16:00:56 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	walking(t_all *all, t_vec *vec, char **mappa)
{
	double		w_x;
	double		w_y;
	
	w_x = vec[1].x * SPEED;
	w_y = vec[1].y * SPEED;
	if (mlx_is_key_down(all->mlx, MLX_KEY_D))
	if (mappa[(int)(vec[0].y + w_x)][(int)(vec[0].x - w_y)] != '1')
	vec[0] = (t_vec){vec[0].x - w_y, vec[0].y + w_x};
	if (mlx_is_key_down(all->mlx, MLX_KEY_A))
	if (mappa[(int)(vec[0].y - w_x)][(int)(vec[0].x + w_y)] != '1')
	vec[0] = (t_vec){vec[0].x + w_y, vec[0].y - w_x};
	if (mlx_is_key_down(all->mlx, MLX_KEY_W))
	if (mappa[(int)(vec[0].y + w_y)][(int)(vec[0].x + w_x)] != '1')
	vec[0] = (t_vec){vec[0].x + w_x, vec[0].y + w_y};
	if (mlx_is_key_down(all->mlx, MLX_KEY_S))
	if (mappa[(int)(vec[0].y - w_y)][(int)(vec[0].x - w_x)] != '1')
	vec[0] = (t_vec){vec[0].x - w_x, vec[0].y - w_y};
}

void	rotation(t_vec *vec, short sign)
{
	double	ca;
	double	sa;
	double	tmp;

	ca = cos(sign * ROTATION_S);
	sa = sin(sign * ROTATION_S);
	tmp = vec[1].x;
	vec[1].x = (vec[1].x * ca) - (vec[1].y * sa);
	vec[1].y = (tmp * sa) + (vec[1].y * ca);
	tmp = vec[2].x;
	vec[2].x = (vec[2].x * ca) - (vec[2].y * sa);
	vec[2].y = (tmp * sa) + (vec[2].y * ca);
}

void loop(void *param)
{
	t_all	*all;
	
	all = (t_all *)param;
	background(all->img, all->map_data.floor_color, all->map_data.ceiling_color);
	raycasting(all);
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
	rotation(all->vec, 1);
	if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT))
	rotation(all->vec, -1);
	walking(all, all->vec, all->mappa);
	}