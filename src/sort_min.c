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
	{
		rrotate(stack_a);
		write(1, "rra\n", 4);
	}
	if (((*stack_a)->x > (*stack_a)->next->x)
		&& ((*stack_a)->x > (*stack_a)->next->next->x))
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if ((*stack_a)->x > (*stack_a)->next->x
		&& (*stack_a)->x < (*stack_a)->next->next->x)
	{
			swap(stack_a);
			write(1, "sa\n", 3);
	}
}

/*
void	sort_five(t_stk *stack_a, t_stk *stack_b)
{
}
*/
