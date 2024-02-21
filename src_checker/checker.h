

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"
# include "./get_next_line/get_next_line.h"

void	sa_checker(t_stk **stack);
void	ra_checker(t_stk **stack_a);
void	pb_checker(t_stk **stack_a, t_stk **stack_b);
void	rra_checker(t_stk **stack_a);
void	sb_checker(t_stk **stack);
void	rb_checker(t_stk **stack_b);
void	pa_checker(t_stk **stack_a, t_stk **stack_b);
void	rrb_checker(t_stk **stack_b);
void	ss_checker(t_stk **stack_a, t_stk **stack_b);
void	rr_checker(t_stk **stack_a, t_stk **stack_b);
void	rrr_checker(t_stk **stack_a, t_stk **stack_b);

#endif