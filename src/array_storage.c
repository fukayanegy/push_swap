#include "../include/push_swap.h"

bool	array_storage(int argc, char **argv, t_stack *A, int size)
{
	int		*tmp;
	char	**argv_cpy;
	int		i;

	tmp = malloc(sizeof(int) * size);
	if (argc == 1)
	{
		argv_cpy = ft_split(argv[0], ' ');
		i = 0;
		while (argv_cpy[i])
		{
			ft_atoi_push_swap(argv_cpy[i], &tmp[i]);
			i++;
		}
		i = 0;
		while (argv_cpy[i])
		{
			free(argv_cpy[i]);
			i++;
		}
		free(argv_cpy);
	}
	else
	{
		i = 0;
		while (i < size)
		{
			ft_atoi_push_swap(argv[i], &tmp[i]);
			i++;
		}
	}
	if (is_overlap(tmp, size))
	{
		free(tmp);
		return (false);
	}
	coordinate_compression(tmp, size);
	i = size;
	while (i != 0)
	{
		push(A, tmp[i - 1]);
		i--;
	}
	free(tmp);
	return (true);
}
