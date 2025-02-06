/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:06:18 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 19:17:30 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putchar_fd(char c, int fd, int *count)
{
	int	check_write;

	if (*count == -1)
		return ;
	check_write = write(fd, &c, 1);
	if (check_write == -1)
	{
		*count = -1;
		return ;
	}
	else
		*count += check_write;
}
