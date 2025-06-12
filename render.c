/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:31:54 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/12 15:38:26 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(mlx_t *mlx)
{
	mlx_image_t *background;
	int y;
	int x;

	y = 0;
	x = 0;
	background = mlx_new_image(mlx, mlx->width, mlx->height);
	if (background == NULL)
	{
		error_msg("Failed to create background image.\n");
		return ;
	}
	while (y < mlx->height / 2)
	{
		x = 0;
		while (x < mlx->width)
		{
			mlx_put_pixel(background, x, y, 0x0000FF); // Fill with black color
			x++;
		}
		y++;
	}
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			mlx_put_pixel(background, x, y, 0xff00ff); // Fill with green color
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(mlx, background, 0, 0) < 0)
	{
		error_msg("Failed to put image to window.\n");
		mlx_delete_image(mlx, background);
		return ;
	}
}