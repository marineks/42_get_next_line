/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:35:23 by msanjuan          #+#    #+#             */
/*   Updated: 2021/07/09 17:05:31 by msanjuan         ###   ########.fr       */
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
    char    *line;

    fd = open("tests/paragraph_alternate_nl", O_RDONLY);
    if (fd < 0)
        printf("\e[31mError: open failed\e[0m\n");
    else
    {
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("\e[32mLine:\e[0m [%s]\n", line);
            free(line);
    	}
		if (!line) 
		{
			printf("\e[35mCall after EOF was reached:\e[1;31m [%s]\n", line);
			free(line);
		}
		printf("\e[0m\n");
		atexit(f);
        close(fd);
    }
    return (0);
}