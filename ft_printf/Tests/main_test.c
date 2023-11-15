/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:31:08 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/15 16:54:56 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include <stdint.h>

void	ft_putptr(uintptr_t num, int upLow)
{
	uintptr_t	tmp;

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

int	main(void)
{
	char	*str = "Ssalut c'est ziwix";
	ft_putstr_fd("0x", 1);
	ft_putnbr_base16((uintptr_t)str, 87);
	printf("\n%p", str);
	return (0);
}
