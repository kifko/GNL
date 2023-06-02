/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: festeve- <festeve-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:32:17 by festeve-          #+#    #+#             */
/*   Updated: 2023/06/02 11:24:42 by festeve-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_substr(const char *str_src,
			unsigned int start_index, size_t substr_len)
{
	size_t	src_index;
	size_t	dst_index;
	char	*str_substr;

	if (!str_src)
		return (NULL);
	str_substr = (char *)malloc(sizeof(*str_src) * (substr_len + 1));
	if (str_substr == 0 || !str_substr)
		return (NULL);
	src_index = 0;
	dst_index = 0;
	while (str_src[src_index])
	{
		if (src_index >= start_index && dst_index < substr_len)
		{
			str_substr[dst_index] = str_src[src_index];
			dst_index++;
		}
		src_index++;
	}
	str_substr[dst_index] = 0;
	return (str_substr);
}

char	*ft_strchr(const char *str, int chr)
{
	char	*res;

	while (*str != '\0')
	{
		if (*str == (char)chr)
		{
			res = (char *)str;
			return (&res[0]);
		}
		str++;
	}
	if (*str == (char)chr)
	{
		return (&(*(char *)str));
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		src_len;
	int		index;
	char	*strdup;

	src_len = 0;
	index = ft_strlen(src);
	strdup = (char *)malloc(sizeof(*strdup) * (index + 1));
	while (src_len < index)
	{
		strdup[src_len] = src[src_len];
		src_len++;
	}
	strdup[src_len] = '\0';
	return (strdup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		index1;
	int		index2;
	char	*res;

	index1 = 0;
	index2 = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[index1] != '\0')
	{
		res[index1] = s1[index1];
		index1++;
	}
	while (s2[index2] != '\0')
	{
		res[index1 + index2] = s2[index2];
		index2++;
	}
	res[index1 + index2] = '\0';
	return (res);
}
