/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/02/02 19:47:27 by erramos           #+#    #+#             */
/*   Updated: 2024/02/02 19:47:29 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stk	*small_node(t_stk *stack)
{
	t_stk	*temp;
	t_stk	*n_small;
	int		small;

	temp = stack;
	small = list_size(stack);
	while (temp)
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

int	index_max(t_stk *stake)
{
	t_stk	*temp;
	int		max;

	max = -1;
	temp = stake;
	while (temp)
	{
		if (max < temp->index)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	count_max_of_bits(int nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		count++;
		nb = nb >> 1;
	}
	return (count);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

t_stk	*last_node(t_stk *node)
{
	t_stk	*temp;

	temp = node;
	if (temp == NULL)
		return (temp);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}

void	print_list(t_stk *list)
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

int	list_size(t_stk *list)
{
	int		count;
	t_stk	*temp;

	temp = list;
	if (temp == NULL)
		return (0);
	count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	free_list(t_stk *list)
{
	t_stk	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

int	check_list_sorted(t_stk *list)
{
	t_stk	*temp;

	temp = list;
	while (temp)
	{
		if (temp->x > temp->next->x)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_sorted(char **numbrs, int i)
{
	int	qtd_arg;

	qtd_arg = 0;
	while (numbrs[qtd_arg])
		qtd_arg++;
	while (i < (qtd_arg - 1))
	{
		if (ft_atoi(numbrs[i]) > ft_atoi(numbrs[i + 1]))
			return (0);
		i++;
	}
	return (1);
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

void	fill_list(t_stk **stack, char **nbs, int fix, int split)
{
	t_stk	*temp;
	t_stk	*head;
	t_stk	*prev;

	head = NULL;
	prev = NULL;
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
	if (split == 0)
		free_args(nbs);
	*stack = head;
}
