/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:44:28 by erramos           #+#    #+#             */
/*   Updated: 2024/02/06 19:09:03 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
void	ft_sort_stake(t_stk **stack_a, t_stk **stack
		i++;
	}
	free(args);
}

int	main(int argc, char **argv)_b)
{
}
*/

t_stk	*small_node(t_stk *stack)
{
	t_stk	*temp;
	t_stk	*n_small;
	int		small;

	temp = stack;
	small = list_size(stack);
	while(temp)
	{
		if (small > temp->index)
		{
			n_small = temp;
			small = temp->index;
		}
		temp = temp->next;
	}
	return (n_small);
}

void		sort_four(t_stk **stack_a, t_stk **stack_b)
{
	int		param;
	int		size_list;

	int		count;
	t_stk	*temp;
	t_stk	*n_small;

	temp = *stack_a;
	size_list = list_size(*stack_a);
	param = size_list / 2;
	count = 0;
	n_small = small_node(*stack_a);
	while (temp != n_small)
	{
		count++;
		temp = temp->next;
	}
	if (count < param)
	{
		while (*stack_a != n_small)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != n_small)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_tree(stack_a);
	pa(stack_b, stack_a);
}

void		sort_five(t_stk **stack_a, t_stk **stack_b)
{
	int		param;
	int		size_list;

	int		count;
	t_stk	*temp;
	t_stk	*n_small;

	temp = *stack_a;
	size_list = list_size(*stack_a);
	param = size_list / 2;
	count = 0;
	n_small = small_node(*stack_a);
	while (temp != n_small)
	{
		count++;
		temp = temp->next;
	}
	if (count < param)
	{
		while (*stack_a != n_small)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != n_small)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}


void	index_list(t_stk *stack)
{
	t_stk	*temp;
	t_stk	*small;
	int		i;
	int		size_list;
	int		nb;

	i = 0;
	size_list = list_size(stack);
	while (i < size_list)
	{
		nb = INT_MAX;
		temp = stack;
		while (temp)
		{
			if (nb >= temp->x && temp->index == -1)
			{
				small = temp;
				nb = temp->x;
			}
			temp = temp->next;
		}
		small->index = i;
		i++;
	}
}

void fill_list(t_stk **stack, char **nbs, int fix)
{
    t_stk *temp;
    t_stk *head = NULL;
    t_stk *prev = NULL;

    while (nbs[fix])
    {
        temp = malloc(sizeof(t_stk));
        if (!temp)
            exit(1);
        temp->x = ft_atoi(nbs[fix]);
		temp->index = -1;
        temp->previous = prev;
        temp->next = NULL;
        if (prev)
            prev->next = temp;
        prev = temp;
        if (!head)
            head = temp;
        fix++;
    }
	index_list(head);
    *stack = head;
}
/*
void	print_list2(t_stk *list)
{
	if (list == NULL)
		return ;
	while (list)
	{
		ft_printf("%d", list->x);
		list = list->previous;
		if (list)
			ft_printf(" ");
	}
}
*/
void	free_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stk	*stack_a;
	t_stk	*stack_b;
//	t_stk	*temp;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split((const char *)argv[1], ' ');
		i = 0;
	}
	if (!check_args(argv, i))
	{
		if (i == 0)
			free_args(argv);
		return (0);
	}
	fill_list(&stack_a, argv, i);
//	head = stack_a;
	if (list_size(stack_a) == 2)
		sa(&stack_a);
	else if (list_size(stack_a) == 3)
		sort_tree(&stack_a);
	else if (list_size(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	else if (list_size(stack_a) == 5)
		sort_five(&stack_a, &stack_b);

	ft_printf("stack A: \n");
	print_list(stack_a);

	ft_printf("\nstack B: \n");
	print_list(stack_b);
//	rrotate(&stack_a);
//	print_list2(last_node(stack_a));
	ft_printf("\n");
	free_list(stack_a);
//	free_list(stack_b);
	if (i == 0)
		free_args(argv);
	return (0);
}
