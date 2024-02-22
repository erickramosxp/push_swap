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
SRCS =	check_args.c \
	execute_operations_b.c \
	operations.c \
	radix.c \
	utils.c \
	execute_operations_a.c \
	execute_operations_both.c \
	push_swap.c \
	sort_min.c \
	utils_list.c
UTILS = $(addprefix src/, $(SRCS))
SRCS_CHECKER =	checker.c\
				utils_commands_a.c\
				utils_commands_b.c\
				utils_commands_both.c
SRCS_GNL =	get_next_line.c\
			get_next_line_utils.c
DIRGNL = $(addprefix get_next_line/, $(SRCS_GNL))

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./libft/ft_printf/
	$(MAKE) -C ./libft/
	cc $(FLAGS) -c $(UTILS)
	mv $(SRCS:.c=.o) ./src
	ar -r ./libft/libft.a ./libft/ft_printf/*.o $(UTILS:.c=.o)
	cp ./libft/libft.a ./
	mv libft.a $(NAMELIB)
	cc $(FLAGS) ./src/push_swap.c $(NAMELIB) -o push_swap
	mv $(NAMELIB) ./src

checker: $(NAME)
	cc $(FLAGS) $(addprefix src_checker/, $(SRCS_CHECKER)) $(addprefix src_checker/, $(DIRGNL)) src/$(NAMELIB) -o checker

clean:
	$(MAKE) clean -C ./libft/ft_printf/
	$(MAKE) clean -C ./libft/
	rm -rf $(UTILS:.c=.o)

fclean: clean
	$(MAKE) fclean -C ./libft/ft_printf/
	$(MAKE) fclean -C ./libft/
	rm -rf $(addprefix src/, $(NAMELIB)) push_swap checker

re:	fclean all
