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
	t_stack	*stackA;
	t_stack	*stackB;

	stackA = create_stack(200);
	stackB = create_stack(200);
	if (!hoge(argc, argv, stackA))
	{
		printf("error\n");
		return (1);
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
	sort_maximum(stackA, stackB);
	print_stack(stackA);
	print_stack(stackB);
	if (is_sortedB(stackA))
		printf("ok\n");
	else
		printf("no\n");
	printf("=====================\n");
	stack_free(stackA, stackB);
	return (0);
}
