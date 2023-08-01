#include "../include/push_swap.h"

// shifting stackA`s top element to stackB`s top element
void	push_other(t_stack *stackA, t_stack *stackB)
{
	int	value;

	value = stackA->array[stackA->top];
	stackA->top--;
	push(stackB, value);
}

// changeing stack first to stack last
// 1 to 2
// 2 to 3
// 3 to 1
void	shift_up(t_stack *stack)
{
	int	first;
	int	i;

	// error
	if (stack->top < 1)
		return ;
	// copy
	first = stack->array[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = first;
}

// changeing stack last to stack first
// 1 to 3
// 2 to 1
// 3 to 2
void	shift_down(t_stack *stack)
{
	int	last;
	int	i;

	// error
	if (stack->top < 1)
		return ;
	// copy
	last = stack->array[0];
	i = 0;
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = last;
}

// 1 to 2
// 2 to 1
// 3 to 3
// 4 to 4
void	swap(t_stack *stack)
{
	int	tmp;

	// error
	if (stack->top < 1)
		return ;
	tmp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = tmp;
}
