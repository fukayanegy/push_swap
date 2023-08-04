#include "../include/push_swap.h"

void	sort_maximum(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	j;

	// is_sorted
	if (is_sortedB(stackA))
		return ;
	// if (stackA->top < 5)
	// 	return (sort_five(stackA, stackB));
	i = 0;
	j = stack_max(stackA);
	while (i <= j)
	{
		while (i != stackA->array[stackA->top])
		{
			ra(stackA);
		}
		pb(stackA, stackB);
		i++;
	}
	i = 0;
	while (i <= j)
	{
		pa(stackA, stackB);
		i++;
	}
}
