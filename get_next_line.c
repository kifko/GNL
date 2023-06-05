/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:08:47 by festeve-          #+#    #+#             */
/*   Updated: 2023/06/02 13:21:41 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_rest(char *buf)
{
	char	*rest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			i++;
			break ;
		}
	}
	rest = malloc(((ft_strlen(buf) - i) + 1) * sizeof(char));
	if (!rest)
			return (free(buf), NULL);
	while (buf[i])
			rest[j++] = buf[i++];
	rest[j] = '\0';
	return (free(buf), rest);
}

char	*read_line(int fd, char *buf)
{
	char	*tmp;
	int		read_return;

	read_return = 1;
	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (search_newline(buf) && read_return)
	{
		read_return = read(fd, tmp, BUFFER_SIZE);
		if ((read_return == 0 && !buf) || read_return < 0)
			return(free(tmp), free(buf), NULL);
		tmp[read_return] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	free(tmp);
	if (buf[0] == '\0')
			return (free(buf), NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	char			*line;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
	buf = read_line(fd, buf);
	if (!buf)
			return (NULL);
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
		{
			i++;
			break ;
		}
	}
	line = ft_substr(buf, 0, i);
	buf = save_rest(buf);
	return (line);
}

// mouadd55 Get_next_line-42Cursus

/*
#include "get_next_line.h"

// Funcion para leer datos de un descriptor 
// de archivo y agregarlos a un búfer de respaldo
static char	*read_and_append_to_backup(int fd, char *buffer, char *backup)
{
	int		read_status;
	char	*prev_backup;

	read_status = 1;
	while (read_status != 0)
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
		{
			free(backup);
			return (NULL);
		}
		else if (read_status == 0)
			break ;
		buffer[read_status] = '\0';
		if (!backup)
			backup = ft_strdup("");
		else
		{
			prev_backup = backup;
			backup = ft_strjoin(prev_backup, buffer);
			free(prev_backup);
			prev_backup = NULL;
			if (!backup)
				return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract_current_line(char *line)
{
	size_t	count;
	char	*next_line;

	count = 0;
	next_line = NULL;
	while (line[count] != '\n' && line[count] != '\0')
			count++;
	if (line[count] == '\0' || line[count + 1] == '\0')
		return (NULL);
	next_line = ft_substr(line, count + 1, ft_strlen(line) - count - 1);
	if (next_line)
		next_line[count] = '\0';
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
	buffer_backup = extract_current_line(line);
	return (line);
}
*/