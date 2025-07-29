/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:58:20 by vde-maga          #+#    #+#             */
/*   Updated: 2025/07/29 15:40:45 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_state
{
	unsigned char	current_char;
	int				bit_count;
}					t_state;

void				ft_error_exit(const char *message);
int					ft_atoi(const char *str);
void				ft_putnbr(int n);

#endif
