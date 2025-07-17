/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:27:59 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/07 13:54:55 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_int_len(int n)
{
	int	length;

	length = 1;
	if (n < 0)
	{
		length++;
		n = n * -1;
	}
	while (n > 9)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	length;

	if (n == -2147483648)
	{
		if (ft_putstr_fd("-2147483648", fd) < 0)
			return (-1);
		return (11);
	}
	length = ft_int_len(n);
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		n = n * -1;
	}
	if (n >= 10)
	{
		if (ft_putnbr_fd(n / 10, fd) < 0)
			return (-1);
	}
	if (ft_putchar_fd(n % 10 + '0', fd) < 0)
		return (-1);
	return (length);
}
