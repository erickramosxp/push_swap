/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:18:11 by erramos           #+#    #+#             */
/*   Updated: 2024/02/17 15:18:33 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execute_move(char *operation, t_stk **stack_a, t_stk **stack_b)
{
	if (!ft_strncmp(operation, "sa\n", ft_strlen(operation)))
		sa_checker(stack_a);
	else if (!ft_strncmp(operation, "sb\n", ft_strlen(operation)))
		sb_checker(stack_b);
	else if (!ft_strncmp(operation, "ss\n", ft_strlen(operation)))
		ss_checker(stack_a, stack_b);
	else if (!ft_strncmp(operation, "pa\n", ft_strlen(operation)))
		pa_checker(stack_b, stack_a);
	else if (!ft_strncmp(operation, "pb\n", ft_strlen(operation)))
		pb_checker(stack_a, stack_b);
	else if (!ft_strncmp(operation, "ra\n", ft_strlen(operation)))
		ra_checker(stack_a);
	else if (!ft_strncmp(operation, "rb\n", ft_strlen(operation)))
		rb_checker(stack_b);
	else if (!ft_strncmp(operation, "rr\n", ft_strlen(operation)))
		rr_checker(stack_a, stack_b);
	else if (!ft_strncmp(operation, "rra\n", ft_strlen(operation)))
		rra_checker(stack_a);
	else if (!ft_strncmp(operation, "rrb\n", ft_strlen(operation)))
		rrb_checker(stack_b);
	else if (!ft_strncmp(operation, "rrr\n", ft_strlen(operation)))
		rrr_checker(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	executer_operations(t_stk **stack_a, t_stk **stack_b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		execute_move(operation, stack_a, stack_b);
		operation = get_next_line(0);
	}
}

void	verif_args_if_split(char **argv, int i)
{
	if (!check_args(argv, i))
	{
		if (i == 0)
			free_args(argv);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stk	*stack_a;
	t_stk	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split((const char *)argv[1], ' ');
		i = 0;
	}
	verif_args_if_split(argv, i);
	fill_list(&stack_a, argv, i, i);
	executer_operations(&stack_a, &stack_b);
	if (check_list_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(stack_a);
}
