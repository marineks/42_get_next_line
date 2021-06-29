/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:16:07 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/29 20:13:18 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res)
	{
		if (*res == (char)c)
			return (res);
		res++;
	}
	if (*res != (char)c)
		return (NULL);
	return (res);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize == 0)
	return (ft_strlen(src));
	if (src == NULL)
	{
		return (0);
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}	
	dst[i] = '\0';

	return (ft_strlen(src));
}

char *ft_strdup(const char *s1)
{
	char *copy;
	
	copy = (char *)malloc(ft_strlen(s1) + 1 * sizeof(char));
	if(!copy)
		return NULL;
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);

	return (copy);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *res;
	size_t i;
	size_t j;

	i = 0;
	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;
	size_t	size;
	size_t	index;

	if (s == '\0')
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	new_string = (char *)malloc((size + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = (size_t)start;
	index = 0;
	while (index < size)
		new_string[index++] = s[i++];
	new_string[index] = '\0';
	return (new_string);
}
