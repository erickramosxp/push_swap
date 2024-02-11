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

void	ss(t_stk **stack_a, t_stk **stack_b)
{
	if ((*stack_a == NULL || (*stack_a)->next == NULL) 
		&& (*stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	rr(t_stk **stack_a, t_stk **stack_b)
{
	if ((*stack_a == NULL || (*stack_a)->next == NULL) 
		&& (*stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rrr(t_stk **stack_a, t_stk **stack_b)
{
	if ((*stack_a == NULL || (*stack_a)->next == NULL) 
		&& (*stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
