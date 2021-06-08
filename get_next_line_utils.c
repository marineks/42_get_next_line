/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:16:07 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/08 13:36:32 by msanjuan         ###   ########.fr       */
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

void    *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    unsigned char *ptr_dest;
    unsigned char *ptr_source;
    unsigned char occurence;
    size_t i;

    ptr_dest = (unsigned char *)dst;
    ptr_source = (unsigned char *)src;
    occurence = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        ptr_dest[i] = ptr_source[i];
        if (ptr_dest[i] == occurence)
        {
            return (dst + 1 + i);
        }
        i++;
    }
return (NULL);
}