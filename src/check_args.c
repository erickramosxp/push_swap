#include "../includes/push_swap.h"

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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_max_and_min(char **numbrs, int fix)
{
	long	nb;
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
	int	fix;
	int	j;

	fix = i;
	while (numbrs[i])
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
