/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:00:59 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:07:55 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Free a string
 * Free a variable of two-dimensional array of type char obtained by split(),etc
 * @param strings Target two-dimensional array
*/
void	free_strings(char **strings)
{
	int	len;

	len = 0;
	while (strings[len])
	{
		free(strings[len]);
		len++;
	}
	free(strings);
}
