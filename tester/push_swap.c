#include "../include/push_swap.h"

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

void	stack_free(t_stack *stackA, t_stack *stackB)
{
	free(stackA->array);
	free(stackA);
	free(stackB->array);
	free(stackB);
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
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		push(stackA, value);
		i++;
	}
	if (is_overlap(stackA))
		return (1);
	print_stack(stackA);
	shift_elements(stackA);
	print_stack(stackA);
	stack_free(stackA, stackB);
	return (0);
}
