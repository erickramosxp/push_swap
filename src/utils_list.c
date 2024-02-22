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

int	check_list_sorted(t_stk *list)
{
	t_stk	*temp;

	temp = list;
	while (temp->next != NULL)
	{
		if (temp->x > temp->next->x)
			return (0);
		temp = temp->next;
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
		nb = 2147483647;
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
