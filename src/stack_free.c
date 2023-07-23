#include "../include/push_swap.h"

void	stack_free(t_stack *stackA, t_stack *stackB)
{
	free(stackA->array);
	free(stackA);
	free(stackB->array);
	free(stackB);
}
