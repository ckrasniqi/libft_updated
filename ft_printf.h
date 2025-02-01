/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:43:21 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/31 13:05:38 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa_long(unsigned int n);
char	*ft_itoa(int n);
void	ft_print_hex_l(unsigned int num, int *count);
void	ft_print_hex_u(unsigned int num, int *count);
void	ft_print_long(unsigned int n, int *count);
void	ft_print_nbr(int n, int *count);
void	ft_print_ptr(void *ptr, int *count);
int		ft_printf(const char *format, ...);
void	ft_printf_putchar_fd(char c, int fd, int *count);
void	ft_printf_putstr_fd(char *s, int *count);
size_t	ft_strlen(const char *c);

#endif
