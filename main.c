/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:20:59 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/09 15:28:39 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		printf("Hello\n");
	}
	else
	{
		write(2, "Error\nUsage: ./cub3d <map.cub>\n", 32);
		return (1);
	}
}