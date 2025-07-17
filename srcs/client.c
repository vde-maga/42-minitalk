/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:45:50 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/16 16:45:50 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_print.h"
#include <signal.h>

void	send_signal(int pid, unsigned char character)
{
	int				i;
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
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	pid_t		server_id;
	char	*message;
	int	i;

	if (argc != 3)
	{
		ft_printf("Usage: ./minitalk <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = -1;
	while (message[++i])
		send_signal(server_pid, message[i]);
	send_signal(server_pid, '\0');
	return (0);
}