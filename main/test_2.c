// this splict is original function checker
# include "../include/push_swap.h"

int	main(void)
{
	int	array[] = {30, 40, 10, 20, 50};
	int	size = 5;
	coordinate_compression(array, size);
	return (0);
}

#include <libc.h>
__attribute__((destructor))
static void destructor()
{
	system("leaks -q a.out");
}