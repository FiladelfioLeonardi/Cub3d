/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:26:17 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/12 13:43:19 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_map(char **map)
{
	int i = 0;

	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// Function to count the number of lines in the map file
int count_lines(int fd)
{
	int count = 0;
	char *line;
	
	line = gnl(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = gnl(fd);
	}
	return (count);
}
