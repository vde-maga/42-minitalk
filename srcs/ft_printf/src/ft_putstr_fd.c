/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:55:08 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/07 14:01:37 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	length;
	int	char_count;

	char_count = 0;
	length = 0;
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	while (*s)
	{
		char_count = ft_putchar_fd(*s++, fd);
		if (char_count < 0)
			return (-1);
		length = length + char_count;
	}
	return (length);
}
