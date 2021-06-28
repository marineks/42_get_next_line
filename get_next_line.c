/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:31 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/28 11:42:41 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
            buffer[ret] = '\0';                                                 // 1st loop : buffer is "Cec\0"
            
            // *line = strdup(strjoin(stock, buffer));    
            printf("Petit buffer : |%s|\n", buffer);                      // sensé rassembler les bouts de la ligne jusqu'au \n
            tmp = strdup(buffer);  
            printf("Tmp 1 : |%s|\n", tmp);
            *line = ft_strjoin(stock, tmp);
            ret = read(fd, buffer, BUFFER_SIZE); 
            printf("\n");   

            printf("Nouveau buffer : |%s|\n", buffer);
            tmp = strdup(buffer); 
            printf("Nv tmp : |%s|\n", tmp);
            *line = ft_strjoin(stock, tmp);
            printf("Stock: |%s|\n", stock);
            printf("\n");
            // while (ft_strchr(stock, '\n') == 0)
            // {

            // }   

        if (*buffer == '\n')
        {
            // printf("\nLe programme a trouvé un retour à la ligne\n");                             
            return (1);                                                         // UNE LIGNE A ETE LUE
        }
        // ret = read(fd, buffer, BUFFER_SIZE);                                    // on relit pour avancer l'offset
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
    
