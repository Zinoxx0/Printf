/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samercad <samercad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:35:29 by samercad          #+#    #+#             */
/*   Updated: 2026/11/04 20:27:23 by samercad         ###   ########.fr       */
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

// #include <stdio.h>

// int main()
// {
// 	char		c;
// 	char		*str;
// 	int			d;
// 	int			totalPrinted;
// 	int			di;
// 	unsigned	int u;
// 	void		*ptr;

// 	c = 'a';
// 	str = "Hello World!";
// 	d = -42;
// 	totalPrinted = 0;
// 	di = 42;
// 	u = 4294967295;
// 	ptr = &d;
// 	printf("\n\nTesting ft_printf:\n");
// 	ft_printf("Character: %c\n", c);
// 	totalPrinted = ft_printf("String: %s\n", str);
// 	ft_printf("Total characters printed in string: %d\n", totalPrinted);
// 	ft_printf("Decimal: %d\n", di);
// 	ft_printf("Integer: %i\n", d);
// 	ft_printf("Unsigned: %u\n", u);
// 	ft_printf("Hex (lowercase): %x\n", u);
// 	ft_printf("Hex (uppercase): %X\n", u);
// 	ft_printf("Pointer: %p\n", ptr);
// 	ft_printf("Percent: %%\n");
// 	totalPrinted = 0;
// 	printf("\n\nTesting printf (original):\n");
// 	printf("Character: %c\n", c);
// 	totalPrinted = printf("String: %s\n", str);
// 	printf("Total characters printed in string: %d\n", totalPrinted);
// 	printf("Decimal: %d\n", di);
// 	printf("Integer: %i\n", d);
// 	printf("Unsigned: %u\n", u);
// 	printf("Hex (lowercase): %x\n", u);
// 	printf("Hex (uppercase): %X\n", u);
// 	printf("Pointer: %p\n", ptr);
// 	printf("Percent: %%\n");
// 	return (0);
// }