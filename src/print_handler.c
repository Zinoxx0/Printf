/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samercad <samercad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:35:49 by samercad          #+#    #+#             */
/*   Updated: 2026/11/04 19:35:50 by samercad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fputchar(char chr, int *len)
{
	write(1, &chr, 1);
	(*len)++;
}

void	fputstr(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (args == 0)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		fputchar(args[i], len);
		i++;
	}
}
