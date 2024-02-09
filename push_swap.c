/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:44:28 by erramos           #+#    #+#             */
/*   Updated: 2024/02/06 19:09:03 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
t_stk	*small_node_in_20(t_stk *stack)
{
	t_stk	*temp;
	t_stk	*n_small;
	int		small;
	int		count;

	temp = stack;
	count = 0;
	small = list_size(stack);
	while(temp != NULL && count < 20)
	{
		if (small > temp->index)
		{
			n_small = temp;
			small = temp->index;
		}
		count++;
		temp = temp->next;
	}
	return (n_small);
}

t_stk	*big_node(t_stk *stack)
{
	t_stk	*temp;
	t_stk	*n_big;
	int		big;

	temp = stack;
	big = 0;
	while(temp)
	{
		if (big < temp->index)
		{
			n_big = temp;
			big = temp->index;
		}
		temp = temp->next;
	}
	return (n_big);
}

void		sort_100(t_stk **stack_a, t_stk **stack_b)
{
	int		param;
	int		i;
	int		j;
	t_stk	*temp;
	t_stk	*big;
	t_stk	*small;

	i = 0;
	temp = *stack_a;
	while (i < list_size(*stack_a) && stack_a != NULL)
	{
		small = small_node_in_20(*stack_a);
		while (*stack_a != NULL && *stack_a != small)
		{
			ft_printf("|||||| COMEÇO |||||||");
			print_list(*stack_a);
				ra(stack_a);
			if (*stack_a == small)
				pb(stack_a, stack_b);
		}
		i++;
	}
	i = 0;
	print_list(*stack_b);
	while (i < 100 && stack_b != NULL)
	{
		big = big_node(*stack_b);
		param = list_size(*stack_b);
		temp = *stack_b;
		j = 0;
		ft_printf("%d", big->x);
		while (temp != big)
		{
			j++;
			temp = temp->next;
		}
		if (j < param)
		{
			while (*stack_b != big)
				ra(stack_b);
		}
		else
		{
			while (*stack_b != big)
				rra(stack_a);
		}
		pa(stack_a, stack_b);
		i++;
	}
}
*/

/*
void	print_list2(t_stk *list)
{
	if (list == NULL)
		return ;
	while (list)
	{
		ft_printf("%d", list->x);
		list = list->previous;
		if (list)
			ft_printf(" ");
	}
}
*/

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
	if (!check_args(argv, i))
	{
		if (i == 0)
			free_args(argv);
		return (0);
	}
	fill_list(&stack_a, argv, i);
	if (list_size(stack_a) == 2)
		sa(&stack_a);
	else if (list_size(stack_a) == 3)
		sort_tree(&stack_a);
	else if (list_size(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	else if (list_size(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_list(stack_a);
	if (i == 0)
		free_args(argv);
	return (0);
}
