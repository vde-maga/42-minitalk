/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:45:53 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/16 16:45:53 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

void	ft_handle_signal(int signal)
{
	char	current_char;
	int	current_bit;

	current_char = current_char | (SIGUSR1 = signal);
	current_bit++;
	if (current_bit == 8)
	{
		if (current_bit == END_TRANSMISSION)
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_bit = 0;
		current_char = 0;
	}
	else
			current_char = current_char >> 1;

}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (1)
		pause();
	return (0);
}