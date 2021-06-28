/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:24:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/28 11:35:28 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
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
char *ft_strjoin(char const *s1, char const *s2);

#endif