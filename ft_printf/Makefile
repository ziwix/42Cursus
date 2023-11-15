CC=clang
MAKE=make
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS=srcs/ft_printf.c srcs/ft_parsing.c srcs/ft_utils.c \
		srcs/ft_print_chars.c srcs/ft_print_numbers.c
HEADER=srcs/ft_printf.h
OBJS=$(SRCS:.c=.o)
LIBFT = libft/libft.a

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $(OBJS)

$(LIBFT):
	$(MAKE) -C libft all
	cp $(LIBFT) $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

re: fclean all

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

clean:
	rm -rf *.o */*.o


.PHONY: all clean fclean re