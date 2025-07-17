/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:30:54 by vde-maga          #+#    #+#             */
/*   Updated: 2025/05/07 15:34:00 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_printf_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_send_to_correct_function(va_list args, char c, int *plength)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		char_count = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		char_count = ft_putpointer(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		char_count = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		char_count = ft_putnbr_u_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		char_count = ft_hexadecimal(va_arg(args, unsigned int), c);
	else if (c == '%')
		char_count = ft_putchar_fd('%', 1);
	else
		return (-1);
	if (char_count < 0)
		*plength = -1;
	else
		*plength = *plength + char_count;
	return (*plength);
}

static int	ft_format_check(const char *format, va_list args, int *plength)
{
	int	length;

	length = *plength;
	while (*format)
	{
		if (*format == '%' && ft_is_printf_char(*(format + 1)))
		{
			length = ft_send_to_correct_function(args, *(format + 1), &length);
			if (length < 0)
				return (-1);
			format++;
		}
		else
		{
			length = length + ft_putchar_fd(*format, 1);
			if (length < 0)
				return (-1);
		}
		format++;
	}
	*plength = length;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	if (ft_format_check(format, args, &length) < 0)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (length);
}
/*
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

// Definições de cores ANSI
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int	main(void)
{
	char			c;
	char			*str;
	int				x = 42, num1 = 123, num2;
	unsigned int	u_num = 3000000000U, hex;
	char			*null_str;
	void			*null_ptr;

	c = 'A';
	str = "Olá, mundo!";
	x = 42, num1 = 123, num2 = -456;
	u_num = 3000000000U, hex = 255;
	null_str = NULL;
	null_ptr = NULL;
	printf(BLUE "======== TESTES COM CARACTERES ========\n" RESET);
	printf(GREEN "Printf: Caractere: %c\n" RESET, c);
	ft_printf(RED "Ft_printf: Caractere: %c\n" RESET, c);
	printf(BLUE "======== TESTES COM STRINGS ========\n" RESET);
	printf(GREEN "Printf: String: %s\n" RESET, str);
	ft_printf(RED "Ft_printf: String: %s\n" RESET, str);
	printf(BLUE "======== TESTES COM PONTEIROS ========\n" RESET);
	printf(GREEN "Printf: Endereço de x: %p\n" RESET, (void *)&x);
	ft_printf(RED "Ft_printf: Endereço de x: %p\n" RESET, &x);
	printf(BLUE "======== TESTES COM NÚMEROS ========\n" RESET);
	printf(GREEN "Printf: Número decimal: %d\n" RESET, num1);
	ft_printf(RED "Ft_printf: Número decimal: %d\n" RESET, num1);
	printf(GREEN "Printf: Número inteiro: %i\n" RESET, num2);
	ft_printf(RED "Ft_printf: Número inteiro: %i\n" RESET, num2);
	printf(BLUE "======== TESTES COM NÚMEROS SEM SINAL ========\n" RESET);
	printf(GREEN "Printf: Número sem sinal: %u\n" RESET, u_num);
	ft_printf(RED "Ft_printf: Número sem sinal: %u\n" RESET, u_num);
	printf(BLUE "======== TESTES COM HEXADECIMAIS ========\n" RESET);
	printf(GREEN "Printf: Hexadecimal minúsculo: %x\n" RESET, hex);
	ft_printf(RED "Ft_printf: Hexadecimal minúsculo: %x\n" RESET, hex);
	printf(GREEN "Printf: Hexadecimal maiúsculo: %X\n" RESET, hex);
	ft_printf(RED "Ft_printf: Hexadecimal maiúsculo: %X\n" RESET, hex);
	printf(BLUE "======== TESTES COM PORCENTAGEM ========\n" RESET);
	printf(GREEN "Printf: Porcentagem: %%\n" RESET);
	ft_printf(RED "Ft_printf: Porcentagem: %%\n" RESET);
	printf(YELLOW "======== TESTES COM NULLS & ERROS ========\n" RESET);
	printf(GREEN "Printf: String NULL: %s\n" RESET, null_str);
	ft_printf(RED "Ft_printf: String NULL: %s\n" RESET, null_str);
	printf(GREEN "Printf: Ponteiro NULL: %p\n" RESET, null_ptr);
	ft_printf(RED "Ft_printf: Ponteiro NULL: %p\n" RESET, null_ptr);
	printf(GREEN "Printf: INT_MAX: %d\n" RESET, INT_MAX);
	ft_printf(RED "Ft_printf: INT_MAX: %d\n" RESET, INT_MAX);
	printf(GREEN "Printf: INT_MIN: %d\n" RESET, INT_MIN);
	ft_printf(RED "Ft_printf: INT_MIN: %d\n" RESET, INT_MIN);
	printf(GREEN "Printf: UINT_MAX: %u\n" RESET, UINT_MAX);
	ft_printf(RED "Ft_printf: UINT_MAX: %u\n" RESET, UINT_MAX);
	printf(MAGENTA "======== TESTES COM FORMATAÇÃO ESTRANHA ========\n" RESET);
	printf(GREEN "Printf: Mistura estranha: %s %d %%\n" RESET, "Texto", 42);
	ft_printf(RED "Ft_printf: Mistura estranha: %s %d %%\n" RESET, "Texto", 42);
	return (0);
}
*/
