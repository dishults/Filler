# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshults <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 18:34:55 by dshults           #+#    #+#              #
#    Updated: 2017/11/14 18:34:57 by dshults          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_count_char.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_malloc_xy.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line/get_next_line.c

OBJ	= $(addprefix .//,$(SRC:.c=.o))

INC = -I ./

all: prntf $(NAME)

%.o: %.c
	@clang $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

prntf:
	@$(MAKE) -C ft_printf all

clean:
	@rm -rf $(SRC:.c=.o)
	@$(MAKE) -C ft_printf clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C ft_printf fclean

re: fclean all




