/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:04:02 by ckrasniq          #+#    #+#             */
/*   Updated: 2024/11/22 19:04:02 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *ptr, int i, size_t n)
{
	unsigned char	*str;

	str = ptr;
	while (n--)
	{
		*str++ = (unsigned char)i;
	}
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', total_size);
	return (ptr);
}
