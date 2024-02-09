/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:47:22 by erramos           #+#    #+#             */
/*   Updated: 2024/02/02 19:47:24 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tree(t_stk **stack_a)
{
	if (((*stack_a)->next->x > (*stack_a)->x)
		&& ((*stack_a)->next->x > (*stack_a)->next->next->x))
		rra(stack_a);
	if (((*stack_a)->x > (*stack_a)->next->x)
		&& ((*stack_a)->x > (*stack_a)->next->next->x))
		ra(stack_a);
	if ((*stack_a)->x > (*stack_a)->next->x
		&& (*stack_a)->x < (*stack_a)->next->next->x)
			sa(stack_a);
}

void		sort_four(t_stk **stack_a, t_stk **stack_b)
{
	int		param;
	int		size_list;

	int		count;
	t_stk	*temp;
	t_stk	*n_small;

	temp = *stack_a;
	size_list = list_size(*stack_a);
	param = size_list / 2;
	count = 0;
	n_small = small_node(*stack_a);
	while (temp != n_small)
	{
		count++;
		temp = temp->next;
	}
	if (count < param)
	{
		while (*stack_a != n_small)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != n_small)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_tree(stack_a);
	pa(stack_b, stack_a);
}

void		sort_five(t_stk **stack_a, t_stk **stack_b)
{
	int		param;
	int		size_list;

	int		count;
	t_stk	*temp;
	t_stk	*n_small;

	temp = *stack_a;
	size_list = list_size(*stack_a);
	param = size_list / 2;
	count = 0;
	n_small = small_node(*stack_a);
	while (temp != n_small)
	{
		count++;
		temp = temp->next;
	}
	if (count < param)
	{
		while (*stack_a != n_small)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != n_small)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}

