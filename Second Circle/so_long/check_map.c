/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:33:22 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/20 13:58:59 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

static void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	check_map(int fd)
{
	char	*map_line;
	char	*map = NULL;
	char	**map_lines;
	int		i;

	i = 0;
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		map = ft_strjoin(map, map_line);
		free(map_line);
		map_line = NULL;
		map_line = get_next_line(fd);
	}
	free(map_line);
	if (!map)
		return (1);
	map = ft_strjoin(map, "\n");
	map_lines = ft_split(map, '\n');
	free(map);
	if (!map_lines)
	{
		free_split(map_lines);
		return (1);
	}
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("map/map_1.ber", O_RDONLY);
	if (check_map(fd) == 1)
		ft_printf("Invalid Map");
	else
		ft_printf("Valid Map");
	close(fd);
}