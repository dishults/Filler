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

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = lib/ft_atoii.c \
	lib/ft_isasciii.c \
	lib/ft_isdigitt.c \
	lib/ft_isprintt.c \
	lib/ft_memallocc.c \
	lib/ft_nbrconvert_base.c \
	lib/ft_putnbr_base.c \
	lib/ft_putnbrr.c \
	lib/ft_putstrr.c \
	lib/ft_strchr_no_zero.c \
	lib/ft_strlenn.c \
	lib/ft_strndupp.c \
	plib/ft_co_get_var_size.c \
	plib/ft_convsp_char.c \
	plib/ft_convsp_num.c \
	plib/ft_num_funcs.c \
	plib/ft_num_o_u_x_p.c \
	plib/ft_p_flags.c \
	plib/ft_p_length.c \
	plib/ft_p_width_precision.c \
	ft_printf.c

OBJ	= $(addprefix .//,$(SRC:.c=.o))

INC = -I ./

all: $(NAME)

%.o: %.c
	@clang $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)

clean:
	@rm -rf $(SRC:.c=.o)

fclean: clean
	@rm -rf $(NAME)

re: fclean all