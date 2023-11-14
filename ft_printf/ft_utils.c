/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:33:31 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/14 14:40:20 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_args(va_list args, char *formats)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(formats);
	while (i <= len)
	{
		if (formats[i] == 'c')
			ft_print_char(args);
		if (formats[i] == 's')
			ft_print_string(args);
		if (formats[i] == '%')
			ft_print_percent();
		if (formats[i] == 'd' || formats[i] == 'i')
			ft_print_int_decimal(args);
		if (formats[i] == 'u')
			ft_print_unsigned_int(args);
		if (formats[i] == 'x' || formats[i] == 'X')
			ft_print_hexa(args, formats[i]);
		//if (formats[i] == 'p') // void * pointer in hexa
			
		i++;
	}
	free(formats);
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

char	*ft_convert_to_hexa(va_list args)
{
	long int	num;
	int			tmp;
	int			i;
	char		hexa_num[100];

	i = 0;
	num = va_arg(args, long int);
	while (num != 0)
	{
		tmp = num % 16;
		if (tmp < 10)
			tmp += 48;
		else
			tmp += 55;
		hexa_num[i++] = tmp;
		num /= 16;
	}
	return (hexa_num);
}

