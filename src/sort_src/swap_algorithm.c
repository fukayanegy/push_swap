/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:12 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 18:13:58 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_two(t_stack *stackA)
{
	if (is_sortedB(stackA) || stackA->top != 1)
		return ;
	else
		sa(stackA);
}

void	sort_two_b(t_stack *stackB)
{
	if (is_sortedA(stackB) || stackB->top != 1)
		return ;
	else
		sb(stackB);
}

void	sort_three(t_stack *stackA)
{
	if (stackA->top < 2)
		return (sort_two(stackA));
	if (is_sortedB(stackA))
		return ;
	else if (stackA->array[2] < stackA->array[0] && stackA->array[0] < stackA->array[1])
	{
		rra(stackA);
		sa(stackA);
	}
	else if (stackA->array[1] < stackA->array[2] && stackA->array[2] < stackA->array[0])
		sa(stackA);
	else if (stackA->array[0] < stackA->array[2] && stackA->array[2] < stackA->array[1])
		rra(stackA);
	else if (stackA->array[1] < stackA->array[0] && stackA->array[0] < stackA->array[2])
		ra(stackA);
	else if (stackA->array[0] < stackA->array[1] && stackA->array[1] < stackA->array[2])
	{
		ra(stackA);
		sa(stackA);
	}
}

void	sort_three_b(t_stack *stackB)
{
	if (stackB->top < 2)
		return (sort_two(stackB));
	if (is_sortedA(stackB))
		return ;
	else if (stackB->array[2] > stackB->array[0] && stackB->array[0] > stackB->array[1])
	{
		rrb(stackB);
		sb(stackB);
	}
	else if (stackB->array[1] > stackB->array[2] && stackB->array[2] > stackB->array[0])
		sb(stackB);
	else if (stackB->array[0] > stackB->array[2] && stackB->array[2] > stackB->array[1])
		rrb(stackB);
	else if (stackB->array[1] > stackB->array[0] && stackB->array[0] > stackB->array[2])
		rb(stackB);
	else if (stackB->array[0] > stackB->array[1] && stackB->array[1] > stackB->array[2])
	{
		rb(stackB);
		sb(stackB);
	}
}

void	sort_five(t_stack *stackA, t_stack *stackB)
{
	int	median;
	int	i;
	int	B_max;

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
		B_max = stack_max(stackB);
		while (stackB->array[stackB->top] != B_max)
		{
			rb(stackB);
		}
		pa(stackA, stackB);
	}
}
