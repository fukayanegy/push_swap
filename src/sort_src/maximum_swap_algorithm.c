/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_swap_algorithm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:01:36 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/13 15:33:12 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	sort_maximum_checker(t_stack *stackA, t_stack *stackB)
{
	if (is_sorted_b(stackA))
		return (false);
	if (stackA->top <= 5)
	{
		sort_five(stackA, stackB);
		return (false);
	}
	return (true);
}

static void	move_a_to_b(t_stack *A, t_stack *B, int q, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < q * 2)
		{
			if (A->top < 0)
				break ;
			while (!is_in_range(A->array[A->top], q * (i + 0), q * (i + 2)))
				ra(A);
			pb(A, B);
			if (is_in_range(B->array[B->top], q * (i + 0), q * (i + 1)))
				rb(B);
			j++;
		}
		i += 2;
	}
}

static void	push_with_in_range(t_stack *A, t_stack *B, int range1, int range2)
{
	int	j;
	int	move_count;

	j = 0;
	while (is_in_range(B->array[B->top], range1, range2) && B->top > 0)
	{
		move_count = 0;
		while (B->array[B->top] != stack_max(B) && B->top > 0)
		{
			rb(B);
			move_count++;
		}
		pa(A, B);
		while (move_count && B->top > 0)
		{
			rrb(B);
			move_count--;
			if (B->array[B->top] == stack_max(B))
				pa(A, B);
		}
	}
}

static void	move_b_to_a(t_stack *A, t_stack *B, int q, int size)
{
	int	i;
	int	j;
	int	k;
	int	move_count;

	i = 0;
	while (i < size)
	{
		push_with_in_range(A, B, q * (size - i), q * (size - i - 1));
		k = 0;
		while (k < q)
		{
			rrb(B);
			k++;
		}
		push_with_in_range(A, B, q * (size - i - 1), q * (size - i - 2));
		i++;
		i++;
	}
}

void	sort_maximum2(t_stack *stackA, t_stack *stackB)
{
	int	chunk_quantity;
	int	step_size;

	if (!sort_maximum_checker(stackA, stackB))
		return ;
	chunk_quantity = 1;
	step_size = 1;
	compute_chunk(stackA, &step_size, &chunk_quantity);
	move_a_to_b(stackA, stackB, chunk_quantity, step_size);
	move_b_to_a(stackA, stackB, chunk_quantity, step_size);
	pa(stackA, stackB);
}
