/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:26:02 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/13 17:28:04 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		array_size;
	t_stack	*a;
	t_stack	*b;

	array_size = 0;
	if (!is_correct_argu(argc - 1, &argv[1], &array_size))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!create_double_stack(array_size, &a, &b))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!array_storage(argc - 1, &argv[1], a, array_size))
	{
		ft_printf("Error\n");
		return (0);
	}
	sort_maximum(a, b);
	return (0);
}
