.PHONY: all fclean re clean
NAME	= push_swap.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
FSANI	= -fsanitize=address -g
SRCS	= src/*.c src/command/*.c
OBJS	= $(SRCS:.c=.o)
MAIN	= tester/*.c
LIBFT	= libft/ft_atoi.c libft/ft_isdigit.c
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

re: fclean all

test:
	$(CC) $(CFLAGS) $(FSANI) -o push_swap $(SRCS) $(MAIN) $(LIBFT) $(PRINTF)

allclean: fclean
	rm a.out
	rm -r a.out*

norm:
	@norminette -R CheckForbiddenSorceHeader $(SRCS)
