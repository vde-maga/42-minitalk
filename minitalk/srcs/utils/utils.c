/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:05:42 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/29 15:40:16 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	ft_error_exit(const char *message)
{
	int	len;

	len = 0;
	while (message[len])
		len++;
	write(2, message, len);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	long	pid;

	pid = 0;
	if (!str)
		ft_error_exit("Error: PID is null.\n");
	while (*str >= '0' && *str <= '9')
	{
		pid = pid * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' || pid <= 100 || pid > 99999)
		ft_error_exit("Error: Invalid PID format or value.\n");
	return ((int)pid);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
