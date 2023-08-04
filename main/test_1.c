# include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int	array_size;
	t_stack	*A;
	t_stack	*B;

	array_size = 0;
	/**
	 * argvが正しいのかどうか → "1 2 3 4" or 1 2 3 4
	 * argv が正しくない場合の例 → "" or " " or "a 2 3 4" or INT_MAX以上 or INT_MIN以下 or 1 2 c 4 5 or     
	 * argc, argv は初めの "./a.out" の部分を除くためにargc - 1, argv[1] から始める
	 * array_size に数字の要素数を入れる(要素数ココ大事)
	 * つまり、"1 2 3 4 5" だとarray_size = 5になる
	*/
	if (!is_correct_argu(argc - 1, &argv[1], &array_size))
		return (1);
	/**
	 * stackA, stackBのメモリを確保する
	 * もしもメモリの確保に失敗したら(mallocの返り値がNULLである場合)return (1)
	*/
	if (!create_double_stack(array_size, &A, &B))
		return (1);
	/**
	 * Aにargvの文字列を数値に変えて格納する
	 * "1 2 3 4" の場合と 1 2 3 4 の場合に分けて処理を行う
	 * つまりargcの値によって変更される
	*/
	if (!array_storage(argc - 1, &argv[1], A, array_size))
		return (1);
	sort_maximum(A, B);
	return (0);
}
