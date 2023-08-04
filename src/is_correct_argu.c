#include "../include/push_swap.h"

bool	is_correct_2argu(char *argument, int *array_size)
{
	int	i;
	int	tmp_number;
	char	**checker_array;

	if (ft_atoi_push_swap(argument, &tmp_number))
	{
		*array_size = 1;
		return (true);
	}
	else
	{
		checker_array = ft_split(argument, ' ');
		if (checker_array[0] == NULL)
		{
			i = 0;
			while (checker_array[i] != NULL)
				free(checker_array[i++]);
			free(checker_array);
			return (false);
		}
		i = 0;
		while (checker_array[i] != NULL)
		{
			if (!ft_atoi_push_swap(checker_array[i], &tmp_number))
			{
				i = 0;
				while (checker_array[i] != NULL)
					free(checker_array[i++]);
				free(checker_array);
				return (false);
			}
			i++;
		}
		*array_size = i;
		i = 0;
		while (checker_array[i] != NULL)
			free(checker_array[i++]);
		free(checker_array);
		return (true);
	}
}

bool	is_correct_argu(int argc, char **argv, int *array_size)
{
	int	i;
	int	tmp_number;

	if (argc < 1)
		return (false);
	else if (argc == 1)
	{
		if (is_correct_2argu(argv[0], array_size))
			return (true);
		else
			return (false);
	}
	i = 0;
	while (i < argc)
	{
		if (!ft_atoi_push_swap(argv[i], &tmp_number))
			return (false);
		i++;
	}
	*array_size = i;

	return (true);
}
