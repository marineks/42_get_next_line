/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:24:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/07/05 17:00:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Lib non autorisées, utilisées pour tester
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t ft_strlcpy(char *dst, char *src, size_t dstsize);
int get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);

#endif