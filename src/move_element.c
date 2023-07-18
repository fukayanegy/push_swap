#include "../include/push_swap.h"

// shifting stackA`s top element to stackB`s top element
void	move_to_stack(t_stack *stackA, t_stack *stackB)
{
	int	value;

	if (stackA->top == -1)
		return ;
	value = stackA->array[stackA->top];
	stackA->top--;
	push(stackB, value);
}

// changeing stack first to stack last
// 1 2 3 4 5 to 5 1 2 3 4
void	shift_elements(t_stack *stack)
{
	int	first;
	int	i;

	if (stack->top < 1)
		return ;
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
// 1 2 3 4 5 to 2 3 4 5 1
void	reverse_shift_elements(t_stack *stack)
{
	int	last;
	int	i;

	if (stack->top < 1)
		return ;
	last = stack->array[0];
	i = 0;
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = last;
}
