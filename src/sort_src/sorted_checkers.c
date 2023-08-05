/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:09:30 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:10:14 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_sortedA(t_stack *stackA)
{
	int	i;

	i = 0;
	while (i < stackA->top)
	{
		if (stackA->array[i] > stackA->array[i + 1])
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_sortedB(t_stack *stackB)
{
	int	i;

	i = 0;
	while (i < stackB->top)
	{
		if (stackB->array[i] < stackB->array[i + 1])
		{
			return (false);
		}
		i++;
	}
	return (true);
}