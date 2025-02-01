/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:56:57 by ckrasniq          #+#    #+#             */
/*   Updated: 2024/11/22 19:06:03 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_digits(char *array)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(array) - 1;
	while (i < j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
}

void	create_digit_array(int n, int len, char *array)
{
	int	neg;
	int	i;

	neg = 0;
	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		neg = 1;
	}
	while (i < len)
	{
		array[i] = (n % 10 + '0');
		n = n / 10;
		i++;
	}
	if (neg == 1)
	{
		array[i] = '-';
		i++;
	}
}

int	count_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * (-1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		bytes;
	int		digit_len;

	digit_len = count_len(n);
	bytes = 0;
	if (n < 0)
		bytes++;
	array = (char *)ft_calloc(digit_len + bytes + 1, sizeof(char));
	if (!array)
		return (NULL);
	create_digit_array(n, digit_len, array);
	reverse_digits(array);
	return (array);
}
