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
	int	n;
	stk *temp;

	if (stackB == NULL)
		return ;
	
	n = stackA->x;
	temp = stackB;
	while (stackB->next != NULL)
		stackB = stackB->next;
	stackB->next = (stk *)malloc(sizeof(stk));
	stackB->next->next = NULL;
	stackB = temp;
	while (stackB->next != NULL)
	{
		n = stackB->next-x;
		stackB->next-x = stackB->x;
	}

	 = temp->x;


}*/

void	rotate(stk *stack)
{
	int	n;

	n = stack->x;
	while (stack->next != NULL)
	{
		stack->x = stack->next->x;
		stack = stack->next;
	}
	stack->x = n;
}

void	rrotate(stk *stack)
{
	stk *head;
	int	n;

	head = stack;
	n = stack->x;
	while (stack->next != NULL)
	{
		n = stack->next->x;
		stack->next->x = n;
		stack = stack->next;
	}
	stack->x = n;
}

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

void sort_tree(stk *stackA)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if ((stackA->x > stackA->next->x) && (stackA->x > stackA->next->next->x))
		{
			rotate(stackA);
			write(1, "ra\n", 3);
		}
		if ((stackA->x > stackA->next->x) || (stackA->next->x > stackA->next->next->x))
		{
			swap(stackA);
			write(1, "sa\n", 3);
		}
		i++;
	}
}
/*
void sort_five(stk *stackA, stk *stackB)
{

}
*/

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
	return (1);
}
int	main(int argc, char **argv)
{	
	int	i;
	stk	*stackA = NULL;
	stk	*stackB = NULL;
	stk *head;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split((const char *)argv[1], ' ');
		i = 0;
	}
	if (!check_args(argv, i))
		return (0);
	stackA = malloc(sizeof(stk));
	stackA->next = NULL;
	head = stackA;
	stackB = malloc(sizeof(stk));
	stackB->next = NULL;
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

	stackA = head;
//	sort_tree(stackA);
	rotate(stackA);
//	swap(stackA);
	print_list(stackA);
	ft_printf("\n");
//	print_list(stackB);
	free_list(stackA);
	free_list(stackB);
	return (0);
}