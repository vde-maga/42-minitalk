/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:03:34 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/07 15:13:36 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_hexadecimal(unsigned int x, char *base)
{
	char	string[9];
	int		i;
	int		length;
	int		result;

	i = 0;
	length = 0;
	while (x != 0)
	{
		string[i++] = base[x % 16];
		x = x / 16;
	}
	while (i--)
	{
		result = ft_putchar_fd(string[i], 1);
		if (result < 0)
			return (-1);
		length = length + result;
	}
	return (length);
}

int	ft_hexadecimal(unsigned int x, char format)
{
	char	base[17];
	int		length;
	int		result;

	if (format == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", sizeof(base));
	else
		ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (x == 0)
	{
		if (ft_putchar_fd('0', 1) < 0)
			return (-1);
		return (1);
	}
	length = 0;
	result = ft_print_hexadecimal(x, base);
	if (result < 0)
		return (-1);
	length = length + result;
	return (length);
}
