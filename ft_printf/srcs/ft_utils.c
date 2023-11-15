/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:33:31 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/15 17:06:48 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_args(va_list args, char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_print_char(args);
	if (format == 's')
		i += ft_print_string(args);
	if (format == '%')
		i += ft_print_percent();
	if (format == 'd' || format == 'i')
		i += ft_print_int_decimal(args);
	if (format == 'u')
		i += ft_print_unsigned_int(args);
	if (format == 'x' || format == 'X')
		i += ft_print_hexa(args, format);
	if (format == 'p')
		i += ft_print_ptr(args);
	return (i);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	char	c;

	c = '0';
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr_base16(int num, int upLow)
{
	int	tmp;

	tmp = 0;
	if (num)
	{
		tmp = num % 16;
		ft_putnbr_base16(num / 16, upLow);
		if (tmp > 9)
			ft_putchar_fd(tmp + upLow, 1);
		else
			ft_putchar_fd(tmp + 48, 1);
	}
}

void	ft_putptr(uintptr_t num)
{
	uintptr_t	tmp;

	tmp = 0;
	if (num)
	{
		tmp = num % 16;
		ft_putptr(num / 16);
		if (tmp > 9)
			ft_putchar_fd(tmp + 87, 1);
		else
			ft_putchar_fd(tmp + 48, 1);
	}
}
