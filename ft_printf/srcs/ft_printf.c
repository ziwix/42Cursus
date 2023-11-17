/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:48:43 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/17 14:09:51 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_start_printf(va_list args, const char *format)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_check_args(args, format[i]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
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
