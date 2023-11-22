/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:54:52 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/22 14:46:24 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcpy(char *dst, char const *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

static int	ft_lenstr(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*dest;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_lenstr(s1);
	len_s2 = ft_lenstr(s2);
	dest = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!dest)
		return (NULL);
	i = ft_strcpy(dest, s1);
	ft_strcpy(dest + i, s2);
	return (dest);
}
