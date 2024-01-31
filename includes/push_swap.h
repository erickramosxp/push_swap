/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:31:45 by erramos           #+#    #+#             */
/*   Updated: 2024/01/17 17:43:11 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				x;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stk;

int					check_repeat(char **numbrs, int i);
int					check_max_and_min(char **numbrs, int fix);
int					check_args(char **numbrs, int i);

void				print_list(t_stk *list);
int					list_size(t_stk *list);
void				free_list(t_stk *list);
int					check_sorted(char **numbrs, int i, int fix);
t_stk				*last(t_stk *node);

void				sort_two(t_stk *stack_a);
void				sort_tree(t_stk **stack_a);
// void	sort_five(t_t_stk *stack_a, t_t_stk *stack_b);

void				swap(t_stk **stack);
void				push(t_stk **stack_a, t_stk **stack_b);
void				rotate(t_stk **stack);
void				rrotate(t_stk **stack);

#endif
