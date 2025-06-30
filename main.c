/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:22:23 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/30 17:00:34 by fefo             ###   ########.fr       */
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
	t_all all;
	
	//You can test the code using the test.cub right now and it will work, ALTHOUGH
	//     it should work instead with the child.cub map

	//// FEFO parse me the following:

	//// 1.Give me the location of the textures, which you can get from test.cub  (do know that only for these (char *) you have to mallocate)
	// Example :   
	// all.map_data->texture_location[0] = "textures/texture1.png";
	// all.map_data->texture_location[1] = "textures/texture2.png";
	// all.map_data->texture_location[2] = "textures/texture3.png";
	// all.map_data->texture_location[3] = "textures/texture4.png";
	
	//// 2.Give me the numbers of F (floor colour) and C (ceiling colour) from test.cub
	// Example:
	//            FLOOR Colour :D
	// all.map_data.floor_color[0] = 75;
	// all.map_data.floor_color[1] = 83;
	// all.map_data.floor_color[2] = 42;
	
	//            CEILING Colour :D
	// all.map_data.ceiling_color[0] = 255;
	// all.map_data.ceiling_color[1] = 111;
	// all.map_data.ceiling_color[2] = 118;

	if (check_arguments(argc, argv) == 1)
		return (1);
	if (parse_map(argv[1]) == NULL)
	return (error_msg("Failed to parse map file.\n"), 1);






	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (mlx == NULL)
		return (error_msg("Failed to initialize MLX42.\n"), 1);
	all.mlx = mlx;
	all.img = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	all.mappa = parse_map(argv[1]);


	mlx_image_to_window(all.mlx, all.img, 0, 0);
	uploading_textures(all.walls);
	pos(all.vec, all.mappa);
	mlx_loop_hook(mlx, loop, &all);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	freeing(&all);
	return (0);
}
