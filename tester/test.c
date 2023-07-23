#include "../include/push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		ft_printf("%d ", stack->array[i]);
		i++;
	}
	ft_printf("\n");
}

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
	printf("=====================\n");
	print_stack(stackA);
	print_stack(stackB);
	if (is_sortedB(stackA))
		printf("ok\n");
	else
		printf("no\n");
	printf("=====================\n");
	sort_five(stackA, stackB);
	printf("---------\n");
	print_stack(stackA);
	print_stack(stackB);
	if (is_sortedB(stackA))
		printf("ok\n");
	else
		printf("no\n");
	printf("=====================\n");

	shift_down(stackA);
	stack_free(stackA, stackB);
	return (0);
}
