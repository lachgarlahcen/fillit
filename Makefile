# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 17:28:20 by yez-zain          #+#    #+#              #
#    Updated: 2018/11/02 00:08:16 by llachgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = *.c GNL/get_next_line.c
OBJ = *.o
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)
clean:
	@/bin/rm -f *.o
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
