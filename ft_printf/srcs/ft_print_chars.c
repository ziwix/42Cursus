/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:39:49 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/14 15:42:50 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
}

void	ft_print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
}

void	ft_print_percent()
{
	char	c;

	c = '%';
	ft_putchar_fd(c, 1);
}
