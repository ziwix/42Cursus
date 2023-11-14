/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:07 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/14 14:55:59 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/************************/
/*		ft_printf.c		*/
/************************/

int	ft_printf(const char *format, ...);
void	ft_start_printf(va_list args, const char *format);

/************************/
/*		ft_parsing		*/
/************************/

char	*ft_parse_numb(const char *format);
int	ft_format_len(const char *to_count);
char	*ft_parse_format(char *dest, const char *to_parse);

/************************/
/*		ft_utils		*/
/************************/

void	ft_check_args(va_list args, char *formats);
void	ft_putnbr_unsigned(unsigned int n);
char	*ft_convert_to_hexa(va_list args);

/****************************/
/*		ft_print_chars		*/
/****************************/

void	ft_print_char(va_list args);
void	ft_print_string(va_list args);
void	ft_print_percent();

/**********************************/
/*        ft_print_numbers        */
/**********************************/

void	ft_print_int_decimal(va_list args);
void	ft_print_unsigned_int(va_list args);
void	ft_print_hexa(va_list args, char lowOrUp);

#endif