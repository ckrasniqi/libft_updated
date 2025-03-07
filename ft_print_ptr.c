/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:19:15 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 19:00:08 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length_of_hex(unsigned long long num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	print_hex(unsigned long long num, int *count)
{
	int		len;
	char	*hex_digits;
	char	*array_hex;
	int		temp;

	len = length_of_hex(num);
	hex_digits = "0123456789abcdef";
	array_hex = ft_calloc(len + 1, sizeof(char));
	if (!array_hex)
	{
		*count = -1;
		return ;
	}
	len--;
	while (num > 0)
	{
		temp = num % 16;
		num /= 16;
		array_hex[len--] = hex_digits[temp];
	}
	ft_printf_putstr_fd(array_hex, count);
	free(array_hex);
}

void	ft_print_ptr(void *ptr, int *count)
{
	unsigned long long	num;

	ft_printf_putstr_fd("0x", count);
	num = (unsigned long long)ptr;
	if (num == 0)
		ft_printf_putstr_fd("0", count);
	else
		print_hex((unsigned long long) num, count);
}
