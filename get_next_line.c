/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:31 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/29 16:40:18 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_the_line(char *stock) // If "Salut\nc'est moi", expects malloc size of "Salut\o"
{
    char *line;
    int i;

    i = 0;
    while (stock[i] != '\n')
    {
        printf("i: %d\n", i);
        printf("Stock[i] : %c\n", stock[i]);
        printf("\n");
        i++;    //nb: compte 1 de plus donc pas besoin de rajouter 1 au malloc
    }
    printf("i: %d\n", i);
    line = (char *)malloc(sizeof(char) * i);
    if (!line)
        return (NULL);
    //line = ft_strncpy(line, stock, i);
    return (line);
}

char *ft_get_the_spare(char *stock) // If "Salut\nC'est moi", expects malloc size of "C'est moi\o"
{
    char *spare;
    int i;
    int j;

    i = 0;
    while (stock[i] != '\n') // Trouver le \n
    {
        printf("i: %d\n", i);
        printf("Stock[i] : %c\n", stock[i]);
        printf("\n");
        i++;    
    }
    printf("i: %d\n", i);
    j = 0;
    while (stock[i + 1]) // on passe le \n avec +1
    {
        i++;
        printf("i v2: %d\n", i);
        printf("Stock[i] : %c\n", stock[i]);
        j++;
        printf("j: %d\n", j);
        printf("\n");
    }

    spare = (char *)malloc(sizeof(char) * (j + 1));
    return (spare);

}



int get_next_line(int fd, char **line)
{
    char buffer[BUFFER_SIZE + 1];
    static char *stock;
    char *tmp;
    ssize_t ret;

    if (!fd || !line)
        return (-1);
    ret = read(fd, buffer, BUFFER_SIZE);                                        // expected : 3
    if (!ret)
        return (-1);                                                            // UNE ERREUR EST SURVENUE
    if (ret > 0)
    {
            buffer[ret] = '\0';                                                 // 1st loop : buffer is "Ce\0"
            
            while (ft_strchr(buffer, '\n') == 0)
            { 
                printf("Petit buffer : |%s|\n", buffer);              
                tmp = strdup(buffer);                              
                printf("Tmp 1 : |%s|\n", tmp);
                
                if (stock == NULL)
                {
                    stock = ft_strdup(tmp);
                    free(tmp);
                    printf("Stock 1 : |%s|\n", stock);
                }
                else if (stock)
                {
                    stock = ft_strjoin(stock, tmp);
                    free(tmp);
                }
            
                ret = read(fd, buffer, BUFFER_SIZE);  
                
                *line = stock;
                printf("Ca a ete join : |%s|\n", *line);
                printf("\n"); 
            }
                  
        if (*buffer == '\n')
        {
            // printf("\nLe programme a trouvé un retour à la ligne\n");                             
            return (1);                                                         // UNE LIGNE A ETE LUE
        }
        // ret = read(fd, buffer, BUFFER_SIZE);                                 // on relit pour avancer l'offset
        if (!ret)
                return (-1);                                                    // UNE ERREUR EST SURVENUE
    }
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
    // get_next_line(fd, &test);
    // printf("|%s|\n", test);
    // get_next_line(fd, &test);
    // printf("|%s|\n", test);
    // get_next_line(fd, &test);
    // printf("|%s|\n", test);
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
    
