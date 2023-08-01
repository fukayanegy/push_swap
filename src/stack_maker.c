#include "../include/push_swap.h"

/*
 * create_stack is function geting stack mamory to malloc and defining top and size
 * push if function defining stack array is value
 * */

t_stack	*create_stack(size_t size)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(size * sizeof(int));
	if (stack->array == NULL)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

void	push(t_stack *stack, int value)
{
	if (stack->top == (int)stack->size - 1)
		return ;
	stack->top++;
	stack->array[stack->top] = value;
}

bool	create_double_stack(size_t size, t_stack **A, t_stack **B)
{
	*A = create_stack(size);
	if (*A == NULL)
		return (false);
	*B = create_stack(size);
	if (*B == NULL)
	{
		free(*A);
		return (false);
	}
	return (true);
}
