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

bool	is_in_range(int n, int min, int max);
int		compute_sqrt(int n);
void	compute_chunk(t_stack *stackA, int *step_size, int *chunk_quantity);
void	ft_sort(int *array, int size);
int	*copy_int_array(int *int_array, int size);
void	free_strings(char **strings);
// tester
void print_stack(t_stack *stack);
// src
bool	is_correct_2argu(char *argument, int *array_size);
bool	is_correct_argu(int argc, char **argv, int *array_size);
bool	ft_atoi_push_swap(const char *str, int *n);
int		*coordinate_compression(int *array, int size);
void	ft_sort(int *array, int size);
t_stack	*create_stack(size_t size);
void	push(t_stack *stack, int value);
bool	create_double_stack(size_t size, t_stack **A, t_stack **B);
bool	array_storage(int argc, char **argv, t_stack *A, int size);
// move_element.c
void	push_other(t_stack *stackA, t_stack *stackB);
void	shift_up(t_stack *stack);
void	shift_down(t_stack *stack);
void	swap(t_stack *stack);
// sort_algo
bool	is_sorted_a(t_stack *stackA);
bool	is_sorted_b(t_stack *stackB);
void	sort_two(t_stack *stackA);
void	sort_three(t_stack *stackA);
void	sort_three_b(t_stack *stackB);
void	sort_five(t_stack *stackA, t_stack *stackB);
// maximum_swap_algo
void	sort_maximum(t_stack *stackA, t_stack *stackB);
void	sort_maximum2(t_stack *stackA, t_stack *stackB);
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

bool	is_overlap(int *array, int size);
void	stack_free(t_stack *stackA, t_stack *stackB);

#endif
