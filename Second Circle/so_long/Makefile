#Program related variables
NAME= so_long
CL= clang
CFLAGS= -Wall -Wextra -Werror

#Paths for libs
LIBFT= libft/libft.a
PRINTF= ft_printf/libftprintf.a
MLX42= MLX42/

#Files
HEADERS= test_mlx42.h
SRCS= test_mlx42.c
LIBMLX= $(MLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS= ${SRCS:.c=.o}

#Rules

#Launching all rules
all : libmlx ftprintf libft $(NAME)

#Compile all libs and so_long
$(NAME) : $(OBJS)
	$(CL) $(OBJS) $(HEADERS) $(LIBMLX) $(LIBFT) $(PRINTF)
	mv a.out $(NAME)

#Build MLX42
libmlx :
	cmake $(MLX42) -B $(MLX42)/build && make -C $(MLX42)/build -j4

#Build ft_printf
ftprintf :
	make -C ft_printf all

#Build libft
libft :
	make -C libft all bonus

#Compile all so_long files
%.o: %.c $(HEADER)
	$(CL) $(CFLAGS) $< -c -o $@

#Clean All .o
clean :
	rm -rf *.o *.gch
	make -C ft_printf clean
	make -C libft clean

#Clean all .o and executable
fclean : clean
	rm -rf $(NAME)
	make -C ft_printf fclean
	make -C libft fclean

#Clean and remake all
re : clean all

.PHONY : all, clean, fclean, re, libmlx, ftprintf, libft