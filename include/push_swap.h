#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
#include<stdio.h>

typedef struct s_stack
{
	int		top;
	size_t	size;
	int		*array;
}			t_stack;

// move_element.c
void	push_other(t_stack *stackA, t_stack *stackB);
void	shift_up(t_stack *stack);
void	shift_down(t_stack *stack);
void	swap(t_stack *stack);
// stack_maker.c
t_stack	*create_stack(size_t size);
void	push(t_stack *stack, int value);
// main.c
void	stack_free(t_stack *stackA, t_stack *stackB);
void 	print_stack(t_stack *stack);
// checker.c
bool	is_overlap(t_stack *stackA);
bool	is_error(int argc, char **argv);
// sort_algo
bool	is_sortedA(t_stack *stackA);
bool	is_sortedB(t_stack *stackB);
void	sort_two(t_stack *stackA);
void	sort_three(t_stack *stackA);
void	sort_five(t_stack *stackA, t_stack *stackB);
// maximum_swap_algo
void	sort_maximum(t_stack *stackA, t_stack *stackB);
// middle.c
void	ft_sort(int *array, int top);
int		ft_median(t_stack *stackA);
// max_min.c
int	stack_max(t_stack *stack);
int	stack_min(t_stack *stack);
// commond
void	sa(t_stack *stackA);
void	sb(t_stack *stackB);
void	ss(t_stack *stackA, t_stack *stackB);

void	pa(t_stack *stackA, t_stack *stackB);
void	pb(t_stack *stackA, t_stack *stackB);

void	ra(t_stack *stackA);
void	rb(t_stack *stackB);
void	rr(t_stack *stackA, t_stack *stackB);

void	rra(t_stack *stackA);
void	rrb(t_stack *stackB);
void	rrr(t_stack *stackA, t_stack *stackB);

#endif
