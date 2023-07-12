# include <stdio.h>
# include "push_swap.h"

int main(void)
{
	int	a[5];

	a[0] = 0;
	a[1] = 1;
	a[2] = 4;
	a[3] = 9;
	a[4] = 16;
	printf("----before----\n");
	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
	printf("\n");
	sa(a);
	printf("----after----\n");
	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
	printf("\n");
	return (0);
}
