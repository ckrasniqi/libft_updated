/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:06:18 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 19:20:54 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len >= ft_gnl_strlen(s) - start)
		len = ft_gnl_strlen(s) - start;
	if (ft_gnl_strlen(s) <= start)
		return (ft_gnl_strdup(""));
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*erase_oneline(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	temp = malloc(((ft_gnl_strlen(buffer) - i) + 1) * sizeof(char));
	if (!temp)
		return (free(buffer), NULL);
	i++;
	while (buffer[i] != '\0')
		temp[j++] = buffer[i++];
	temp[j] = '\0';
	free(buffer);
	return (temp);
}

char	*save_oneline(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	temp = ft_gnl_substr(buffer, 0, i + 1);
	if (temp == NULL)
		return (NULL);
	return (temp);
}

char	*read_and_save(int fd, char *buffer)
{
	char	buffer_2[BUFFER_SIZE + 1];
	int		check_read;
	char	*new_line;

	check_read = 1;
	while (check_read > 0)
	{
		check_read = read(fd, buffer_2, BUFFER_SIZE);
		if (check_read == -1 || (check_read == 0 && buffer == NULL))
			return (free(buffer), NULL);
		buffer_2[check_read] = '\0';
		new_line = ft_gnl_strjoin(buffer, buffer_2);
		free(buffer);
		if (!new_line)
			return (NULL);
		buffer = new_line;
		if (ft_gnl_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = NULL;
	buffer = read_and_save(fd, buffer);
	if (!buffer)
		return (NULL);
	line = save_oneline(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = erase_oneline(buffer);
	return (line);
}
