/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:06:20 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/31 13:09:15 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	char	*array;
	size_t	prefixlength;
	size_t	suffixlength;
	size_t	i;

	prefixlength = ft_strlen(prefix);
	suffixlength = ft_strlen(suffix);
	i = 0;
	array = (char *)malloc(prefixlength + suffixlength + 1);
	if (array == NULL)
		return (NULL);
	while (i < (prefixlength))
	{
		array[i] = prefix[i];
		i++;
	}
	while (i < (prefixlength + suffixlength))
	{
		array[i] = suffix[i - prefixlength];
		i++;
	}
	array[i] = '\0';
	return (array);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*ptr1;
	const char	*ptr2;

	ptr1 = dst;
	ptr2 = src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (n--)
			*ptr1++ = *ptr2++;
	}
	else
	{
		while (n--)
			ptr1[n] = ptr2[n];
	}
	return (dst);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*array;

	i = ft_strlen(src);
	array = (char *)malloc(sizeof(char) * (i + 1));
	if (array == NULL)
		return (NULL);
	ft_memmove(array, src, i + 1);
	array[i] = '\0';
	return (array);
}
