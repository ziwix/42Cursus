/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:48:43 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/14 14:54:38 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start_printf(va_list args, const char *format)
{
	char	*formats;
	formats = ft_parse_numb(format);
	if (!formats)
		return ;
	ft_check_args(args, formats);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_start_printf(args, format);
	va_end(args);
	return (0);
}
