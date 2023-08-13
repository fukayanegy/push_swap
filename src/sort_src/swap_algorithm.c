/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:12 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/13 15:35:27 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_two(t_stack *stackA)
{
	if (is_sorted_b(stackA) || stackA->top != 1)
		return ;
	else
		sa(stackA);
}

void	sort_two_b(t_stack *stackB)
{
	if (is_sorted_a(stackB) || stackB->top != 1)
		return ;
	else
		sb(stackB);
}

void	sort_three(t_stack *A)
{
	if (A->top < 2)
		return (sort_two(A));
	if (is_sorted_b(A))
		return ;
	else if (A->array[2] < A->array[0] && A->array[0] < A->array[1])
	{
		rra(A);
		sa(A);
	}
	else if (A->array[1] < A->array[2] && A->array[2] < A->array[0])
		sa(A);
	else if (A->array[0] < A->array[2] && A->array[2] < A->array[1])
		rra(A);
	else if (A->array[1] < A->array[0] && A->array[0] < A->array[2])
		ra(A);
	else if (A->array[0] < A->array[1] && A->array[1] < A->array[2])
	{
		ra(A);
		sa(A);
	}
}

void	sort_three_b(t_stack *B)
{
	if (B->top < 2)
		return (sort_two(B));
	if (is_sorted_a(B))
		return ;
	else if (B->array[2] > B->array[0] && B->array[0] > B->array[1])
	{
		rrb(B);
		sb(B);
	}
	else if (B->array[1] > B->array[2] && B->array[2] > B->array[0])
		sb(B);
	else if (B->array[0] > B->array[2] && B->array[2] > B->array[1])
		rrb(B);
	else if (B->array[1] > B->array[0] && B->array[0] > B->array[2])
		rb(B);
	else if (B->array[0] > B->array[1] && B->array[1] > B->array[2])
	{
		rb(B);
		sb(B);
	}
}

void	sort_five(t_stack *stackA, t_stack *stackB)
{
	int	median;
	int	i;
	int	b_max;

	if (stackA->top < 3)
		return (sort_three(stackA));
	median = ft_median(stackA);
	i = 0;
	while (i < median - 1)
	{
		if (stackA->array[stackA->top] < median)
		{
			pb(stackA, stackB);
			i++;
		}
		else
			ra(stackA);
	}
	sort_three(stackA);
	sort_three_b(stackB);
	while (stackB->top >= 0)
	{
		b_max = stack_max(stackB);
		while (stackB->array[stackB->top] != b_max)
			rb(stackB);
		pa(stackA, stackB);
	}
}
