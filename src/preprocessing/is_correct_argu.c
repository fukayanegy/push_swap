/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_argu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:00:30 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/13 16:44:59 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	__quoted_array_checker(char **checker_array, int *array_size)
{
	int	i;
	int	tmp_number;

	if (checker_array == NULL)
		return (true);
	if (checker_array[0] == NULL)
		return (true);
	i = 0;
	while (checker_array[i] != NULL)
	{
		if (!ft_atoi_push_swap(checker_array[i], &tmp_number))
		{
			return (false);
		}
		i++;
	}
	*array_size = i;
	return (true);
}

static bool	__is_correct_quoted_string(char *argument, int *array_size)
{
	int		tmp_number;
	char	**checker_array;

	if (ft_atoi_push_swap(argument, &tmp_number))
	{
		*array_size = 1;
		return (true);
	}
	else
	{
		checker_array = ft_split(argument, ' ');
		if (!__quoted_array_checker(checker_array, array_size))
		{
			free_strings(checker_array);
			return (false);
		}
		free_strings(checker_array);
		return (true);
	}
}

bool	is_correct_argu(int argc, char **argv, int *array_size)
{
	int	i;
	int	tmp_number;

	if (argc < 1)
		return (true);
	else if (argc == 1)
	{
		if (__is_correct_quoted_string(argv[0], array_size))
			return (true);
		else
			return (false);
	}
	i = 0;
	while (i < argc)
	{
		if (!ft_atoi_push_swap(argv[i], &tmp_number))
			return (false);
		i++;
	}
	*array_size = i;
	return (true);
}
