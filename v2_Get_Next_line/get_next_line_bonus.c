/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:50:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/07/09 18:05:24 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_the_line(char *stock)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	line = NULL;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	len = i + 1;
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

void	ft_get_the_spare(char *buffer)
{
	int	i;
	int	j;

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

char	*ft_stopEOF_or_giveLine(int ret, char **line, char *stock, char *buffer)
{
	char	*line;

	line = NULL;
	if (ft_strlen(stock) == 0)
	{
		free(stock);
		return (NULL);
	}
	if (ret == 0)
		line = ft_get_the_line(stock);
	else
	{
		line = ft_get_the_line(stock);
		ft_get_the_spare(buffer[fd]);
	}
	free(stock);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*stock;
	int			ret;

	stock = NULL;
	if ((read(fd, buffer, 0) == -1) || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	stock = ft_strjoin(stock, buffer[fd]);
	while (ft_strchr(stock, '\n') == NULL && ret > 0)
	{
		ret = read(fd, buffer[fd], BUFFER_SIZE);
		if (ret < 0)
		{
			free(stock);
			return (NULL);
		}
		buffer[fd][ret] = '\0';
		stock = ft_strjoin(stock, buffer[fd]);
	}
	return (ft_stopEOF_or_giveLine(ret, stock, buffer[fd]));
}
