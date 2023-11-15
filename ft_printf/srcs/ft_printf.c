/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:48:43 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/15 17:05:22 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_start_printf(va_list args, const char *format)
{
	int		i;

	i = 0;
	while (!format[i])
	{
		if (format[i] == '%')
		{
			i++;
			i += ft_check_args(args, format[i]);
		}
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	count = ft_start_printf(args, format);
	va_end(args);
	return (count);
}
