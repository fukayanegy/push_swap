#include "../include/push_swap.h"
#include <stdio.h>

// main関数内でstackのmallocをするタイミングでargcによって確保数を変えているので、""で区切られている場合だと正しくメモリを確保することができない。それは変えておく必要がある。一応fsanitizeを切ると直る
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

bool	hoge(int argc, char **argv, t_stack *stackA)
{
	int		i;
	int		value;
	char	**argv_cpy;

	if (argc <= 1)
		return (false);
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ') == NULL)
			return (false);
		else
		{
			argv_cpy = ft_split(argv[1], ' ');
			i = 0;
			while (argv_cpy[i] != NULL)
				i++;
			printf("========while copy=======\n");
			while (i)
			{
				value = ft_atoi(argv_cpy[i - 1]);
				printf("%d\n", value);
				push(stackA, value);
				i--;
			}
			printf("======================\n");
			return (true);
		}
	}
	i = argc;
	while (i > 1)
	{
		value = ft_atoi(argv[i - 1]);
		push(stackA, value);
		i--;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;
	t_stack	*stackB;

	stackA = create_stack(200);
	stackB = create_stack(argc - 1);
	hoge(argc, argv, stackA);
	print_stack(stackA);
	return 0;
}
