/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:44:33 by amecani           #+#    #+#             */
/*   Updated: 2025/06/27 16:31:34 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Put these in a direction movement folder3
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
// Bis here nibba







//---------------------------------------------
//---------------------------------------------
//---------------------------------------------

void	raycasting(t_all *all)
{
	int x = 0;
	t_vec			*vec = all->vec;
	t_values		val;
	t_nearest_wall	wall;
	
	while (x++ < WIDTH)
	{
		val.camx = (float)2 * x / WIDTH - (float)1;
		val.dir[0] = vec[1].x + vec[2].x * val.camx;
		val.dir[1] = vec[1].y + vec[2].y * val.camx;
		val.distance[0] = fabs((float)1 / val.dir[0]);
		val.distance[1] = fabs((float)1 / val.dir[1]);
		val.pos[0] = vec[0].x;
		val.pos[1] = vec[0].y;
		// Under Construction
		if (val.dir[0] < 0)
		LEFT(&val, vec);
		else
		RIGHT(&val, vec);
		if (val.dir[1] < 0)
		UP(&val, vec);
		else
		UNDER(&val, vec);

		//---------------------------------------------
		//---------------------------------------------
		//---------------------------------------------
		// *

		int	hx;
		char **map = all->map;
		
		hx = 0;
		while (!(map[val.pos[1]][val.pos[0]] == '1'))
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
