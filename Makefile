# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yez-zain <yezzainabi@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/20 17:28:20 by yez-zain          #+#    #+#              #
#    Updated: 2018/11/02 00:08:16 by llachgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = validate.c tools.c main.c ft_sqrt.c fillit.c GNL/get_next_line.c
OBJ = *.o
LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)
clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
