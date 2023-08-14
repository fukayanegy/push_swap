/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:35 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 12:13:36 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *stackA)
{
	shift_up(stackA);
	ft_printf("ra\n");
}

void	rb(t_stack *stackB)
{
	shift_up(stackB);
	ft_printf("rb\n");
}

void	rr(t_stack *stackA, t_stack *stackB)
{
	shift_up(stackA);
	shift_up(stackB);
	ft_printf("rr\n");
}
