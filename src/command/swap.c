/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:13:38 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 12:13:39 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *stackA)
{
	swap(stackA);
	ft_printf("sa\n");
}

void	sb(t_stack *stackB)
{
	swap(stackB);
	ft_printf("sb\n");
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	swap(stackA);
	swap(stackB);
	ft_printf("ss\n");
}
