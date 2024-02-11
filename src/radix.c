/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:52:03 by erramos           #+#    #+#             */
/*   Updated: 2024/02/10 11:52:06 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	radix_sort(t_stk **stack_a, t_stk **stack_b)
{
	int		max_bits;
	int		i;
	int		size_list;

	i = 0;
	max_bits = count_max_of_bits(index_max(*stack_a));
	while (i < max_bits)
	{
		size_list = list_size(*stack_a);
		while (size_list)
		{
			if ((((*stack_a)->index >> i) & 0b0000001) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			size_list--;
		}
		while (*stack_b != NULL)
			pa(stack_b, stack_a);
		i++;
	}
}
