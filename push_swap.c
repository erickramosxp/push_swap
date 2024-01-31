/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:44:28 by erramos           #+#    #+#             */
/*   Updated: 2024/01/17 17:42:55 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
void	ft_sort_stake(t_stk **stack_a, t_stk **stack_b)
{
}
*/
int	main(int argc, char **argv)
{
	int		i;
	t_stk	*stack_a;
	t_stk	*stack_b;
	t_stk	*head;

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
	if (!check_args(argv, i))
		return (0);
	stack_a = malloc(sizeof(t_stk));
	if (!stack_a)
		exit(1);
	stack_a->next = NULL;
	head = stack_a;
	stack_b = malloc(sizeof(t_stk));
	stack_b = NULL;
	ft_printf("\n");
	while (argv[i])
	{
		stack_a->x = ft_atoi(argv[i]);
		if (argv[i + 1])
			stack_a->next = malloc(sizeof(t_stk));
		else
			stack_a->next = NULL;
		if (!stack_a)
			exit(1);
		stack_a = stack_a->next;
		i++;
	}
	stack_a = head;

	if (list_size(stack_a) == 2)
	{
		swap(&stack_a);
		write(1, "sa", 2);
	}
	if (list_size(stack_a) == 3)
		sort_tree(&stack_a);

	ft_printf("\nstack A: \n");
	print_list(stack_a);

	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
