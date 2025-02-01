/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:47:50 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/31 13:06:59 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_long(unsigned int n, int *count)
{
	char	*str;

	str = ft_itoa_long(n);
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
}
