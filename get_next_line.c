/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:31 by msanjuan          #+#    #+#             */
/*   Updated: 2021/07/02 17:09:06 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_the_line(char *stock) // If "Salut\nc'est moi", expects malloc size of "Salut\o"
{
	char *line;
	int i;

	i = 0;
	if (stock[i] == '\n' && stock[i + 1])
	{
		line = ft_strdup("\n");
		free(stock);
		return (line);
	}
	while (stock[i] != '\n')
		i++;    					//nb: compte 1 de plus donc pas besoin de rajouter 1 au malloc
	line = (char *)malloc(sizeof(char) * (i + 1)); // je sais pas pourquoi mais qd je rajoute + 1 ca marche?
	if (!line)
		return (NULL);
	ft_strlcpy(line, stock, (i + 1));
	free(stock); // je sais pas pourquoi mais qd je rajoute + 1 ca marche?
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
	// free(stock);
	return (spare);
}

int get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static char *stock = NULL; 
	// char *tmp;
	int ret;
	
	ret = 0;
	// tmp = NULL;
	if ((ret = read(fd, buffer, 0) == -1) || !fd || BUFFER_SIZE <= 0)
		return (-1);					
	if (stock == NULL)
	{
		ret = read(fd, buffer, BUFFER_SIZE); 
		buffer[ret] = '\0'; 
		if (!ret)
			return (-1); 
		// tmp = ft_strdup(buffer);
		stock = ft_strdup(buffer);
		// free(tmp);
	}											
	while (ft_strchr(stock, '\n') == NULL && stock)
	{ 
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';  	
		if (ret == 0)
		{
			*line = ft_strdup(stock);
			// free(stock);                     
			return (0);
		}
		if (!ret)
			return (-1);	
		// tmp = strdup(buffer);
		stock = ft_strjoin(stock, buffer);
		// free(tmp);
	}
	*line = ft_get_the_line(stock);
	stock = ft_get_the_spare(stock);                             
	return (1);
}
	