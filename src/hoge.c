#include "../include/push_swap.h"

bool	hoge(int argc, char **argv, t_stack *stackA)
{
	int		i;
	int		j;
	// int		k;
	int		value;
	char	**argv_cpy;

	value = 0;
	if (argc < 1)
		return (false);
	else if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ') == NULL)
			return (false);
		else
		{
			argv_cpy = ft_split(argv[1], ' ');
			i = 0;
			while (argv_cpy[i] != NULL)
				i++;
			// k = 0;
			// while (k < i)
			// {
			// 	j = 0;
			// 	while (argv_cpy[k][j] != '\0')
			// 	{
			// 		if (!ft_isdigit(argv_cpy[k][j]))
			// 		{
			// 			return (false);
			// 		}
			// 		j++;
			// 	}
			// 	k++;
			// }
			i = 0;
			while (argv_cpy[i] != NULL)
				i++;
			while (i)
			{
				if (!ft_atoi_push_swap(argv_cpy[i - 1], &value))
				{
					return (false);
				}
				push(stackA, value);
				i--;
			}
			free(argv_cpy);
			return (true);
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (!ft_isdigit(argv[i][j]))
				{
					return (false);
				}
				j++;
			}
			i++;
		}
		i = argc;
		while (i > 1)
		{
			value = ft_atoi(argv[i - 1]);
			push(stackA, value);
			i--;
		}
		return (true);
	}
}