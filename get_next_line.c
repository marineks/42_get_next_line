/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:31 by msanjuan          #+#    #+#             */
/*   Updated: 2021/07/05 17:49:15 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char *ft_get_the_line(char *stock) // If "Salut\nc'est moi", expects malloc size of "Salut\o"
{
	char *line;
	int i;

	i = 0;
	if (stock[i] == '\n' && stock[i + 1] == '\n')
	{
		line = ft_strdup("\n");
		free(stock);
		return (line);
	}
	while (stock[i] != '\n')
		i++;    					
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stock, (i + 1));
	free(stock);
	return (line);
}

char *ft_get_the_spare(char *stock) // If "Salut\nC'est moi", expects malloc size of "C'est moi\o"
{
	char *spare;
	int i;
	int j;
	int start;

	i = 0;
	while (stock[i] != '\n') 						// Trouver le \n
		i++;    
	start = i + 1; 									// on passe le \n avec +1
	j = 0;
	while (stock[i + 1]) 							// on passe le \n avec +1
	{
		i++;
		j++;
	}
	spare = (char *)malloc(sizeof(char) * (j + 1));
	if (!spare)
		return (NULL);
	// printf("stock : %s\n",  stock); // | i: %d\n| start: %d\n | j: %d\n", , i, start, j
	spare = ft_substr(stock, start, (j + 1));
	return (spare);
}

int get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static char *stock = NULL; 
	char *tmp;
	int ret;
	
	ret = 0;
	tmp = NULL;
	if ((read(fd, buffer, 0) == -1) || !line || BUFFER_SIZE <= 0)
		return (-1);					
	if (stock == NULL)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(stock);
			return (-1);
		}	 
		buffer[ret] = '\0'; 
		stock = ft_strdup(buffer);
	}
	if (stock)
	{			
		while (ft_strchr(stock, '\n') == NULL && stock)
		{ 
			ret = read(fd, buffer, BUFFER_SIZE);
			if (ret < 0)
			{
				free(stock);
				return (-1);
			}
			buffer[ret] = '\0';
			if (ret == 0)
			{
				*line = ft_strdup(stock);
				free(stock);                     
				return (0);
			}
			// printf("stock : %s\n", stock);
			stock = ft_strjoin(stock, buffer);
		}
		*line = ft_get_the_line(stock);
		tmp = ft_strdup(stock);
		stock = ft_get_the_spare(tmp);      
		free(tmp);
	}                
	return (1);
}
	