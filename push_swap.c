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

void	swap(stk **stack)
{
	stk    *head;
	int    n;

	head = (*stack);
	n = head->x;
	head->x = (*stack)->next->x;
	(*stack)->next->x = n;
}

stk *last(stk *node)
{
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

void	push(stk **stackA, stk **stackB)
{
	stk *temp;

	if (*stackA == NULL)
		return ;
	temp = *stackA;

	*stackA = (*stackA)->next;
	temp->next = *stackB;
	*stackB = temp;
//	(*stackB)->next = NULL;
}

void rotate(stk **stack)
{
	stk *tail;

    if (*stack == NULL) {
		return ;
	}
	tail = *stack;
    while (tail->next != NULL) {
        tail = tail->next;
	}
	tail->next = *stack;
    *stack = (*stack)->next;
    tail->next->next = NULL;
}

void	rrotate(stk **stack)
{
	stk *temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->next->next->next = NULL;
	*stack = temp;
}

void	print_list(stk *list)
{
	if (list == NULL)
		return ;
	while (list)
	{
		ft_printf("%d", list->x);
		list = list->next;
		if (list)
			ft_printf(" ");
	}
}

int list_size(stk *list)
{
	int count;
	stk *temp;

	temp = list;
/*	if (temp == NULL)
		return (0);*/
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
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

int check_repeat(char **numbrs, int i)
{
	int nb;
	int j;
	while (numbrs[i + 1])
	{
		nb = ft_atoi(numbrs[i]);
		j = i + 1;
		while (numbrs[j])
		{
			if (nb == ft_atoi(numbrs[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_sorted(char **numbrs, int i, int fix)
{
	while ( fix < i )
	{
		if (ft_atoi(numbrs[i - 1]) > ft_atoi(numbrs[i]))
			return(0);
		i--;
	}
	return (1);
}

void sort_two(stk *stackA)
{
	int nb;

	nb = stackA->next->x;
	stackA->next->x = stackA->x;
	stackA->x = nb;
}

void sort_tree(stk **stackA)
{

		if (((*stackA)->x > (*stackA)->next->x) || ((*stackA)->next->x > (*stackA)->next->next->x))
		{
			swap(stackA);
			write(1, "sa\n", 3);
		}
		if (((*stackA)->x > (*stackA)->next->x) && ((*stackA)->x > (*stackA)->next->next->x))
		{
			rrotate(stackA);
			write(1, "rra\n", 4);
		}
}
/*
void sort_five(stk *stackA, stk *stackB)
{

}
*/

int	check_max_and_min(char **numbrs, int fix)
{
	long nb;//
	while (numbrs[fix])
	{
		nb = ft_atoi(numbrs[fix]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (1);
		fix++;
	}
	return (0);
}

int	check_args(char **numbrs, int i)
{
	int fix;
	int j;

	fix = i;
	while(numbrs[i])
	{
		j = 0;
		while (numbrs[i][j])
		{
			if (numbrs[i][j] == '-' || numbrs[i][j] == '+')
				j++;
			if (!ft_isdigit(numbrs[i][j]))
			{
				ft_printf("Um dos valores não é um digito.");
				return (0);
			}
			j++;
		}
		i++;
	}
	i--;
	if (check_sorted(numbrs, i, fix))
	{
		ft_printf("Os valores já estão ordenados");
		return (0);
	}
	if (check_repeat(numbrs, fix))
	{
		ft_printf("Existe valores iguais.");
		return (0);
	}
	if (check_max_and_min(numbrs, fix))
	{
		ft_printf("Número maior que o maximo inteiro o menor que o minimo inteiro.");
		return (0);
	}
	return (1);
}
/*
void	ft_sort_stake(stk **stackA, stk **stackB)
{
	
}
*/
int	main(int argc, char **argv)
{	
	int	i;
	stk	*stackA = NULL;
	stk	*stackB = NULL;
	stk *head;

	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split((const char *)argv[1], ' ');
		i = 0;
	}
	if (!check_args(argv, i))
		return (0);
	stackA = malloc(sizeof(stk));
	if (!stackA)
		exit(1);
	stackA->next = NULL;
	head = stackA;
	stackB = malloc(sizeof(stk));
	stackB = NULL;
	ft_printf("\n");
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
	stackA = head;


	if (list_size(stackA) == 2)
	{
		swap(&stackA);
		write (1, "sa", 2);
	}
	if (list_size(stackA) == 3)
		sort_tree(&stackA);


	ft_printf("\nstack A: \n");
	print_list(stackA);

	free_list(stackA);
	free_list(stackB);
	return (0);
}