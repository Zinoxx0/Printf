/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samercad <samercad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:35:56 by samercad          #+#    #+#             */
/*   Updated: 2026/11/04 20:11:15 by samercad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fput_base(unsigned long number, char *base, int *len)
{
	unsigned long	size;

	size = 0;
	while (base[size])
		size++;
	if (number >= size)
		fput_base(number / size, base, len);
	fputchar(base[number % size], len);
}

void	fnum(int number, int *len)
{
	long	n;

	n = number;
	if (n < 0)
	{
		fputchar('-', len);
		n = -n;
	}
	fput_base(n, DECIMAL, len);
}

void	fpointer(unsigned long pointer, int *len)
{
	if (pointer == 0)
		fputstr("(nil)", len);
	else
	{
		fputstr("0x", len);
		fput_base(pointer, HEX_LOWER, len);
	}
}
