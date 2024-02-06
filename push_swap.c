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
        temp->x = atoi(nbs[fix]);
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
    *stack = head;
}

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
//	t_stk	*head;

	stack_a = NULL;
	stack_b = NULL;
//	head = NULL;
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
/*	if (list_size(stack_a) == 2)
	{
		swap(&stack_a);
		ft_printf("sa");
	}
	else if (list_size(stack_a) == 3)
		sort_tree(&stack_a);
	else if (list_size(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
*/
	ft_printf("\nstack A: \n");
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
