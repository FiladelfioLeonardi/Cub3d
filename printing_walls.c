/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:12:12 by amecani           #+#    #+#             */
/*   Updated: 2025/06/27 16:26:34 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//*! SHNDRYDHE FURISHEM
int32_t	ft_pixel(int32_t	r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	printing_walss(t_nearest_wall *wall, short x, t_all *all, t_values *val)
{
	t_texture		t;
	int32_t			pixel;
	int				i = wall->w_hit;
	mlx_texture_t	*txt = all->walls[i];


	//1
	t.height = (all->img->height) / wall->w_distance;
	t.start = (all->img->height / 2) - (t.height / 2);
	t.end = (all->img->height / 2) + (t.height / 2);
	if (t.start < 0)
		t.start = 0;
	if (t.end >= (int)(all->img->height))
		t.end = all->img->height - 1;
	if (wall->axis_hit == 0)//
		t.wall_x = all->vec[0].y + (wall->w_distance * val->dir[1]);
	else
		t.wall_x = all->vec[0].x + (wall->w_distance * val->dir[0]);
	//2
	t.wall_x -= floor(t.wall_x);
	t.pix[0] = (int)(t.wall_x * (double)txt->width);
	if ((wall->axis_hit == 0 && val->dir[0] > 0)
		|| (wall->axis_hit == 1 && val->dir[1] < 0))
		t.pix[0] = txt->width - t.pix[0] - 1;
	//3
	t.step = (double)(txt->height) / t.height;
	t.pos = (t.start - (all->img->height / 2) + (t.height / 2)) * t.step;
	while (t.start < t.end)
	{
		t.pix[1] = t.pos;
		pixel = (t.pix[1] * txt->width + t.pix[0]) * 4;
		mlx_put_pixel(all->img, x, t.start, ft_pixel(txt->pixels[pixel + 0],
				txt->pixels[pixel + 1], txt->pixels[pixel + 2], 255));
		t.pos += t.step;
		t.start++;
	}
}