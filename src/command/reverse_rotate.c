/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:32 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 12:13:33 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *stackA)
{
	shift_down(stackA);
	ft_printf("rra\n");
}

void	rrb(t_stack *stackB)
{
	shift_down(stackB);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stackA, t_stack *stackB)
{
	shift_down(stackA);
	shift_down(stackB);
	ft_printf("rrr\n");
}
