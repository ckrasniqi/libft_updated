/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:07:49 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/31 13:08:09 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr_fd(char *s, int *count)
{
	int	i;
	int	len;

	if (!s)
		ft_printf_putstr_fd("(null)", count);
	else
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			ft_printf_putchar_fd(s[i], 1, count);
			i++;
		}
	}
}
