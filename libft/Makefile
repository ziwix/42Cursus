CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
HEADER=libft.h
OBJS=$(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	$(CC) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all: $(NAME)

re: fclean all

fclean: clean
	rm -f $(NAME) libft.so

clean:
	rm -f $(OBJS)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	cc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re