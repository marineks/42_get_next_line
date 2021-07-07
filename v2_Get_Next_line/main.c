/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:35:23 by msanjuan          #+#    #+#             */
/*   Updated: 2021/07/07 18:27:37 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void f(void)
{
	system("leaks a.out");
}

int main()
{

    int		fd;
    // char	*ret;
    char    *line;

	
    fd = open("tests/test6", O_RDONLY);
    if (fd < 0)
        printf("\e[31mError: open failed\e[0m\n");
    else
    {
        // while ((ret = get_next_line(fd)) != NULL)
        // {
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
            printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
			line = get_next_line(fd);
			printf("\e[33mLine Read:\e[0m [%s]", line);
            free(line);
    }
		atexit(f);
        close(fd);
    // }
    // system("leaks a.out | grep 'leaks'");
    return (0);
}