/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_int_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:15:33 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:07:47 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Create a copy of the array
 * Takes an array of type int, allocates memory and makes a copy
 * @param int_array Array to copy
 * @param size Length of array
 * @return Length of the copied array
*/
int	*copy_int_array(int *int_array, int size)
{
	int	*result;

	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, int_array, sizeof(int) * size);
	return (result);
}
