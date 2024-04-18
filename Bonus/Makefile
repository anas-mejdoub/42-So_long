SRCS = main.c parsing.c flood_fill.c render_map.c \
so_long_utils.c handle_moves.c check_errs.c parse_utils.c
OBJBS = $(SRCS:.c=.o)
NAME = ../so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	@make -C ../libft
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJBS) ../libft/libft.a
	@echo "\033[1;32mthe Bonus target has been mad with success\033[0m"

%.o : %.c push_swap_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJBS)
	@echo "\033[1;31mthe bonus part object files had been deleted\033[0m"

fclean : clean
	rm -rf $(NAME)
	@echo "\033[1;31mthe bonus part target has been deleted\033[0m"
re : fclean all