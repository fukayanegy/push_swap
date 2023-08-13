/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:12 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/13 17:18:15 by etakaham         ###   ########.fr       */
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
		return (sort_two_b(B));
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
	if (stackA->top < 3)
		return (sort_three(stackA));
	while (stackA->top > 2)
	{
		while (stackA->array[stackA->top] > 1)
			ra(stackA);
		pb(stackA, stackB);
	}
	sort_three(stackA);
	sort_three_b(stackB);
	while (stackB->top >= 0)
		pa(stackA, stackB);
}
