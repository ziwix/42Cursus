CC=clang
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS=ft_printf.c ft_parsing.c ft_utils.c ft_print_chars.c ft_print_numbers.c
#SRCB=
HEADER=ft_printf.h
OBJS=$(SRCS:.c=.o)
LIBFT = libft/libft.a
#OBJB=$(SRCB:.c=.o)


$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C libft all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

re: fclean all

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

clean:
	rm -rf *.o

#bonus: $(OBJB)
#	ar rcs $(NAME) $(OBJB)

.PHONY: all clean fclean re #bonus