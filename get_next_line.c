/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:08:47 by festeve-          #+#    #+#             */
/*   Updated: 2023/05/23 12:31:00 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Funcion para leer datos de un descriptor de archivo y agregarlos a un búfer de respaldo
static char	*read_and_append_to_backup(int fd, char *buffer, char *backup)
{
	int		read_status;
	char	*prev_backup;

	read_status = 1;
	while (read_status != '\0')
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			return (0);
		else if (read_status == 0)
			break;
		buffer[read_status] = '\0';
		if (!backup)
			backup = ft_strdup("");
		prev_backup = backup;
		backup = ft_strjoin(prev_backup, buffer);
		free(prev_backup);
		prev_backup = NULL;
		if (ft_strchr(buffer, '\n'))
				break;
	}
	return (backup);
}

static char	*extract_current_line(char *line)
{
	size_t	count;
	char	*next_line;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
			count++;
	if (line[count] == '\0' || line[1] == '\0')
			return (0);
	next_line = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*next_line == '\0')
	{
		free(next_line);
		next_line = NULL;
	}
	line[count + 1] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*buffer_backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_and_append_to_backup(fd, buffer, buffer_backup);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	buffer_backup = get_line(line);
	return (line);
}
