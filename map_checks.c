/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:28:44 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/13 16:47:00 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//still gotta add check if the map is closed by walls
//	
int validate_map(char **map)
{
	int i = 0;
	int j;
	int player_count = 0;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || 
				map[i][j] == 'W')
					player_count++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
			return (error_msg("Invalid character in map.\n"), 1);
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (error_msg("Map must have exactly one player starting position.\n"), 1);
	return (0);
}

// Function to parse the map into a 2D array
char **parse_map(char *map_name)
{
	int fd;
	int i;
	int line_count;
	char **map;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (error_msg("Failed to open map file.\n"), NULL);

	// Count the number of lines in the map
	line_count = count_lines(fd);
	close(fd);

	// Allocate memory for the map
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (error_msg("Memory allocation failed.\n"), NULL);

	// Read the map file again and store each line
	fd = open(map_name, O_RDONLY);
	while (i < line_count)
	{
		map[i] = gnl(fd);
		i++;
	}
	map[i] = NULL; // Null-terminate the array
	close(fd);

	return (map);
}

int check_map_file(char *map_name)
{
	char **map;

	// Validate the file extension
	if (validate_file_extension(map_name) != 0)
		return (1);

	// Parse the map
	map = parse_map(map_name);
	if (!map)
		return (1);

	// Validate the map
	if (validate_map(map) != 0)
	{
		free_map(map); // Free the allocated memory
		return (1);
	}
	// Free the map after validation (or store it for later use)
	free_map(map);
	return (0);
}

int validate_file_extension(char *map_name)
{
	int len;

	len = ft_strlen(map_name);
	if (len < 4 || ft_strncmp(&map_name[len - 4], ".cub", 4) != 0)
	{
		error_msg("Map file must have a .cub extension.\n");
		return (1);
	}
	return (0);
}