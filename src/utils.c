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
