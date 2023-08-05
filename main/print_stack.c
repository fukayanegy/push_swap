#include "../include/push_swap.h"

void print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		ft_printf("%d ", stack->array[i]);
		i++;
	}
	ft_printf("\n");
}
