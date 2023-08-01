#include "../include/push_swap.h"

void	ft_sort(int *array, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*coordinate_compression(int *array, int size)
{
	int	*result;
	int	*array_cpy;
	int	i;
	int	j;

	result = malloc(sizeof(int) * size);
	array_cpy = malloc(sizeof(int) * size);
	ft_memcpy(result, array, sizeof(int) * size);
	ft_memcpy(array_cpy, array, sizeof(int) * size);
	ft_sort(result, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array_cpy[j] == result[i])
			{
				array[j] = i;
			}
			j++;
		}
		i++;
	}
	free(result);
	free(array_cpy);
	return (array);
}
