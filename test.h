#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		top;
	size_t	size;
	int		*array;
}			t_stack;

t_stack *create_stack(size_t size);
void push(t_stack *stack, int value);
void swap(t_stack *stack);
void move_to_stack(t_stack *stackA, t_stack *stackB);
void print_stack(t_stack *stack);
void shift_elements(t_stack *stack);
void reverse_shift_elements(t_stack *stack);
#endif