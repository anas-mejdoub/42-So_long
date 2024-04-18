SRCS = main.c parsing.c flood_fill.c render_map.c \
so_long_utils.c handle_moves.c check_errs.c parse_utils.c
OBJBS = $(SRCS:.c=.o)
NAME = ../so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

all : $(NAME)

$(NAME) : $(OBJBS) so_long.h 
	make -C ../libft
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJBS) ../libft/libft.a
	@echo "\033[1;32mthe Mandatory target has been made with success\033[0m"
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make clean -C ../libft
	rm -rf $(OBJBS)
	@echo "\033[1;31mthe Mandatory part object files had been deleted\033[0m"

fclean : clean
	@make fclean -C ../libft
	rm -rf $(NAME)
	@echo "\033[1;31mthe Mandatory part target has been deleted\033[0m"
re : fclean all