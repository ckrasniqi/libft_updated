/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:34:46 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/02/06 19:58:23 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// get_next_line

char				*get_next_line(int fd);
char				*ft_gnl_strjoin(char const *prefix, char const *suffix);
size_t				ft_gnl_strlen(const char *c);
char				*ft_gnl_strchr(char *str, char c);
char				*ft_gnl_strdup(const char *src);
void				*ft_gnl_memmove(void *dst, const void *src, size_t n);

// ft_printf

void				*ft_calloc(size_t count, size_t size);
char				*ft_itoa_long(unsigned int n);
char				*ft_itoa(int n);
void				ft_print_hex_l(unsigned int num, int *count);
void				ft_print_hex_u(unsigned int num, int *count);
void				ft_print_long(unsigned int n, int *count);
void				ft_print_nbr(int n, int *count);
void				ft_print_ptr(void *ptr, int *count);
int					ft_printf(const char *format, ...);
void				ft_printf_putchar_fd(char c, int fd, int *count);
void				ft_printf_putstr_fd(char *s, int *count);
size_t				ft_strlen(const char *c);

// Libft

int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);
void				*ft_memset(void *ptr, int i, size_t n);
size_t				ft_strlen(const char *c);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// Bonus
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
