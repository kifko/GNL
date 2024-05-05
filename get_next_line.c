/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:08:47 by festeve-          #+#    #+#             */
/*   Updated: 2023/12/11 16:20:06 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *buf)
{
	int		i;
	int		j;
	char	*rest;

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
	int				i;
	static char		*buf;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_and_process(fd, buf);
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
	buf = get_rest(buf);
	return (line);
}

/*
int main(int argc, char **argv)
{
    int fd;
	(void)	argc;
	char	*line;

    // Abre el archivo de texto para lectura
    fd = open(argv[1], O_RDONLY);

    // Lee líneas del archivo hasta el final
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line); // Libera la memoria asignada por get_next_line
    }
    // Cierra el archivo
    close(fd);

    return 0;
}
*/
