#include "checker.h"

void	sa_checker(t_stk **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	swap(stack);
}

void	ra_checker(t_stk **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rotate(stack_a);
}

void	pb_checker(t_stk **stack_a, t_stk **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_a, stack_b);
}

void	rra_checker(t_stk **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rrotate(stack_a);
}
