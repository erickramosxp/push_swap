/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:47:07 by erramos           #+#    #+#             */
/*   Updated: 2024/02/17 17:55:04 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	ft_printf("Error\n");
	return (1);
}

int	check_repeat(char **numbrs, int i)
{
	int	nb;
	int	j;

	while (numbrs[i + 1])
	{
		nb = ft_atoi(numbrs[i]);
		j = i + 1;
		while (numbrs[j])
		{
			if (nb == ft_atoi(numbrs[j]))
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_max_and_min(char **numbrs, int fix)
{
	long long	nb;

	while (numbrs[fix])
	{
		nb = ft_atoi(numbrs[fix]);
		if (nb < INT_MIN || nb > INT_MAX)
		{
			ft_printf("Error\n");
			return (1);
		}
		fix++;
	}
	return (0);
}

int	check_digit(char **numbrs, int fix)
{
	int	i;
	int	j;

	i = fix;
	j = 0;
	while (numbrs[i])
	{
		j = 0;
		while (numbrs[i][j] || j == 0)
		{
			if (numbrs[i][j] == '-' || numbrs[i][j] == '+')
				j++;
			if (!ft_isdigit(numbrs[i][j]))
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **numbrs, int i)
{
	if (check_digit(numbrs, i))
		return (0);
	if (check_repeat(numbrs, i))
		return (0);
	if (check_max_and_min(numbrs, i))
		return (0);
	return (1);
}
