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

void	sa(t_stk **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	swap(stack);
	ft_printf("sa\n");
}

void	ra(t_stk **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	pb(t_stk **stack_a, t_stk **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	rra(t_stk **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rrotate(stack_a);
	ft_printf("rra\n");
}
