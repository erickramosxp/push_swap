/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:52:22 by erramos           #+#    #+#             */
/*   Updated: 2024/02/10 11:52:25 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_stk **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	swap(stack);
	ft_printf("sb\n");
}

void	rb(t_stk **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	pa(t_stk **stack_a, t_stk **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	rrb(t_stk **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rrotate(stack_b);
	ft_printf("rrb\n");
}
