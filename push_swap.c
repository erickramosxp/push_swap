/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:44:28 by erramos           #+#    #+#             */
/*   Updated: 2024/01/17 17:42:55 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap(stk *stack)
{
	stk    *head;
	int    n;

	head = stack;
	n = head->x;
	head->x = stack->next->x;
	stack->next->x = n;
}
/*
void	push(stk *stackA, stk *stackB)
{
	

}
*/
void	rotate(stk *stack)
{
	int	n;
	stk *head;

	head = stack;
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	n = stack->x;
	stack->x = head->x;
	head->x = n;
}
/*
void	reverse_rotate(stk *stack)
{

}
*/

void	print_list(stk *list)
{
	while (list)
	{
		ft_printf("%d", list->x);
		list = list->next;
		if (list)
			ft_printf(" ");
	}
}

void	free_list(stk *list)
{
	stk *temp;
	while(list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}
int	main(int argc, char **argv)
{	
	int	i;
	stk	*stackA = NULL;
	stk	*stackB = NULL;
	stk *head;

	i = 1;
	stackB = malloc(sizeof(stk));
	stackB->next = NULL;
	if (argc > 0)
	{
		stackA = malloc(sizeof(stk));
		stackA->next = NULL;
		head = stackA;
		if (argc == 2)
		{
			argv = ft_split((const char *)argv[1], ' ');
			i = 0;
		}
		/*
		while (argv[i])
		{
			ft_printf("%s", argv[i]);
			i++;
		}*/

		ft_printf("\n");
		if (!stackA)
			exit(1);
		while (argv[i])
		{
			stackA->x = ft_atoi(argv[i]);
			if (argv[i + 1])
				stackA->next = malloc(sizeof(stk));
			else
				stackA->next = NULL;
			if (!stackA)
				exit(1);
			stackA = stackA->next;
			i++;
		}

	}
	stackA = head;
	rotate(stackA);
//	swap(stackA);
	print_list(stackA);
	ft_printf("\n");
	print_list(stackB);
	free_list(stackA);
	free_list(stackB);
	return (0);
}