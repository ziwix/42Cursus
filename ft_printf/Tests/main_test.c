/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:31:08 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/14 14:33:52 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main() 
{
	long int decNum,quo;
	int i=1,j,temp;
	char hexadecNum[100];

	printf("Enter any decimal number to convert it to hexadecimal Number: ");
	scanf("%ld",&decNum);
	quo = decNum;
	while (quo != 0)
	{
		temp = quo % 16;
		if( temp < 10)
			temp = temp + 48; 
		else
			temp = temp + 55;
		hexadecNum[i++] = temp;
		quo = quo / 16;
	}
	printf("hexadecimal value of decimal number entered is %ld: ",decNum);
	for (j = i - 1 ;j > 0; j--)
		printf("%c", hexadecNum[j]);
	return (0);
}
