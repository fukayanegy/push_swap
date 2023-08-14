/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:29 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 12:13:30 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *stackA, t_stack *stackB)
{
	push_other(stackB, stackA);
	ft_printf("pa\n");
}

void	pb(t_stack *stackA, t_stack *stackB)
{
	push_other(stackA, stackB);
	ft_printf("pb\n");
}
