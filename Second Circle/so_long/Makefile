CC=clang
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
SRCS=
HEADER=
OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

.PHONY: all clean fclean re bonus