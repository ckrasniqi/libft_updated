/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:06:15 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/31 13:09:34 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *prefix, char const *suffix);
size_t	ft_strlen(const char *c);
char	*ft_gnl_strchr(char *str, char c);
char	*ft_strdup(const char *src);
void	*ft_memmove(void *dst, const void *src, size_t n);

#endif
