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

void	sort_two(t_stk *stack_a)
{
	int	nb;

	nb = stack_a->next->x;
	stack_a->next->x = stack_a->x;
	stack_a->x = nb;
}

void	sort_tree(t_stk **stack_a)
{
	if (((*stack_a)->next->x > (*stack_a)->x)
		&& ((*stack_a)->next->x > (*stack_a)->next->next->x))
	{
		rrotate(stack_a);
		write(1, "rra\n", 4);
	}
	if (((*stack_a)->x > (*stack_a)->next->x)
		&& ((*stack_a)->x > (*stack_a)->next->next->x))
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if ((*stack_a)->x > (*stack_a)->next->x
		&& (*stack_a)->x < (*stack_a)->next->next->x)
	{
			swap(stack_a);
			write(1, "sa\n", 3);
	}
}


void	sort_five(t_stk **stack_a, t_stk **stack_b)
{

	while (!check_list_sorted(*stack_a))
	{
		push(stack_a, stack_b);
		push(stack_a, stack_b);
		ft_printf("pb\n");
		ft_printf("pb\n");
		sort_tree(stack_a);
		push(stack_b, stack_a);
		ft_printf("pa\n");
		rotate(stack_a);
		ft_printf("ra\n");
		push(stack_b, stack_a);
	}
}
