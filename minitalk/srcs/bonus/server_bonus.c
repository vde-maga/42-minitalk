/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:56:00 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/29 15:40:34 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	process_byte(t_state *state)
{
	if (state->current_char == '\0')
		write(1, "\n", 1);
	else
		write(1, &state->current_char, 1);
	state->bit_count = 0;
	state->current_char = 0;
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static t_state	state = {0, 0};

	(void)context;
	state.current_char = (state.current_char << 1) | (sig == SIGUSR1);
	state.bit_count++;
	if (state.bit_count == 8)
		process_byte(&state);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		state.bit_count = 0;
		state.current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server PID: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error_exit("Error setting SIGUSR1 handler\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error_exit("Error setting SIGUSR2 handler\n");
	while (1)
		pause();
	return (0);
}
