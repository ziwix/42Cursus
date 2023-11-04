/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:11:25 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/04 17:50:05 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_find_power(int nb)
{
	int	pow;

	pow = 1;
	while (nb / 10 != 0)
	{
		nb /=10;
		pow *= 10;
	}
	return (pow);
}

static void	ft_putnbr(int nb, char *arr)
{
	int	pow;
	int	i;

	i = 0;
	pow = ft_find_power(nb);
	if (nb < 0)
	{
		arr[i] = '-';
		nb *= -1;
		i++;
	}
	while (pow >= 1)
	{
		arr[i] = (nb / pow) + '0';
		nb %= pow;
		pow /= 10;
		i++;
	}
	arr[i] = 0;
}

int	ft_size(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb / 10 != 0)
	{
		nb /= 10;
		i++;	
	}
	return (i);
}

#include <stdio.h>

char	*ft_itoa(int n)
{
	int		i;
	char	*arr;

	i = ft_size(n);
	printf("SIZZZZZZZZZZZZZZZZZZZZZZZZZZZE : %d\n", i + 1);
	if (n == -2147483648)
	{
		arr = (char *)malloc(sizeof(char) * 12);
		if (!arr)
			return (NULL);
		arr = "-2147483648";
		arr[11] = 0;
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	ft_putnbr(n, arr);
	return (arr);
}

#include <stdlib.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char *res = ft_itoa(0);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 2)
	{
		char *res = ft_itoa(9);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 3)
	{
		char *res = ft_itoa(-9);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 4)
	{
		char *res = ft_itoa(10);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 5)
	{
		char *res = ft_itoa(-10);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 6)
	{
		char *res = ft_itoa(8124);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 7)
	{
		char *res = ft_itoa(-9874);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 8)
	{
		char *res = ft_itoa(543000);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 9)
	{
		char *res = ft_itoa(-2147483648LL);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 10)
	{
		char *res = ft_itoa(2147483647);
		ft_print_result(res);
		free(res);
	}
	return (0);
}
