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

void	fputstr(char *str, int *len)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	(*len) += i;
}
