.PHONY: all fclean re clean
NAME	= push_swap.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
FSANI	= -fsanitize=address -g
SRCS	= src/*.c src/command/*.c
OBJS	= $(SRCS:.c=.o)
PUSH_SWAP	= tester/push_swap.c
TEST = tester/test.c
TEST_TWO = tester/test2.c
LIBFT	= libft/ft_atoi.c libft/ft_isdigit.c libft/ft_memcpy.c
PRINTF	= ft_printf/*.c

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

t:
	$(CC) $(CFLAGS) $(FSANI) -o test $(SRCS) $(TEST) $(LIBFT) $(PRINTF)

test:
	$(CC) $(CFLAGS) $(FSANI) -o test $(SRCS) $(TEST_TWO) $(LIBFT) $(PRINTF)

norm:
	@norminette -R CheckForbiddenSorceHeader $(SRCS)
