/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:27:49 by festeve-          #+#    #+#             */
/*   Updated: 2023/06/02 13:18:46 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *str);
char	*ft_substr(char *str_src,
			unsigned int start, size_t substrlen);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		search_newline(char *s);

#endif
