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
	printf("=====before sort_list=====\n");
	print_stack(A);
	printf("==========================\n");
	printf("============max===========\n");
	printf("%d\n", stack_max(A));
	printf("==========================\n");
	sort_maximum2(A, B);
	printf("=======sorted_list========\n");
	print_stack(A);
	print_stack(B);
	printf("==========================\n");
	return (0);
}
