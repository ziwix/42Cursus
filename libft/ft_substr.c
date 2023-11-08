/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:48:46 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/08 16:45:42 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!s || start >= ft_strlen(s))
	{
		dst = (char *)malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > (ft_strlen(s) - start))
		dst = (char *)malloc(sizeof(char) * ((len - start) + 1));
	else
		dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s[start] && i < len)
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
