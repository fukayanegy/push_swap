/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:14:06 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:07:40 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*coordinate_compression(int *array, int size)
{
	int	i;
	int	j;
	int	*result;
	int	*array_cpy;

	result = copy_int_array(array, size);
	array_cpy = copy_int_array(array, size);
	ft_sort(result, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			array[j] = (array_cpy[j] == result[i] ? i : array[j]);
			j++;
		}
		i++;
	}
	free(result);
	free(array_cpy);
	return (array);
}
