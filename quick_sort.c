#include <stdio.h>

void	ft_sort(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSort(int arr[], int left, int right)
{
	int	pivot;
	int	i;
	int	j;
	int	partitionIndex;

	// left よりrightが小さくないとダメ
	if (left > right)
		return ;
	// pivot はいちばん後ろの値
	pivot = arr[right];
	// i, j には配列のもっとも低いインデックスを渡す
	i = left;
	j = left;
	// いちばん小さいインデックスからいちばん大きいインデックスに変える
	// 配列の中でいちばん後ろの値よりも小さい数字は
	while (j < right)
	{
		if (arr[j] <= pivot)
		{
			printf("first sort i = %d = %d, j = %d = %d\n", i, arr[i], j, arr[j]);
			ft_sort(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	i--;
	ft_sort(&arr[i + 1], &arr[right]);
	partitionIndex = i + 1;
	// 初めの要素から分ける部分まで
	// 分ける部分から終わりの要素まで
	quickSort(arr, left, partitionIndex - 1);
	quickSort(arr, partitionIndex + 1, right);
}

int main()
{
	int arr[] = {12, 4, 5, 6, 7, 3, 1, 15, 13};
	int n = sizeof(arr) / sizeof(arr[0]);

	// 32
	printf("%zu\n", sizeof(arr));
	// 4
	printf("%zu\n", sizeof(arr[0]));
	// 8
	// nは要素数
	printf("%d\n", n);
	printf("Unsorted array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 並び替えを行う配列・初めの要素・終わりの要素
	// 初回の値はleft = 0, right = last
	quickSort(arr, 0, n - 1);

	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

