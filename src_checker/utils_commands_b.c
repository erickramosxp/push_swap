#include "checker.h"

void	sb_checker(t_stk **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	swap(stack);
}

void	pa_checker(t_stk **stack_a, t_stk **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
}

void	rrb_checker(t_stk **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rrotate(stack_b);
}

void	rb_checker(t_stk **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_b);
}
