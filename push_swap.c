/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:44:28 by erramos           #+#    #+#             */
/*   Updated: 2024/01/17 16:18:34 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	stk	*stack = NULL;
	stk	*head = NULL;

	i = 1;
	if (argc > 0)
	{
		stack = malloc(sizeof(stk));
		head = stack;
		if (!stack)
			exit(1);
		while (argv[i])
		{
			stack->x = ft_atoi(argv[i]);
			stack->next = malloc(sizeof(stk));
			if (!stack)
				exit(1);
			stack = stack->next;
			i++;
		}

	}
	while (head)
	{
		ft_printf("%d", head->x);
		head = head->next;
	}
	return (0);
}
