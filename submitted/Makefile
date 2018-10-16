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

NAME = dshults.filler

FLAGS = -Wall -Wextra -Werror

SRC =	main.c			\
		get_map_token.c	\
		my_move.c		\
		try_place_it.c	\

OBJ	= $(addprefix .//,$(SRC:.c=.o))

INC = -I ./

LIBS = libft/libft.a libft/ft_printf/libftprintf.a

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

all: lib $(NAME)

%.o: %.c
	@clang $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	@clang $(SRC:.c=.o) $(LIBS) -o $(NAME)

lib:
	@$(MAKE) -C libft all

clean:
	@rm -rf $(SRC:.c=.o)
	@$(MAKE) -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

# remake only filler files, relink with libs and delete .o
f: fcln $(NAME)
	@echo "$(WARN_COLOR)\c"
	rm -rf $(SRC:.c=.o)
	@echo "$(NO_COLOR)\c"

%.o: %.c
	@echo "$(COM_COLOR)\c"
	clang $(FLAGS) $(INC) -o $@ -c $<
	@echo "$(NO_COLOR)\c"

$(NAME): $(OBJ)

fcln: 
	@echo "$(WARN_COLOR)\c"
	rm -rf $(NAME)
	@echo "$(NO_COLOR)\c"
