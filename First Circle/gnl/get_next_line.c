/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:08:47 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/24 16:38:22 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = read_file(fd, stock);
	if (!stock)
		return (NULL);
	line = get_line(stock);
	stock = trim_stock(stock, ft_strlen(line));
	return (line);
}

char	*read_file(int fd, char *stock)
{
	char	*buff;
	int		read_size;

	while (1)
	{
		buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		stock = ft_strjoin(stock, buff);
		free(buff);
		buff = NULL;
		if (have_newline(stock) > 0 || read_size < BUFFER_SIZE)
			return (stock);
	}
	return (NULL);
}

char	*get_line(char *stock)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_calloc(sizeof(char), have_newline(stock) + 1);
	if (!line)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	have_newline(char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*trim_stock(char *stock, int start)
{
	int		i;
	char	*dest;

	i = 0;
	while (stock[start + i])
		i++;
	dest = ft_calloc(sizeof(char), i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (stock[start + i])
	{
		dest[i] = stock[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("Result 1 : '%s'\n", str);
	free(str);
	str = get_next_line(fd);
	printf("Result 2 : '%s'\n", str);
	free(str);
	str = get_next_line(fd);
	printf("Result 3 : '%s'\n", str);
	free(str);
	close(fd);
	return (0);
}
