# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 16:59:12 by ckrasniq          #+#    #+#              #
#    Updated: 2025/02/01 19:25:52 by ckrasniq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =			ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c \
				ft_memcpy.c ft_itoa.c ft_strlen.c ft_strdup.c  ft_memcpy.c ft_split.c ft_atoi.c \
				ft_strjoin.c ft_strtrim.c ft_strrchr.c ft_strnstr.c ft_memmove.c ft_substr.c \
				ft_memset.c ft_calloc.c ft_strchr.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strmapi.c ft_toupper.c ft_tolower.c ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
				get_next_line.c get_next_line_utils.c ft_calloc.c ft_itoa_long.c ft_itoa.c ft_print_hex_l.c \
				ft_print_hex_u.c ft_print_long.c ft_print_nbr.c ft_print_ptr.c ft_printf.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_strlen.c \

# ---------- COLORS AND STUFF ---------- #
GREEN =  033[0;32m
RED =  033[0;31m
YELLOW =  033[0;33m
CYAN =  033[0;36m
NC =  033[0m
CLEAR_LINE =  033[2K r

TOTAL_SRCS = $(words $(SRCS))
CURRENT = 0

# Object files
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@true

# Rule to compile the main library
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Object file compilation rule
.c.o:
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)🚧 Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(CYAN)$<$(NC) 🚧"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and libraries
clean:
	@rm -f $(OBJS)

# Clean all generated files
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re