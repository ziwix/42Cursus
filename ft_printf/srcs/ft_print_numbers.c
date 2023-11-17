/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:27:05 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/17 16:36:13 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_decimal(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
	return (1);
}

int	ft_print_unsigned_int(va_list args)
{
	unsigned int	u_num;

	u_num = va_arg(args, unsigned int);
	ft_putnbr_unsigned(u_num);
	return (1);
}

int	ft_print_hexa(va_list args, char format)
{
	int	hexa_num;
	int	count;

	hexa_num = va_arg(args, int);
	count = ft_len_hexa(hexa_num);
	if (format == 'x')
		ft_putnbr_base16(hexa_num, 87);
	if (format == 'X')
		ft_putnbr_base16(hexa_num, 55);
	return (count);
}

int	ft_print_ptr(va_list args)
{
	char	*ptr;
	int		count;

	ptr = va_arg(args, char *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count = ft_len_u_ptr(((unsigned long long)ptr));
	ft_putstr_fd("0x", 1);
	count += 2;
	ft_putptr((unsigned long long)ptr);
	return (count);
}
