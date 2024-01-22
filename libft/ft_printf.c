/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:58:41 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/01/20 15:47:16 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format_type(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_fd2(va_arg(args, int), 1);
	else if (format == 's')
		count += ft_putstr_fd2(va_arg(args, char *), 1);
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int), 10);
	else if (format == 'u')
		count += ft_print_u(va_arg(args, unsigned int), 10);
	else if (format == 'x')
		count += ft_print_hex((long) va_arg(args, unsigned int), 16, 'x');
	else if (format == 'X')
		count += ft_print_hex((long)va_arg(args, unsigned int), 16, 'X');
	else if (format == 'p')
		count += ft_hex_adress((unsigned long)va_arg(args, void *), 16, 'p');
	else if (format == '%')
		count += ft_putchar_fd2('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count += format_type(format[++i], args);
		else
			count += write(1, &format[i], 1);
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
 }
