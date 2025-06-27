/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:22:23 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/27 16:18:32 by amecani          ###   ########.fr       */
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
	if (parse_map(argv[1]) == NULL)
		return (error_msg("Failed to parse map file.\n"), 1);
	mlx = mlx_init(800, 600, "Cub3D", true);
	if (mlx == NULL)
		return (error_msg("Failed to initialize MLX42.\n"), 1);

	// Give it to me Fefo, fill me with your biological information, 1587.5 TB to be exact
	t_all *all = malloc(sizeof(t_all));
	char *map[] = {
		"11111",
		"10001",
		"10101",
		"10S01",
		"11111"
	};
	all->map = map;
	//
	render_background(mlx);
	raycasting(all);
	mlx_key_hook(mlx, handle_key, mlx);
	mlx_loop(mlx);

	return (0);
}
