NAME=so_long
all :
	@make -C ./Mandatory

bonus : 
	@make -C ./Bonus

clean :
	@make clean -C ./Mandatory
# @make clean -C ./Bonus

fclean :
# @make fclean -C ./Bonus
	@make fclean -C ./Mandatory

re :
	@make re -C ./Mandatory

.PHONY : bonus