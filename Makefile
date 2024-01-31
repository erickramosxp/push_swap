# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erramos <erramos@student.42.rio>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:38:34 by erramos           #+#    #+#              #
#    Updated: 2024/01/17 15:55:21 by erramos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMELIB = push_swap.a
FLAGS = -Wall -Wextra -Werror
UTILS = ./src/*.c

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./libft/ft_printf/
	$(MAKE) -C ./libft/
	cc $(FLAGS) -c $(UTILS)
	mv ./*.o ./src
	ar -r ./libft/libft.a ./libft/ft_printf/*.o ./src/*.o
	cp ./libft/libft.a ./
	mv libft.a $(NAMELIB)
	cc $(FLAGS) push_swap.c $(NAMELIB) -o push_swap

clean:
	$(MAKE) clean -C ./libft/ft_printf/
	$(MAKE) clean -C ./libft/
	rm ./src/*.o

fclean: clean
	$(MAKE) fclean -C ./libft/ft_printf/
	$(MAKE) fclean -C ./libft/
	rm -rf $(NAMELIB) push_swap

re:	fclean all
