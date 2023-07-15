#include "test.h"

t_stack *create_stack(size_t size)
{
	t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(size * sizeof(int));
	if (stack->array == NULL)
	{
		exit(EXIT_FAILURE);
	}
	return stack;
}

void push(t_stack *stack, int value)
{
	if (stack->top == (int)stack->size - 1)
	{
		fprintf(stderr, "stack is full\n");
		return;
	}

	stack->top++;
	stack->array[stack->top] = value;
}

void print_stack(t_stack *stack)
{
	printf("stack: ");
	for (int i = stack->top; i >= 0; i--)
	{
		printf("%d ", stack->array[i]);
	}
	printf("\n");
}

void swap(t_stack *stack)
{
	if (stack->top < 1)
	{
		return;
	}
	int temp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = temp;
}

void move_to_stack(t_stack *stackA, t_stack *stackB)
{
	if (stackA->top == -1)
	{
		return;
	}

	int value = stackA->array[stackA->top];
	stackA->top--;

	push(stackB, value);
}

void shift_elements(t_stack *stack)
{
	if (stack->top < 1)
	{
		return;
	}
	int first = stack->array[stack->top];
	for (int i = stack->top; i > 0; i--)
	{
		stack->array[i] = stack->array[i - 1];
	}
	stack->array[0] = first;
}

void reverse_shift_elements(t_stack *stack)
{
	if (stack->top < 1)
	{
		fprintf(stderr, "スタックには2つ以上の要素が必要です\n");
		return;
	}

	int last = stack->array[0];
	for (int i = 0; i < stack->top; i++)
	{
		stack->array[i] = stack->array[i + 1];
	}
	stack->array[stack->top] = last;
}
