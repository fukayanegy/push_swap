#include "../../include/push_swap.h"

void	ra(t_stack *stackA)
{
	shift_up(stackA);
	ft_printf("ra\n");
}

void	rb(t_stack *stackB)
{
	shift_up(stackB);
	ft_printf("rb\n");
}

void	rr(t_stack *stackA, t_stack *stackB)
{
	shift_up(stackA);
	shift_up(stackB);
	ft_printf("rr\n");
}
