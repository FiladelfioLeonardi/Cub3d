/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:44:33 by amecani           #+#    #+#             */
/*   Updated: 2025/06/29 20:54:57 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	background(mlx_image_t *img)
{
	printf("Background\n");
	unsigned short	x = 0;
	unsigned short	y;
	
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			mlx_put_pixel(img, x, ++y,
				ft_pixel(75, 83,42, 0x000000FF));
		}
		while (y < HEIGHT - 1)
		{
			mlx_put_pixel(img, x, ++y,
				ft_pixel(255, 111, 118, 0x000000FF));
		}
		x++;
		}
}
			
			void	set_texture(t_texture *t, t_nearest_wall *wall, mlx_texture_t *text, t_values *val)
			{
				t->wall_x -= floor(t->wall_x);
				t->pix[0] = (int)(t->wall_x * (double)text->width);
				if ((wall->axis_hit == 0 && val->dir[0] > 0)
				|| (wall->axis_hit == 1 && val->dir[1] < 0))
				t->pix[0] = text->width - t->pix[0] - 1;
			}
			
			void	texture(t_texture *t, t_nearest_wall *w, t_all *all, t_values *val)
			{
				t->height = (all->img->height) / w->w_distance;
				t->start = (all->img->height / 2) - (t->height / 2);
				t->end = (all->img->height / 2) + (t->height / 2);
				if (t->start < 0)
				t->start = 0;
				if (t->end >= (int)(all->img->height))
				t->end = all->img->height - 1;
				if (w->axis_hit == 0)//
				t->wall_x = all->vec[0].y + (w->w_distance * val->dir[1]);
				else
				t->wall_x = all->vec[0].x + (w->w_distance * val->dir[0]);
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
				
				void	LEFT(t_values	*val, t_vec	*vec)
				{
					val->charge[0] = -1;
	val->steps[0] = (vec[0].x - (double)val->pos[0]) * val->distance[0];
	val->side_hit[0] = 3;
}

void	RIGHT(t_values	*val, t_vec	*vec)
{
	val->charge[0] = 1;
	val->steps[0] = ((double)val->pos[0] + 1.0 - vec[0].x) * val->distance[0];
	val->side_hit[0] = 2;
}

void	UP(t_values	*val, t_vec	*vec)
{
	val->charge[1] = -1;
	val->steps[1] = (vec[0].y - (double)val->pos[1]) * val->distance[1];
	val->side_hit[1] = 0;
}

void	UNDER(t_values	*val, t_vec	*vec)
{
	val->charge[1] = 1;
	val->steps[1] = ((double)val->pos[1] + 1.0 - vec[0].y) * val->distance[1];
	val->side_hit[1] = 1;
}

void raycasting(t_all *all)
{
	printf("Raycasting\n");
	uploading_textures(all->walls);
	char *mappa[] = {
		"11111",
		"10S01",
		"10001",
		"10001",
		"11111"
	};
	pos(all->vec, mappa);
	
	//////////////////////////////////////*
	int		x;
	t_values		val;
	t_nearest_wall		wall;
	
	x = -1;
	while (++x < (int)all->img->width)
	{
		val.camx = (float)2 * x / WIDTH - (float)1;
		val.dir[0] = all->vec[1].x + all->vec[2].x * val.camx;
		val.dir[1] = all->vec[1].y + all->vec[2].y * val.camx;
		val.distance[0] = fabs((float)1 / val.dir[0]);
		val.distance[1] = fabs((float)1 / val.dir[1]);
		val.pos[0] = all->vec[0].x;
		val.pos[1] = all->vec[0].y;
		if (val.dir[0] < 0)
		LEFT(&val, all->vec);
		else
		RIGHT(&val, all->vec);
		if (val.dir[1] < 0)
		UP(&val, all->vec);
		else
		UNDER(&val, all->vec);
		
		int	hx;
		
		hx = 0;
		while (!(mappa[val.pos[1]][val.pos[0]] == '1'))
		{
			if (val.steps[0] < val.steps[1])
			{
				val.steps[0] += val.distance[0];
				val.pos[0] += val.charge[0];
				hx = 0;
			}
			else
			{
				val.steps[1] += val.distance[1];
				val.pos[1] += val.charge[1];
				hx = 1;
			}
		}
		wall.axis_hit = hx;
		
		if (!wall.axis_hit)
		{
			wall.w_distance = val.steps[0] - val.distance[0];
			wall.w_hit = val.side_hit[0];
		}
		else
		{
			wall.w_distance = val.steps[1] - val.distance[1];
			wall.w_hit = val.side_hit[1];
		}
		
		printing_walss(&wall, x, all, &val);
	}
}
