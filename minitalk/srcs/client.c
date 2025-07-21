/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:45:50 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/21 17:31:31 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	signal;

	result = 0;
	signal = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal = signal * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * signal);
}

void	send_signal(int pid, unsigned char character)
{
	int		i;
	char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_id;
	int		i;

	if (argc != 3)
	{
		write(1, "Usage: ./client <pid> <message>\n", 32);
		return (1);
	}
	server_id = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_signal(server_id, argv[2][i]);
		i++;
	}
	send_signal(server_id, '\0');
	return (0);
}