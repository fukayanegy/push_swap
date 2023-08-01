#include "../include/push_swap.h"

// sort perfect
// 1 2 3 4 5
bool	is_sortedA(t_stack *stackA)
{
	int	i;

	i = 0;
	while (i < stackA->top)
	{
		if (stackA->array[i] > stackA->array[i + 1])
		{
			return (false);
		}
		i++;
	}
	return (true);
}

// sort perfect
// 5 4 3 2 1
bool	is_sortedB(t_stack *stackB)
{
	int	i;

	i = 0;
	while (i < stackB->top)
	{
		if (stackB->array[i] < stackB->array[i + 1])
		{
			return (false);
		}
		i++;
	}
	return (true);
}

void	sort_two(t_stack *stackA)
{
	if (is_sortedB(stackA) || stackA->top != 1)
	{
		return ;
	}
	else
		sa(stackA);
}

void	sort_three(t_stack *stackA)
{
	if (stackA->top < 2)
		return (sort_two(stackA));
	// 1 2 3
	if (is_sortedB(stackA))
		return ;
	// 1 3 2
	else if (stackA->array[2] < stackA->array[0] && stackA->array[0] < stackA->array[1])
	{
		// ra sa rra
		ra(stackA);
		sa(stackA);
		rra(stackA);
	}
	// 2 1 3
	else if (stackA->array[1] < stackA->array[2] && stackA->array[2] < stackA->array[0])
	{
		// sa
		sa(stackA);
	}
	// 2 3 1
	else if (stackA->array[0] < stackA->array[2] && stackA->array[2] < stackA->array[1])
	{
		// rra
		rra(stackA);
	}
	// 3 1 2
	else if (stackA->array[1] < stackA->array[0] && stackA->array[0] < stackA->array[2])
	{
		// ra
		ra(stackA);
	}
	// 3 2 1
	else if (stackA->array[0] < stackA->array[1] && stackA->array[1] < stackA->array[2])
	{
		// sa ra ra
		sa(stackA);
		ra(stackA);
		ra(stackA);
	}
}

void	sort_five(t_stack *stackA, t_stack *stackB)
{
	int	median;
	int	i;
	int	B_max;

	if (stackA->top < 3)
		return (sort_three(stackA));
	median = ft_median(stackA);
	i = 0;
	while (i < median - 1)
	{
		if (stackA->array[stackA->top] < median)
		{
			pb(stackA, stackB);
			i++;
		}
		else
			ra(stackA);
	}
	sort_three(stackA);
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
