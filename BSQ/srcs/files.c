/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonnevi <ibonnevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:40:04 by lroussel          #+#    #+#             */
/*   Updated: 2024/08/07 20:22:21 by ibonnevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

char	*create_content(int fd, char *buffer, int *i)
{
	size_t	total_bytes_read;
	ssize_t	bytes_read;

	total_bytes_read = 0;
	bytes_read = read(fd, buffer, MAX_FILE_SIZE);
	while (bytes_read > 0)
	{
		total_bytes_read += bytes_read;
		if (total_bytes_read >= MAX_FILE_SIZE)
		{
			free(buffer);
			return (NULL);
		}
		bytes_read = read(fd, buffer + total_bytes_read,
				MAX_FILE_SIZE - total_bytes_read);
	}
	*i = total_bytes_read;
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_calloc(void)
{
	long	i;
	char	*buffer;

	i = -1;
	buffer = malloc(sizeof(char) * MAX_FILE_SIZE);
	if (buffer == NULL)
		return (NULL);
	while (++i < MAX_FILE_SIZE)
		buffer[i] = '\0';
	return (buffer);
}

char	*file_get_contents(char *path)
{
	int		fd;
	char	*buffer;
	char	*new_buffer;
	int		i;

	fd = 0;
	if (!(!path))
		fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = ft_calloc();
	i = 0;
	buffer = create_content(fd, buffer, &i);
	if (i <= 4 || buffer[i - 1] != '\n')
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	new_buffer = ft_strndup(buffer, 0, i);
	free(buffer);
	close(fd);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}
