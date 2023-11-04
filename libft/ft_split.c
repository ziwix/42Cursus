/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:16:02 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/04 16:04:34 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static int	ft_words_len(char const *s, char c, int *i)
{
	while (s[*i])
	{
		if ((s[*i] == c || s[(*i) + 1] == 0))
			return ((*i));
		(*i)++;
	}
	return (0);
}

static void	ft_put_words(char const *s, char *strs, int words_len)
{
	int	i;

	i = 0;
	while (s[i] && i < words_len)
	{
		strs[i] = s[i];
		i++;
	}
	strs[i] = 0;
}

static int	ft_mal_strs(char const *s, char **strs, char c, int count)
{
	int	n;
	int	j;
	int	words_len;

	n = 0;
	words_len = 0;
	j = 0;
	while (n < count)
	{
		words_len = ft_words_len(s + j, c, &j);
		strs[n] = (char *)malloc(sizeof(char) * (words_len + 1));
		if (!strs[n])
			return (1);
		if (n == 0)
			ft_put_words(s, strs[n], words_len);
		else
			ft_put_words(s + j, strs[n], words_len);
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
	strs = (char **)malloc(sizeof(char) * count + 1);
	if (!strs)
		return (NULL);
	strs[count] = 0;
	result = ft_mal_strs(s, strs, c, count);
	if (result == 1)
		return (NULL);
	return (strs);
}
