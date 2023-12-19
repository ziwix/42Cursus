/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:33:22 by megadiou          #+#    #+#             */
/*   Updated: 2023/12/19 16:57:22 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

int	check_map(int fd)
{
	char	*map_line;
	char	*map;
	int		map_len;
	
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		map = ft_strjoin(map, map_line);
		free(map_line);
		map_line = NULL;
		map_line = get_next_line(fd);
	}
	if (!map)
		return (1);
	map = ft_strjoin(map, "\n");
	map_len = ft_strlen(map);
	return (0);
}
