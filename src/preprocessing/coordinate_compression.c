/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:14:06 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/13 15:48:53 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	compres_helper(int *array, int *array_cpy, int *result, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array_cpy[j] == result[i])
				array[j] = i;
			j++;
		}
		i++;
	}
}

int	*coordinate_compression(int *array, int size)
{
	int	*result;
	int	*array_cpy;

	result = copy_int_array(array, size);
	array_cpy = copy_int_array(array, size);
	ft_sort(result, size);
	compres_helper(array, array_cpy, result, size);
	free(result);
	free(array_cpy);
	return (array);
}
