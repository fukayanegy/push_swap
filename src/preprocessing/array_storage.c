/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_storage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:48:03 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:07:27 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	__partition_and_store_text(char *argv_one, int *tmp)
{
	int		i;
	char	**argv_cpy;

	argv_cpy = ft_split(argv_one, ' ');
	i = 0;
	while (argv_cpy[i])
	{
		ft_atoi_push_swap(argv_cpy[i], &tmp[i]);
		i++;
	}
	free_strings(argv_cpy);
}

static void	__convert_strings_to_numbers(char **strings, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_atoi_push_swap(strings[i], &numbers[i]);
		i++;
	}
}

bool	array_storage(int argc, char **argv, t_stack *A, int size)
{
	int		*tmp;
	int		i;

	tmp = malloc(sizeof(int) * size);
	if (argc == 1)
		__partition_and_store_text(argv[0], tmp);
	else
		__convert_strings_to_numbers(argv, tmp, size);
	if (is_overlap(tmp, size))
	{
		free(tmp);
		return (false);
	}
	coordinate_compression(tmp, size);
	i = size;
	while (i != 0)
	{
		push(A, tmp[i - 1]);
		i--;
	}
	free(tmp);
	return (true);
}
