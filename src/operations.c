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

	head->previous = second;
	head->next = second->next;

	if (second->next != NULL)
		second->next->previous = head;
	second->next = head;
	second->previous = NULL;
	*stack = second;
}

void	push(t_stk **stack_a, t_stk **stack_b)
{
	t_stk	*temp;
	t_stk	*head;

	if (*stack_a == NULL)
		return ;

	head = *stack_a;
	temp = head->next;

	if (temp != NULL)
		temp->previous = NULL;

	head->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = head;
	head->previous = NULL;

	*stack_a = temp;
	*stack_b = head;
}

void	rotate(t_stk **stack)
{
	t_stk	*temp;
	t_stk	*tail;
	t_stk	*head;

	if (*stack == NULL)
		return ;
	temp = *stack;
	head = *stack;
	tail = last_node(temp);
	tail->next = head;
	head->next->previous = NULL;
	temp = head->next;
	head->previous = tail;
	head->next = NULL;
	*stack = temp;
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
