/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:04:54 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:08:23 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*create_stack(size_t size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = -1;
	stack->size = size;
	stack->array = (int *)malloc(size * sizeof(int));
	if (stack->array == NULL)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

void	push(t_stack *stack, int value)
{
	if (stack->top == (int)stack->size - 1)
		return ;
	stack->top++;
	stack->array[stack->top] = value;
}

bool	create_double_stack(size_t size, t_stack **A, t_stack **B)
{
	*A = create_stack(size);
	if (*A == NULL)
		return (false);
	*B = create_stack(size);
	if (*B == NULL)
	{
		free(*A);
		return (false);
	}
	return (true);
}
