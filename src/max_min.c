#include "../include/push_swap.h"

int	stack_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (i <= stack->top)
	{
		if (max < stack->array[i])
		{
			max = stack->array[i];
		}
		i++;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = INT_MAX;
	while (i <= stack->top)
	{
		if (min > stack->array[i])
		{
			min = stack->array[i];
		}
		i++;
	}
	return (min);
}
