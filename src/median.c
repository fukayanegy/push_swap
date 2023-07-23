#include "../include/push_swap.h"

void	ft_sort(int *array, int top)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i <= top)
	{
		j = i + 1;
		while (j <= top)
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

// seach median
int	ft_median(t_stack *stack)
{
	int	*array_cpy;
	int	size;
	int	i;

	array_cpy = (int *)malloc(sizeof(int) * (stack->top + 1));
	size = stack->top + 1;
	i = 0;
	while (i < size)
	{
		array_cpy[i] = stack->array[i];
		i++;
	}
	ft_sort(array_cpy, stack->top);
	if (size % 2 == 0)
		return (array_cpy[size / 2 - 1] + array_cpy[size / 2]) / 2;
	else
		return (array_cpy[size / 2]);
}
