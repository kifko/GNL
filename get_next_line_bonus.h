/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:01:34 by festeve-          #+#    #+#             */
/*   Updated: 2023/06/06 18:09:02 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, 
			unsigned int start, size_t substrlen);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		search_newline(char *s);

#endif
