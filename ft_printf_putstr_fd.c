/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:05:08 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 19:57:19 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
