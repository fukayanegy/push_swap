/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:02:04 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:08:18 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	stack_free(t_stack *stackA, t_stack *stackB)
{
	free(stackA->array);
	free(stackA);
	free(stackB->array);
	free(stackB);
}
