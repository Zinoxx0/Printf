/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samercad <samercad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:35:56 by samercad          #+#    #+#             */
/*   Updated: 2026/11/04 19:35:57 by samercad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fnum(int number, int *len)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (number < 0)
	{
		fputchar('-', len);
		fnum(number * -1, len);
	}
	else
	{
		if (number > 9)
		{
			fnum(number / 10, len);
		}
		fputchar(number % 10 + '0', len);
	}
}

void	funsigned_int(unsigned int number, int *len)
{
	if (number > 9)
	{
		funsigned_int(number / 10, len);
	}
	fputchar(number % 10 + '0', len);
}

void	fhexadecimal(unsigned int number, int *len, char choose)
{
	char	str[25];
	char	*hexa_base;
	int		i;

	i = 0;
	if (choose == 'X')
		hexa_base = "0123456789ABCDEF";
	else
		hexa_base = "0123456789abcdef";
	if (number == 0)
	{
		fputchar('0', len);
		return ;
	}
	while (number != 0)
	{
		str[i] = hexa_base[number % 16];
		number = number / 16;
		i++;
	}
	while (i--)
		fputchar(str[i], len);
}

void	fpointer(unsigned long pointer, int *len)
{
	char	str[25];
	int		i;
	char	*hexa_base;

	hexa_base = "0123456789abcdef";
	i = 0;
	if (pointer == 0)
	{
		*len += write(1, "(nil)", 5);
		return ;
	}
	else
		*len += write(1, "0x", 2);
	while (pointer != 0)
	{
		str[i] = hexa_base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i)
	{
		i--;
		fputchar(str[i], len);
	}
}
