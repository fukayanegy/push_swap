#include "../include/push_swap.h"

static unsigned int	ft_abs(int n)
{
	unsigned int	result;

	if (n < 0)
	{
		result = (unsigned int)(-1 * n);
	}
	else
		result = (unsigned int)n;
	return (result);
}

bool	ft_atoi_push_swap(const char *str, int *n)
{
	int				i;
	unsigned int	num;
	bool			minus_sign;

	minus_sign = false;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_sign = true;
		str++;
	}
	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		num *= 10;
		num += str[i] - '0';
		if ((!minus_sign && num > INT_MAX) || (num > ft_abs(INT_MIN)))
			return (false);
		i++;
	}
	if (minus_sign)
		num *= -1;
	*n = num;
	return (true);
}
