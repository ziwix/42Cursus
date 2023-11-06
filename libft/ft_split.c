/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:16:02 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/06 18:29:49 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (*s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_mal_strs(char const *s, char **strs, char c, int count)
{
	int		n;
	int		j;
	size_t	words_len;

	n = 0;
	words_len = 0;
	j = 0;
	while (n < count)
	{
		while (*s == c)
			s++;
		words_len = ft_words_len(s, c);
		strs[n] = (char *)malloc(sizeof(char) * (words_len + 1));
		if (!strs[n])
			return (1); //FREE ALL
		ft_strlcpy(strs[n], s, words_len + 1);
		s += words_len;
		n++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		result;
	char	**strs;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * count + 1);
	if (!strs)
		return (NULL);
	result = ft_mal_strs(s, strs, c, count);
	strs[count] = 0;
	if (result == 1)
		return (NULL);
	return (strs);
}

int main(void)
{
	ft_split("  tripouille  42  ", ' ');
	return 0;
}

