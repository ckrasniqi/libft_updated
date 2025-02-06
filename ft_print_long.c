/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:47:50 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 19:00:04 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
