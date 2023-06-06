/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:20:47 by festeve-          #+#    #+#             */
/*   Updated: 2023/06/06 17:41:44 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_rest(char *buf)
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

char	*read_and_process(int fd, char *buf)
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
			return (free(tmp), free(buf), NULL);
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
	static char		*buf[OPEN_MAX];
	char			*line;
	int				i;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = read_and_process(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	i = -1;
	while (buf[fd][++i])
	{
		if (buf[fd][i] == '\n')
		{
			i++;
			break ;
		}
	}
	line = ft_substr(buf[fd], 0, i);
	buf[fd] = get_rest(buf[fd]);
	return (line);
}
