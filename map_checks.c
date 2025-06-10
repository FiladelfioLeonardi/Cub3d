/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:28:44 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/10 16:27:20 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_map_file(char *map_name)
{
	int i;
	int fd;
	

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0 || map_name[0] == '.')
		return (error_msg("Failed to open map file.\n"), 1);
	while (map_name[i])
	{
		if (map_name[i] == '.')
		{
			if (ft_strncmp(&map_name[i], ".cub\0", 5) != 0)
				return (error_msg("Invalid file extension. Use .cub\n"), 1);
		}
		i++;
	}

	return (0);
}