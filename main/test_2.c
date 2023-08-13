# include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int	array_size;
	t_stack	*A;
	t_stack	*B;

	array_size = 0;
	if (!is_correct_argu(argc - 1, &argv[1], &array_size))
		return (1);
	if (!create_double_stack(array_size, &A, &B))
		return (1);
	if (!array_storage(argc - 1, &argv[1], A, array_size))
		return (1);
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
