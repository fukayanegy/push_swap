#include "../../include/push_swap.h"

void	sa(t_stack *stackA)
{
	swap(stackA);
	ft_printf("sa\n");
}

void	sb(t_stack *stackB)
{
	swap(stackB);
	ft_printf("sb\n");
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	swap(stackA);
	swap(stackB);
	ft_printf("ss\n");
}
