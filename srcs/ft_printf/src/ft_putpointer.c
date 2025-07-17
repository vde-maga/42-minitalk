/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:05:23 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/07 14:59:51 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_pointer_address(size_t x, char *base)
{
	char	string[25];
	int		i;
	int		length;
	int		char_count;

	i = 0;
	length = 0;
	while (x != 0)
	{
		string[i++] = base[x % 16];
		x = x / 16;
	}
	while (i--)
	{
		char_count = ft_putchar_fd(string[i], 1);
		if (char_count < 0)
			return (-1);
		length = length + char_count;
	}
	return (length);
}

int	ft_putpointer(size_t x)
{
	char	base[17];
	int		length;
	int		char_count;

	ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (x == 0)
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	length = 2;
	char_count = ft_print_pointer_address(x, base);
	if (char_count < 0)
		return (-1);
	length = length + char_count;
	return (length);
}
