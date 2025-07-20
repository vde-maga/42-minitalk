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

#include "ft_printf.h"
//#include "libftprintf.h"
#include <signal.h>

#define LIVE 1

void	ft_handle_signal(int signal)
{
	static unsigned char	current_char;
	static int	current_bit;

	current_char = current_char | (signal == SIGUSR1);
	current_bit++;
	if (current_bit == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_bit = 0;
		current_char = 0;
	}
	else
			current_char = current_char << 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (LIVE)
		pause();
	return (0);
}
