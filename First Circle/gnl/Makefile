CC=clang
GFLAGS=-D BUFFER_SIZE=5
CFLAGS=-Wall -Wextra -Werror $(GFLAGS)
NAME=get_next_line.a
SRCS=get_next_line.c get_next_line_utils.c
HEADER=get_next_line.h
OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

.PHONY: all clean fclean re
