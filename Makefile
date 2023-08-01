.PHONY: all fclean re clean
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
FSANI		= -fsanitize=address -g
SRCS		= src/*.c src/*/*.c
OBJS		= $(SRCS:.c=.o)
PUSH_SWAP	= main/push_swap.c
TEST_ONE	= main/test_1.c
TEST_TWO	= main/test_2.c
TEST_THREE	= main/test_3.c
LIBFT		= libft/*.c
PRINTF		= ft_printf/*.c

push_swap:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(PUSH_SWAP) $(LIBFT) $(PRINTF)

test1:
	$(CC) $(CFLAGS) $(FSANI) -o test $(SRCS) $(TEST_ONE) $(LIBFT) $(PRINTF)

test2:
	$(CC) $(CFLAGS) $(SRCS) $(TEST_TWO) $(LIBFT) $(PRINTF)

test3:
	$(CC) $(FSANI) -o test $(SRCS) $(TEST_THREE) $(LIBFT) $(PRINTF)

norm:
	@norminette -R CheckForbiddenSorceHeader $(SRCS)
