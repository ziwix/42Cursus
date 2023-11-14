/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:27:05 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/14 13:44:10 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_print_int_decimal(va_list args)
{
	int	num = va_arg(args, int);
	ft_putnbr_fd(num, 1);
}

void	ft_print_unsigned_int(va_list args)
{
	unsigned int	u_num;

	u_num = va_arg(args, unsigned int);
	ft_putnbr_unsigned(u_num);
}

void	ft_print_hexa(va_list args, char lowOrUp)
{
	int		hexa_num;
	char	*hexa_string = NULL;

	hexa_num = va_arg(args, int);
	if (lowOrUp == 'x')
	{
		hexa_string = ft_convert_to_hexa(args);
		ft_putstr_fd(hexa_string, 1);
	}
	if (lowOrUp == 'X')
	{
		hexa_string = ft_convert_to_hexa(args);
		ft_putstr_fd(hexa_string, 1);
	}
}
