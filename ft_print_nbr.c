/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:57:41 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 19:00:06 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_nbr(int n, int *count)
{
	char	*str;

	if (n == INT_MIN)
	{
		ft_printf_putstr_fd("-2147483648", count);
		return ;
	}
	else if (n == INT_MAX)
	{
		ft_printf_putstr_fd("2147483647", count);
		return ;
	}
	str = ft_itoa(n);
	if (!str)
	{
		*count = -1;
		return ;
	}
	else
	{
		ft_printf_putstr_fd(str, count);
		free(str);
	}
	return ;
}
