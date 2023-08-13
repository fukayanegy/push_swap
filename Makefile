.PHONY: all fclean re clean
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
FSANI		= -fsanitize=address -g
SRCS		= src/*/*.c
OBJS		= $(SRCS:.c=.o)
PUSH_SWAP	= main/push_swap.c
TEST_ZERO	= main/test_0.c
TEST_ONE	= main/test_1.c
TEST_TWO	= main/test_2.c
TEST_THREE	= main/test_3.c
PRINTER		= main/print_stack.c
LIBFT		= libft/*.c
PRINTF		= ft_printf/*.c

all:$(NAME)

push_swap:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(PUSH_SWAP) $(LIBFT) $(PRINTF)

test0:
	$(CC) $(FSANI) -o test_zero $(SRCS) $(TEST_ZERO) $(LIBFT) $(PRINTF) $(PRINTER)

test1:
	$(CC) $(CFLAGS) $(FSANI) -o test_one $(SRCS) $(TEST_ONE) $(LIBFT) $(PRINTF) $(PRINTER)

test2:
	$(CC) $(CFLAGS) $(SRCS) $(TEST_TWO) $(LIBFT) $(PRINTF) $(PRINTER)

test3:
	$(CC) $(FSANI) -o test_three $(SRCS) $(TEST_THREE) $(LIBFT) $(PRINTF) $(PRINTER)

clean:
	rm -r *.dSYM

norm:
	@norminette -R CheckForbiddenSorceHeader $(SRCS)
