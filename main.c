/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:22:23 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/10 16:23:34 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error_msg(char *msg)
{
	write (2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
}

int check_arguments(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_map_file(argv[1]) == 1)
			return (1);
	}
	else
		return (error_msg("Usage: ./cub3d <map.cub>\n"), 1);
	return (0);
}

int main (int argc, char **argv)
{
	mlx_t *mlx;
	
	if (check_arguments(argc, argv) == 1)
		return (1);
	mlx = mlx_init(800, 600, "Cub3D", true);
	mlx_loop(mlx);
	

	return (0);
}

