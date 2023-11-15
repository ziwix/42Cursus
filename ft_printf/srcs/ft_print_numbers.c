/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:27:05 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/15 17:09:24 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_decimal(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
}

void	ft_print_unsigned_int(va_list args)
{
	unsigned int	u_num;

	u_num = va_arg(args, unsigned int);
	ft_putnbr_unsigned(u_num);
}

void	ft_print_hexa(va_list args, char format)
{
	int	hexa_num;

	hexa_num = va_arg(args, int);
	if (format == 'x')
		ft_putnbr_base16(hexa_num, 87);
	if (format == 'X')
		ft_putnbr_base16(hexa_num, 55);
}

void	ft_print_ptr(va_list args)
{
	char	*ptr;

	ptr = va_arg(args, char *);
	ft_putptr((uintptr_t)ptr);
}
