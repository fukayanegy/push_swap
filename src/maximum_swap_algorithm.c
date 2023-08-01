#include "../include/push_swap.h"

void	sort_maximum(t_stack *stackA, t_stack *stackB)
{
	int	median;
	int	i;
	int	B_max;

	if (stackA->top < 5)
		return (sort_five(stackA, stackB));
	median = ft_median(stackA);
	i = stackA->top;
	while (i >= 0)
	{
		pb(stackA, stackB);
		i--;
	}
	while (stackB->top >= 0)
	{
		B_max = stack_max(stackB);
		while (stackB->array[stackB->top] != B_max)
		{
			rb(stackB);
		}
		pa(stackA, stackB);
	}
}
