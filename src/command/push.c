#include "../../include/push_swap.h"

void	pa(t_stack *stackA, t_stack *stackB)
{
	push_other(stackB, stackA);
	ft_printf("pa\n");
}

void	pb(t_stack *stackA, t_stack *stackB)
{
	push_other(stackA, stackB);
	ft_printf("pb\n");
}
