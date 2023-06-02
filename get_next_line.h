/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:27:49 by festeve-          #+#    #+#             */
/*   Updated: 2023/06/02 11:19:32 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_substr(const char *str_src,
			unsigned int start_index, size_t substr_len);
char	*ft_strchr(const char *str, int chr);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *str1, const char *str2);
char	*get_next_line(int fd);

#endif
