/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:31 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/30 18:34:01 by msanjuan         ###   ########.fr       */
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
		return (line);
	}
	while (stock[i] != '\n')
		i++;    					//nb: compte 1 de plus donc pas besoin de rajouter 1 au malloc
	line = (char *)malloc(sizeof(char) * (i + 1)); // je sais pas pourquoi mais qd je rajoute + 1 ca marche?
	if (!line)
		return (NULL);
	ft_strlcpy(line, stock, (i + 1)); // je sais pas pourquoi mais qd je rajoute + 1 ca marche?
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
	spare = ft_substr(stock, start, (j + 1));
	return (spare);
}

int get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static char *stock = NULL; 
	char *tmp;
	ssize_t ret;
	
	printf("\n");
	printf("\n");
	printf("DEBUT FONCTION \n");
	printf("\n");
	// printf("Stock 1 : |%s|\n", stock);
	ret = 0;
	if (!fd || !line || BUFFER_SIZE == -1)
		return (-1);					
	buffer[ret] = '\0';
	// printf("1 Statut buffer : |%s|\n", buffer);        
	if (stock == NULL)
	{
		ret = read(fd, buffer, BUFFER_SIZE);   
		if (!ret)
			return (-1);  
		tmp = strdup(buffer); 
		stock = ft_strdup(tmp);
		free(tmp);
		// printf("Stock 1 : |%s|\n", stock);
	}											
	// if (ret > 0)
	// {	
		while (ft_strchr(stock, '\n') == NULL)
		{ 
			ret = read(fd, buffer, BUFFER_SIZE); // i'\n'e
			// printf("2 Statut buffer : |%s|\n", buffer);
			if (!ret)
				return (-1);	
			tmp = strdup(buffer);                              
			// printf("Tmp 1 : |%s|\n", tmp);
					
			stock = ft_strjoin(stock, tmp);		 // ceci \n e
			// printf("Ca a ete join : |%s|\n", stock);
			free(tmp);
	
		}
	*line = ft_get_the_line(stock);
	printf("Line : |%s|\n", *line);
	stock = ft_get_the_spare(stock);
	printf("Stock Spare : |%s|\n", stock);
	printf("\n");                             
		return (1); 
	// }                                                                                               
   return (0);                                                                  // END OF FILE REACHED
}

int main()
{
	int fd;
	char *test;
	test= NULL;

	fd = open("test.txt", O_RDONLY);
	
	printf("%d\n", get_next_line(fd, &test));
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	get_next_line(fd, &test);
	printf("|%s|\n", test);
	// get_next_line(fd, &test);
	// printf("|%s|\n", test);
	free(test);
	close(fd);
	return (0);
}


//RELIQUAT ANCIENNE LOOP A LA MANO
/* 
// printf("\nNouveau buffer : |%s|\n", buffer);
				
				// tmp = strdup(buffer); 
				// printf("Nv tmp : |%s|\n", tmp);
				
				// stock = ft_strjoin(stock, tmp);

*/
	
