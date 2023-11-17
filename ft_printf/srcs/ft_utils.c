/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:33:31 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/17 16:04:53 by megadiou         ###   ########.fr       */
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
