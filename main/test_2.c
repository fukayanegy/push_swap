# include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		array_size;
	t_stack	*A;
	t_stack	*B;

	array_size = 0;
	if (!is_correct_argu(argc - 1, &argv[1], &array_size))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!create_double_stack(array_size, &A, &B))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!array_storage(argc - 1, &argv[1], A, array_size))
	{
		ft_printf("Error\n");
		stack_free(A, B);
		return (0);
	}
	sort_maximum(A, B);
	stack_free(A, B);
	return (0);
}

#include <libc.h>
__attribute__((destructor))
static void destructor()
{
	system("leaks -q a.out");
}
