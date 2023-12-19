/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:14:09 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/11 16:37:29 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	*str = "salut";
	char	str2[5];

	printf("%zu\n%s\n", ft_strlcpy(str2, str, 6), str2);
	//printf("%zu\n%s\n", strlcpy(str2, str, 6), str2);
	return (0);
}
