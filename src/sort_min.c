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
		rra(stack_a);
	if (((*stack_a)->x > (*stack_a)->next->x)
		&& ((*stack_a)->x > (*stack_a)->next->next->x))
		ra(stack_a);
	if ((*stack_a)->x > (*stack_a)->next->x
		&& (*stack_a)->x < (*stack_a)->next->next->x)
			sa(stack_a);
}

