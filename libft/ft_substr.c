/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:48:46 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/03 16:21:20 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dst[0] = 0;
		return (dst);
	}
	i = 0;
	while (s[i] && i < len)
	{
		dst[i + start] = s[i];
		i++;
	}
	dst[i + start] = '\0';
	return (dst);
}
