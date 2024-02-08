/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:47:27 by erramos           #+#    #+#             */
/*   Updated: 2024/02/02 19:47:29 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	t_stk *temp;

	temp = list;
	while (temp)
	{
		if (temp->x > temp->next->x)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_sorted(char **numbrs, int i, int fix)
{
	while (fix < i)
	{
		if (ft_atoi(numbrs[i - 1]) > ft_atoi(numbrs[i]))
			return (0);
		i--;
	}
	return (1);
}
