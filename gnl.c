/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:03:30 by fileonar          #+#    #+#             */
/*   Updated: 2025/06/10 18:17:34 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_add_to_return_str(char buffer[BUFFER_SIZE + 1],
	char **return_str)
{
	const char		*tmp = *return_str;
	const size_t	size = ft_strlen(*return_str) + ft_strlen(buffer) + 1;

	*return_str = (char *) ft_calloc(size, sizeof(char));
	if (*return_str == NULL)
		return (free((void *)tmp), EXIT_FAILURE);
	if (tmp != NULL)
		ft_strlcpy(*return_str, tmp, size);
	*return_str = ft_strcat(*return_str, buffer);
	free((void *)tmp);
	return (EXIT_SUCCESS);
}

static int	ft_handle_new_line(char buffer[BUFFER_SIZE + 1], char **return_str)
{
	int		i;
	char	*new_line_pos;
	char	after_new_line;

	new_line_pos = ft_strchr(buffer, '\n');
	after_new_line = *++new_line_pos;
	*new_line_pos = '\0';
	if (ft_add_to_return_str(buffer, return_str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	*new_line_pos = after_new_line;
	i = 0;
	while (new_line_pos[i] != '\0')
	{
		buffer[i] = new_line_pos[i];
		i++;
	}
	ft_memset(&buffer[i], '\0', BUFFER_SIZE + 1 - i);
	return (EXIT_SUCCESS);
}

int	loop_til_new_line(char buffer[BUFFER_SIZE + 1], char **return_str,
	const int fd)
{
	ssize_t		bytes_read;

	while (ft_strchr(buffer, '\n') == NULL)
	{
		if (buffer[0] != '\0')
		{
			if (ft_add_to_return_str(buffer, return_str) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(*return_str), EXIT_FAILURE);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
	}
	return (EXIT_SUCCESS);
}

char	*gnl(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*return_str;

	if (read(fd, 0, 0) == -1)
		return (ft_memset(buffer, '\0', BUFFER_SIZE + 1), NULL);
	return_str = NULL;
	if (loop_til_new_line(buffer, &return_str, fd) == EXIT_FAILURE)
		return (NULL);
	if (ft_strchr(buffer, '\n'))
		ft_handle_new_line(buffer, &return_str);
	else
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
	return (return_str);
}