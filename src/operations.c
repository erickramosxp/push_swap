/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:47:15 by erramos           #+#    #+#             */
/*   Updated: 2024/02/02 19:47:17 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stk **stack)
{
	t_stk	*head;
	t_stk	*second;

	head = *stack;
	second = head->next;

	head->next = head->next->next;
	second->next = head;
	*stack = second;
}
void	push(t_stk **stack_a, t_stk **stack_b)
{
	t_stk	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	rotate(t_stk **stack)
{
	t_stk	*tail;

	if (*stack == NULL)
		return ;
	tail = *stack;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = *stack;
	*stack = (*stack)->next;
	tail->next->next = NULL;
}

void	rrotate(t_stk **stack)
{
	t_stk	*last;
	t_stk	*temp;

	temp = *stack;
	last = last_node(temp);
	last->next = temp;
	temp->previous = last;

	last->previous->next = NULL;
	last->previous = NULL;
	*stack = last;
}
