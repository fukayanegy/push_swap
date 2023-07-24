#include "../include/push_swap.h"

bool	is_overlap(t_stack *stackA)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stackA->top)
	{
		j = 0;
		while (j < i)
		{
			if (stackA->array[i] == stackA->array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_error(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		return (true);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
