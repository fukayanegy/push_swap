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

bool	is_error(int argc, char **argv, char **argv_cpy)
{
	int	i;
	int	j;

	if (argc <= 1)
		return (true);
	else if (argc == 2)
	{
		return (is_error_double_quotation(argc, argv, argv_cpy));
	}
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
	argv_cpy = malloc(sizeof(argv));
	ft_memcpy(argv_cpy, &argv[1], sizeof(argv));
	return (false);
}

bool	is_error_double_quotation(int argc, char **argv, char **argv_cpy)
{
	int	i = argc;
	int	j;

	if (ft_strchr(argv[1], ' ') == NULL)
		return (true);
	argv_cpy = ft_split(argv[1], ' ');
	i = 0;
	while (argv_cpy[i] != NULL)
	{
		j = 0;
		while (argv_cpy[i][j] != '\0')
		{
			if (!ft_isdigit(argv_cpy[i][j]))
			{
				free(argv_cpy);
				return (true);
			}
			j++;
		}
		i++;
	}
	printf("=====is_error=====\n");
	for (int k = 0; argv_cpy[k] != NULL; k++)
	{
		printf("%s\n", argv_cpy[k]);
	}
	printf("==================\n");
	return (false);
}
