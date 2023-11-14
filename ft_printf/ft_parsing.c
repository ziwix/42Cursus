/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:43:13 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/14 14:55:23 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_numb(const char *format)
{
	char	*parsed_format;
	int		num_format;

	num_format = ft_format_len(format);
	parsed_format = (char *)malloc(sizeof(char) * (num_format + 1));
	if (!parsed_format)
		return (NULL);
	parsed_format = ft_parse_format(parsed_format, format);
	if (!parsed_format)
		return (NULL);
	return (parsed_format);
}

int	ft_format_len(const char *to_count)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (to_count[i])
	{
		if (to_count[i] == '%')
		{
			i++;
			len++;
		}
		i++;
	}
	return (len);
}

char	*ft_parse_format(char *dest, const char *to_parse)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (to_parse[i])
	{
		if (to_parse[i] == '%')
		{
			i++;
			dest[n] = to_parse[i];
			n++;
		}
		i++;
	}
	return (dest);
}
