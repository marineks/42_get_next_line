/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:19:31 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/08 13:53:11 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    static char buffer[BUFFER_SIZE + 1];
    ssize_t ret;

    ret = read(fd, buffer, BUFFER_SIZE);
    while (ret > 0)
    {
        printf("nb de boucles\n");
        buffer[ret] = '\0';
        *line = strdup(buffer);
        printf("RET: %zu\n", ret);
        ret = read(fd, buffer, BUFFER_SIZE);
        printf("RET: %zu\n", ret);
        //ret = 0;
    }
   return (0);
}

int main()
{
    int fd;
    char *test;
    test= NULL;

    fd = open("test.txt", O_RDONLY);
    get_next_line(fd, &test);
    printf("|%s|\n", test);
    free(test);
    close(fd);
    return (0);
}
    
