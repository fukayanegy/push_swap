/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:25 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 12:14:48 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_other(t_stack *stackA, t_stack *stackB)
{
	int	value;

	value = stackA->array[stackA->top];
	stackA->top--;
	push(stackB, value);
}

void	shift_up(t_stack *stack)
{
	int	first;
	int	i;

	if (stack->top < 1)
		return ;
	first = stack->array[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = first;
}

void	shift_down(t_stack *stack)
{
	int	last;
	int	i;

	if (stack->top < 1)
		return ;
	last = stack->array[0];
	i = 0;
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = last;
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top < 1)
		return ;
	tmp = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = tmp;
}
