#include "test.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return EXIT_FAILURE;
	}

	size_t size = argc - 1;
	t_stack *stackA = create_stack(size);
	t_stack *stackB = create_stack(size);

	for (int i = 1; i < argc; i++)
	{
		int value = atoi(argv[i]);
		push(stackA, value);
	}

	printf("stackA:\n");
	print_stack(stackA);
	printf("stackB:\n");
	print_stack(stackB);

	move_to_stack(stackA, stackB);

	printf("moved stackA to B:\n");
	printf("stackA:\n");
	print_stack(stackA);
	printf("stackB:\n");
	print_stack(stackB);

	free(stackA->array);
	free(stackA);
	free(stackB->array);
	free(stackB);

	return EXIT_SUCCESS;
}
