/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysuliman <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-17 12:01:28 by ysuliman          #+#    #+#             */
/*   Updated: 2024-04-17 12:01:28 by ysuliman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	safe_free(int *byte, char **buffer)
{
	if (*byte == 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (*byte);
}

int	line_process(int *i, char **line, int *remaining, int fd)
{
	int			n;
	int			byte;
	static char	*buffer[MAX_FILES_OPENED];

	if (!buffer[fd])
		buffer[fd] = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	n = 0;
	if (*remaining == 0)
		byte = read(fd, buffer[fd], BUFFER_SIZE);
	else
		byte = *remaining;
	while (n < byte)
	{
		if (buffer[fd][n] == '\n')
		{
			(*line)[(*i)++] = '\n';
			*remaining = byte - n - 1;
			ft_memmove(buffer[fd], buffer[fd] + n + 1, *remaining);
			buffer[fd][*remaining] = '\0';
			break ;
		}
		(*line)[(*i)++] = buffer[fd][n++];
		*remaining = 0;
	}
	return (safe_free(&byte, &buffer[fd]));
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line[MAX_FILES_OPENED];
	static int	remaining[MAX_FILES_OPENED];
	int			byte;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = (char *)malloc(10000000);
	if (!line[fd])
		return (NULL);
	i = 0;
	byte = 1;
	while (byte > 0 && (i == 0 || line[fd][i - 1] != '\n'))
		byte = line_process(&i, &(line[fd]), &(remaining[fd]), fd);
	if (byte <= BUFFER_SIZE && i != 0)
	{
		line[fd][i] = '\0';
		result = ft_strdup(line[fd]);
		free(line[fd]);
		return (result);
	}
	if (line[fd])
		free(line[fd]);
	return (NULL);
}
