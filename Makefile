NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c radix_sort.c algo.c chunksort.c disorder.c creat_stack.c \
       ft_atoi.c ft_printf.c ft_push.c ft_strcmp.c init_stack.c \
       tools1.c tools2.c upsidedown.c dysplay_stack.c list_utils.c \
	   ft_tri_slectif.c ft_search_min.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push.h ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
