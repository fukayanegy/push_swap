.PHONY: all fclean re clean
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= src/command/move_element.c src/command/push.c src/command/reverse_rotate.c src/command/rotate.c src/command/swap.c src/preprocessing/array_storage.c src/preprocessing/coordinate_compression.c src/preprocessing/copy_int_array.c src/preprocessing/free_strings.c src/preprocessing/ft_atoi_push_swap.c src/preprocessing/is_correct_argu.c src/preprocessing/is_overlap.c src/preprocessing/stack_free.c src/preprocessing/stack_maker.c src/sort_src/max_min.c src/sort_src/maximum_swap_algorithm.c src/sort_src/maximum_swap_utils.c src/sort_src/median.c src/sort_src/sort.c src/sort_src/sorted_checkers.c src/sort_src/swap_algorithm.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c ft_printf/ft_printf.c ft_printf/print_c.c ft_printf/print_di.c ft_printf/print_p.c ft_printf/print_s.c ft_printf/print_u.c ft_printf/print_xX.c

MAIN		= main/push_swap.c

all:$(NAME)

OBJS		= $(SRCS:.c=.o)

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re:fclean all

