
#include "checker.h"

void    execute_move(char *operation, t_stk **stack_a, t_stk **stack_b)
{
    while (operation != NULL)
    {
        if(!ft_strncmp(operation, "sa\n", ft_strlen(operation)))
            sa(stack_a);
        else if(!ft_strncmp(operation, "sb\n", ft_strlen(operation)))
            sb(stack_b);
        else if(!ft_strncmp(operation, "ss\n", ft_strlen(operation)))
            ss(stack_a, stack_b);
        else if(!ft_strncmp(operation, "pa\n", ft_strlen(operation)))
            pa(stack_a, stack_b);
        else if(!ft_strncmp(operation, "pb\n", ft_strlen(operation)))
            pb(stack_a, stack_b);
        else if(!ft_strncmp(operation, "ra\n", ft_strlen(operation)))
            ra(stack_a);
        else if(!ft_strncmp(operation, "rb\n", ft_strlen(operation)))
            rb(stack_b);
        else if(!ft_strncmp(operation, "rr\n", ft_strlen(operation)))
            rr(stack_a, stack_b);
        else if(!ft_strncmp(operation, "rra\n", ft_strlen(operation)))
            rra(stack_a);
        else if(!ft_strncmp(operation, "rrb\n", ft_strlen(operation)))
            rrb(stack_b);
        else if(!ft_strncmp(operation, "rrr", ft_strlen(operation)))
            rrr(stack_a, stack_b);
        operation = get_next_line(0);
    }
}

void    executer_operations(t_stk **stack_a, t_stk **stack_b)
{
    char    *operation;

    operation = get_next_line(0);
    execute_move(operation, stack_a, stack_b);
    ft_printf("%s", operation);

}

int main(int argc, char **argv)
{
    int     i;
	t_stk	*stack_a;
	t_stk	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split((const char *)argv[1], ' ');
		i = 0;
	}
	if (!check_args(argv, i))
	{
		if (i == 0)
			free_args(argv);
		return (0);
	}
	fill_list(&stack_a, argv, i, i);
    executer_operations(&stack_a, &stack_b);
    print_list(stack_a);
	free_list(stack_a);
}