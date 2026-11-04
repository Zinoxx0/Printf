/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samercad <samercad@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:35:38 by samercad          #+#    #+#             */
/*   Updated: 2026/11/04 19:35:39 by samercad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

void	fput_base(unsigned long number, char *base, int *len);
void	fnum(int number, int *len);
void	fpointer(unsigned long pointer, int *len);

void	fputchar(char chr, int *len);
void	fputstr(char *str, int *len);

int		ft_printf(const char *string, ...);

#endif
