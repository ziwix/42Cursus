/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:08:47 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/22 18:01:04 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	line = start_get_line(fd);
	return (line);
}

char	*start_get_line(int fd)
{
	static char	*stock;
	char		*buff;
	char		*line;
	size_t		stock_len;

	while (1)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		read(fd, buff, BUFFER_SIZE);
		if (!stock)
			stock = ft_substr(buff, BUFFER_SIZE);
		else
			stock = ft_strjoin(stock, buff);
		stock_len = have_newline(stock);
		if (stock_len > 0)
		{
			line = ft_substr(stock, stock_len);
			stock = trim_remains(stock + 1, stock_len);
			return (line);
		}
	}
	return (NULL);
}

size_t	have_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*trim_remains(char	*str, size_t len)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	while (str[len + i])
	{
		dst[i] = str[len + i];
		i++;
	}
	dst[i] = '\0';
	free(str);
	return (dst);
}

#include <stdio.h>

int main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*str = get_next_line(fd);
	printf("Result 1 : %s\n", str);
	// str = get_next_line(fd);
	// printf("Result 2 : %s\n", str);
	// str = get_next_line(fd);
	// printf("Result 3 : %s\n", str);
	close(fd);
	return (0);
}
