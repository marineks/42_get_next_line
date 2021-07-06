/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:31 by msanjuan          #+#    #+#             */
/*   Updated: 2021/07/06 16:49:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_the_line(char *stock)
{
	char *line;
	int i;
	int len;

	i = 0;
	line = NULL;
	while (stock[i] != '\n' && stock[i] != '\0') // BOOLEENS
		i++; 
	len = i; 					
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && i < len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void ft_get_the_spare(char *buffer)
{
	int i;
	int j;

	i = 0;
	while (buffer[i] != '\n')
		i++;    
	i = i + 1;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

int get_next_line(int fd, char **line)
{
	static char buffer[BUFFER_SIZE + 1];
	char *stock = NULL; 
	int ret;
	
	if ((read(fd, buffer, 0) == -1) || !line || BUFFER_SIZE <= 0)
		return (-1);					
	ret = 1;
	stock = ft_strjoin(stock, buffer);
	while (ft_strchr(stock, '\n') == NULL && ret > 0)
	{ 
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(stock);
			return (-1);
		}
		buffer[ret] = '\0';
		stock = ft_strjoin(stock, buffer);	
	}
	if (ret == 0)
		{
			*line = ft_get_the_line(stock);
			free(stock);                     
			return (0);
		}
	*line = ft_get_the_line(stock);
	free(stock);
	ft_get_the_spare(buffer);
	return (1);
}
	