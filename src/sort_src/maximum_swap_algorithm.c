/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_swap_algorithm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:01:36 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 18:41:43 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_in_range(int n, int min, int max)
{
	int	tmp;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	if (min <= n && n < max)
		return (true);
	else
		return (false);
}

/**
 * Find the square root
 * @param n number
 * @return square result
*/
int	compute_sqrt(int n)
{
	int	result;

	result = 0;
	if (n < 1)
		return (result);
	while (result * result < n)
	{
		result++;
	}
	return (result - 1);
}

/**
 * Calculate how many elements are to be divided
 * 1 2 3 4 / 5 6 7 8 / 9 10 11 12 / 13 14 15 16 / 17 18 19 20 / 21 22
 * @param stackA
 * @param step_size 6
 * @param chunk_quantity 4
*/
void	compute_chunk(t_stack *stackA, int *step_size, int *chunk_quantity)
{
	int	top_sqrt;

	top_sqrt = compute_sqrt(stackA->top);
	*chunk_quantity = stackA->top / top_sqrt;
	*step_size = stackA->top / *chunk_quantity;
	if (stackA->top / *chunk_quantity != 0)
		*step_size = *step_size + 1;
	if (*step_size % 2 == 1)
	{
		while (*step_size % 2 == 1)
		{
			*chunk_quantity = *chunk_quantity + 1;
			*step_size = stackA->top / *chunk_quantity;
			if (stackA->top / *chunk_quantity != 0)
				*step_size = *step_size + 1;
		}
	}
}

void	sort_maximum2(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	j;
	int	k;
	int	move_count;
	int	chunk_quantity;
	int	step_size;

	if (is_sortedB(stackA))
		return ;
	if (stackA->top <= 5)
		return (sort_five(stackA, stackB));
	chunk_quantity = 1;
	step_size = 1;
	compute_chunk(stackA, &step_size, &chunk_quantity);
	i = 0;
	while (i < step_size)
	{
		j = 0;
		while (j < chunk_quantity * 2)
		{
			if (stackA->top < 0)
				break ;
			while (!is_in_range(stackA->array[stackA->top], chunk_quantity * i, chunk_quantity * (i + 2)))
				ra(stackA);
			if (is_in_range(stackA->array[stackA->top], chunk_quantity * i, chunk_quantity * (i + 1)))
			{
				pb(stackA, stackB);
				rb(stackB);
			}
			else if (is_in_range(stackA->array[stackA->top], chunk_quantity * (i + 1), chunk_quantity * (i + 2)))
			{
				pb(stackA, stackB);
			}
			j++;
		}
		i++;
		i++;
	}
	i = 0;
	while (i < step_size)
	{
		j = 0;
		while (is_in_range(stackB->array[stackB->top], chunk_quantity * (step_size - i), chunk_quantity * (step_size - i - 1)) && stackB->top > 0)
		{
			move_count = 0;
			while (stackB->array[stackB->top] != stack_max(stackB) && stackB->top > 0)
			{
				rb(stackB);
				move_count++;
			}
			pa(stackA, stackB);
			while (move_count && stackB->top > 0)
			{
				rrb(stackB);
				move_count--;
				if (stackB->array[stackB->top] == stack_max(stackB))
					pa(stackA, stackB);
			}
		}
		k = 0;
		while (k < chunk_quantity)
		{
			rrb(stackB);
			k++;
		}
		while (is_in_range(stackB->array[stackB->top], chunk_quantity * (step_size - i - 1), chunk_quantity * (step_size - i - 2)) && stackB->top > 0)
		{
			move_count = 0;
			while (stackB->array[stackB->top] != stack_max(stackB) && stackB->top > 0)
			{
				rb(stackB);
				move_count++;
			}
			pa(stackA, stackB);
			while (move_count && stackB->top > 0)
			{
				rrb(stackB);
				move_count--;
				if (stackB->array[stackB->top] == stack_max(stackB))
					pa(stackA, stackB);
			}
		}
		i++;
		i++;
	}
	pa(stackA, stackB);
}
