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
//STEP_SIZE
void	sort_maximum(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	j;

	if (is_sortedB(stackA))
		return ;
	if (stackA->top <= 5)
		return (sort_five(stackA, stackB));
	i = 0;
	j = stack_max(stackA);
	while (i <= j)
	{
		while (i != stackA->array[stackA->top])
		{
			ra(stackA);
		}
		pb(stackA, stackB);
		i++;
	}
	i = 0;
	while (i <= j)
	{
		pa(stackA, stackB);
		i++;
	}
}

void	quick_sort(t_stack *stackA, t_stack *stackB)
{
	int	i;
	int	j;
	int	median;

	if (is_sortedB(stackA))
		return ;
	while (stackA->top < 3)
	{
		i = 0;
		// jは要素数
		j = stackA->top;
		// 中央値で分ける
		while (i <= j)
		{
			median = ft_median(stackA);
			while (stackA->array[stackA->top] > median)
			{
				ra(stackA);
			}
			pb(stackA, stackB);
			i++;
		}
	}
	i = 0;
	while (i <= j)
	{
		pa(stackA, stackB);
		i++;
	}
}
