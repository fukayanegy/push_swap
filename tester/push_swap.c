#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	int		value;
	int		i;
	size_t	size;
	t_stack	*stackA;
	t_stack	*stackB;

	if (is_error(argc, argv))
		return (1);
	size = argc - 1;
	stackA = create_stack(size);
	stackB = create_stack(size);
	i = argc;
	while (i > 1)
	{
		value = ft_atoi(argv[i - 1]);
		push(stackA, value);
		i--;
	}
	if (is_overlap(stackA))
		return (1);
	sort_maximum(stackA, stackB);
	stack_free(stackA, stackB);
	return (0);
}
