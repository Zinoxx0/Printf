/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samercad <samercad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:35:29 by samercad          #+#    #+#             */
/*   Updated: 2026/11/04 19:35:30 by samercad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_check(char s, va_list *args, int *len, int *i)
{
	if (s == 's')
		fputstr(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		fnum(va_arg(*args, int), len);
	else if (s == 'u')
		fput_base(va_arg(*args, unsigned int), DECIMAL, len);
	else if (s == 'x')
		fput_base(va_arg(*args, unsigned int), HEX_LOWER, len);
	else if (s == 'X')
		fput_base(va_arg(*args, unsigned int), HEX_UPPER, len);
	else if (s == 'p')
		fpointer((unsigned long)va_arg(*args, void *), len);
	else if (s == 'c')
		fputchar(va_arg(*args, int), len);
	else if (s == '%')
		fputchar('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!string)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			print_check(string[i], &args, &len, &i);
			i++;
		}
		else
		{
			fputchar((char)string[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
