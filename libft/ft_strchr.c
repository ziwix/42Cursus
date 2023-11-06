/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:09:50 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/06 15:30:04 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!ft_isascii(c))
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == c)
			return (((char *)s + i));
		i++;
	}
	if (c == 0)
		return (((char *)s + i));
	return (0);
}
