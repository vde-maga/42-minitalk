/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:32:26 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/07 13:53:45 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_u_int_len(unsigned int a)
{
	int	length;

	length = 1;
	while (a > 9)
	{
		length++;
		a = a / 10;
	}
	return (length);
}

int	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int	length;

	length = ft_u_int_len(n);
	if (n >= 10)
	{
		if (ft_putnbr_u_fd(n / 10, fd) < 0)
			return (-1);
	}
	if (ft_putchar_fd(n % 10 + '0', fd) < 0)
		return (-1);
	return (length);
}
