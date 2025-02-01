/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:46:21 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/31 13:10:32 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_fspecifier(const char *format, va_list args, int i, int *count)
{
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
			return (ft_printf_putchar_fd(va_arg(args, int), 1, count));
		else if (format[i] == '%' && format[i + 1] == 's')
			return (ft_printf_putstr_fd(va_arg(args, char *), count));
		else if (format[i] == '%' && format[i + 1] == 'p')
			return (ft_print_ptr(va_arg(args, void *), count));
		else if (format[i] == '%' && (format[i + 1] == 'd'))
			return (ft_print_nbr(va_arg(args, int), count));
		else if (format[i] == '%' && (format[i + 1] == 'i'))
			return (ft_print_nbr(va_arg(args, int), count));
		else if (format[i] == '%' && format[i + 1] == 'u')
			return (ft_print_long(va_arg(args, unsigned int), count));
		else if (format[i] == '%' && format[i + 1] == 'x')
			return (ft_print_hex_l(va_arg(args, unsigned long), count));
		else if (format[i] == '%' && format[i + 1] == 'X')
			return (ft_print_hex_u(va_arg(args, unsigned long), count));
		else if (format[i] == '%' && format[i + 1] == '%')
			return (ft_printf_putchar_fd('%', 1, count));
		else
			return ;
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			find_fspecifier(format, args, i, &count);
			i++;
		}
		else
			ft_printf_putchar_fd(format[i], 1, &count);
		i++;
	}
	va_end(args);
	return (count);
}
