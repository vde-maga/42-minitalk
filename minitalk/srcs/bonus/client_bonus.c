/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:59:30 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/29 15:40:27 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

static void	send_bit(pid_t server_pid, int bit)
{
	int	timeout_counter;

	g_ack_received = 0;
	if (bit)
	{
		if (kill(server_pid, SIGUSR1) == -1)
			ft_error_exit("Error: Failed to send signal to server.\n");
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
			ft_error_exit("Error: Failed to send signal to server.\n");
	}
	timeout_counter = 0;
	while (g_ack_received == 0)
	{
		if (timeout_counter >= 500)
			ft_error_exit("Error: No response from server (timeout).\n");
		usleep(100);
		timeout_counter++;
	}
}

static void	send_message(pid_t server_pid, const char *message)
{
	int		i;
	int		bit_index;
	char	current_char;

	i = 0;
	while (1)
	{
		current_char = message[i];
		bit_index = 8;
		while (bit_index--)
			send_bit(server_pid, (current_char >> bit_index) & 1);
		if (current_char == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc != 3 || !argv[2][0])
		ft_error_exit("Usage: ./client <Server_PID> <Message>\n");
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error_exit("Error: Failed to set signal handler.\n");
	send_message(server_pid, argv[2]);
	write(1, "Message sent successfully!\n", 27);
	return (0);
}
