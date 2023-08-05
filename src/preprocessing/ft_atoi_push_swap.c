/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakaham <etakaham@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:01:05 by etakaham          #+#    #+#             */
/*   Updated: 2023/08/05 17:08:03 by etakaham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static unsigned int	ft_abs(int n)
{
	unsigned int	result;

	if (n < 0)
		result = (unsigned int)(-1 * n);
	else
		result = (unsigned int)n;
	return (result);
}

static int	__handle_sign(const char *str, bool *minus_sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus_sign = true;
		str++;
	}
	if (*str == '\0')
		return (2);
	else if (*minus_sign)
		return (1);
	else
		return (0);
}

static bool	__string_number(const char *str, unsigned int *num, bool minus_sign)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		*num *= 10;
		*num += str[i] - '0';
		if ((!minus_sign && *num > INT_MAX) || (*num > ft_abs(INT_MIN)))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_atoi_push_swap(const char *str, int *n)
{
	unsigned int	num;
	bool			minus_sign;

	minus_sign = false;
	if (__handle_sign(str, &minus_sign) == 1)
		str++;
	else if (__handle_sign(str, &minus_sign) == 2)
		return (false);
	num = 0;
	if (!__string_number(str, &num, minus_sign))
		return (false);
	if (minus_sign)
		num *= -1;
	*n = num;
	return (true);
}
