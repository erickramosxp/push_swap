#include "checker.h"

void	ss_checker(t_stk **stack_a, t_stk **stack_b)
{
	if ((*stack_a == NULL || (*stack_a)->next == NULL)
		&& (*stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	swap(stack_a);
	swap(stack_b);
}

void	rr_checker(t_stk **stack_a, t_stk **stack_b)
{
	if ((*stack_a == NULL || (*stack_a)->next == NULL)
		&& (*stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	rotate(stack_a);
	rotate(stack_b);
}

void	rrr_checker(t_stk **stack_a, t_stk **stack_b)
{
	if ((*stack_a == NULL || (*stack_a)->next == NULL)
		&& (*stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	rrotate(stack_a);
	rrotate(stack_b);
}
