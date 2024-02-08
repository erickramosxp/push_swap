#include "../includes/push_swap.h"

void	sa(t_stk **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stk **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_stk **stack_a, t_stk **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	pa(t_stk **stack_a, t_stk **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stk **stack_a, t_stk **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	ra(t_stk **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stk **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stk **stack_a, t_stk **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	rra(t_stk **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stk **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stk **stack_a, t_stk **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
