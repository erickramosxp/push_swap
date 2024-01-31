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
	t_stk	*temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->next->next->next = NULL;
	*stack = temp;
}
