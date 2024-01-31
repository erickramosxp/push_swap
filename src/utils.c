#include "../includes/push_swap.h"

t_stk	*last(t_stk *node)
{
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
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
