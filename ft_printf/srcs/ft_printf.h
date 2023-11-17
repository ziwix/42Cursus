/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:07 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/17 16:16:52 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

/************************/
/*		ft_printf.c		*/
/************************/

int		ft_printf(const char *format, ...);
int		ft_start_printf(va_list args, const char *format);

/************************/
/*		ft_parsing		*/
/************************/

char	*ft_parse_numb(const char *format);
int		ft_format_len(const char *to_count);
char	*ft_parse_format(char *dest, const char *to_parse);

/************************/
/*		ft_utils		*/
/************************/

int		ft_check_args(va_list args, char format);

/************************/
/*		ft_length		*/
/************************/

int		ft_len_hexa(int num);
int		ft_len_u_ptr(unsigned long long num);

/*********************/
/*		ft_hexa		 */
/*********************/

void	ft_putnbr_unsigned(unsigned int n);
void	ft_putnbr_base16(int num, int upLow);
void	ft_putptr(unsigned long long num);

/****************************/
/*		ft_print_chars		*/
/****************************/

int		ft_print_char(va_list args);
int		ft_print_string(va_list args);
int		ft_print_percent(void);

/**********************************/
/*        ft_print_numbers        */
/**********************************/

int		ft_print_int_decimal(va_list args);
int		ft_print_unsigned_int(va_list args);
int		ft_print_hexa(va_list args, char lowOrUp);
int		ft_print_ptr(va_list args);


#endif