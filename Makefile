SRCS = ./Mandatory/main.c ./Mandatory/parsing.c ./Mandatory/flood_fill.c
# SRCS_BONUS = ./Bonus/main_bonus.c ./Bonus/parsing_bonus.c ./Bonus/rules_bonus.c ./Bonus/rules2_bonus.c
OBJBS = $(SRCS:.c=.o)
# OBJBS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = so_long
# NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS) ./Mandatory/so_long.h 
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ./libft/libft.a

# bonus : $(OBJBS_BONUS) ./bonus/push_swap_bonus.h
# 	make -C ./libft
# 	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJBS_BONUS) ./libft/libft.a

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ./libft
	rm -rf $(OBJBS)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all