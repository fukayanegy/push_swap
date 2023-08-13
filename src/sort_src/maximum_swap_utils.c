/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:12:11 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/13 14:15:34 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Determine if a number is within a range
 * @param n Number to be determined
 * @param min Out of range if less than this argument
 * @param max Out of range if greater than or equal to this argument
 * @return True if the number is within the range
*/
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
 * example) 1 2 3 4 / 5 6 7 8 / 9 10 11 12 / 13 14 15 16 / 17 18 19 20 / 21 22
 * @param stackA
 * @param step_size example) 6
 * @param chunk_quantity example) 4
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
