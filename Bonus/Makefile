SRCS = main_bonus.c parsing_bonus.c flood_fill_bonus.c render_map_bonus.c \
parse_utils_bonus.c handle_moves_bonus.c check_errs_bonus.c so_long_utils_bonus.c counter_bonus.c \
enemy_bonus.c
OBJBS = $(SRCS:.c=.o)
NAME = ../so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

all : $(NAME)

$(NAME) : $(OBJBS) so_long_bonus.h
	@make -C ../libft
	$(CC) $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJBS) ../libft/libft.a
	@echo "\033[1;32mthe Bonus target has been mad with success\033[0m"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJBS)
	@echo "\033[1;31mthe bonus part object files had been deleted\033[0m"

fclean : clean
	rm -rf $(NAME)
	@echo "\033[1;31mthe bonus part target has been deleted\033[0m"
re : fclean all