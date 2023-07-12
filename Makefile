.PHONY: all fclean re clean
NAME	= push_swap.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
FSANI	= -fsanitize=address -g
SRCS	= swap_element.c swap_element_utils.c
OBJS	= $(SRCS:.c=.o)
MAIN	= test.c

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
	$(CC) $(CFLAGS) $(FSANI) $(SRCS) $(MAIN)

norm:
	@norminette -R CheckForbiddenSorceHeader $(SRCS)