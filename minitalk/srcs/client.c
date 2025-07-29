/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:45:50 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/29 15:08:59 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

void	ft_ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	ft_send_bit(pid_t pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	while (g_ack_received == 0)
		pause();
	g_ack_received = 0;
}

static void	ft_send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
		ft_send_bit(pid, (c >> i) & 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				server_pid;
	int					i;

	if (argc != 3)
	{
		write(1, "Usage: ./client <pid> <message>\n", 32);
		return (1);
	}
	act.sa_handler = ft_ack_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_send_char(server_pid, argv[2][i]);
		i++;
	}
	ft_send_char(server_pid, '\0');
	return (0);
}
