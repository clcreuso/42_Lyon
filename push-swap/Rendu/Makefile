# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 18:11:02 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2017/12/08 18:11:02 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

NAME_CHK = checker

NAME_PSW = push_swap

NAME_LIB = Libft/libft.a

C_FLAGS = -Wall -Wextra -Werror

DIR_LIB = Libft/

DIR_INC = Includes/

DIR_SRC = Sources/

DIR_PSW = Sources_PS/

DIR_CHK = Sources_Checker/

SRC =	  operations_00.c operations_01.c parsing.c tools.c

CHK_SRC = checking_checker.c main_checker.c  

PSW_SRC = checking_pushswap.c main_pushswap.c long_resolve.c \
		  params_pushswap.c short_resolve.c

SRC_CHK = $(addprefix $(DIR_CHK), $(CHK_SRC)) $(addprefix $(DIR_SRC), $(SRC))

SRC_PSW = $(addprefix $(DIR_PSW), $(PSW_SRC)) $(addprefix $(DIR_SRC), $(SRC))

OBJ_CHK = $(SRC_CHK:.c=.o)

OBJ_PSW = $(SRC_PSW:.c=.o) 

all: $(NAME_PSW) $(NAME_CHK)

$(NAME_PSW): $(OBJ_PSW) $(NAME_LIB)
	@$(CC) $(C_FLAGS) $(OBJ_PSW) -L $(DIR_LIB) -lft -o $(NAME_PSW) 
	@echo "\033[0;32m✅️   make push_swap.\033[0m"

$(NAME_CHK): $(OBJ_CHK) $(NAME_LIB)
	@$(CC) $(C_FLAGS) $(OBJ_CHK) -L $(DIR_LIB) -lft -o $(NAME_CHK) 
	@echo "\033[0;32m✅️   make checker.\033[0m"

$(NAME_LIB):
	@make -C $(DIR_LIB)	

./%.o: ./%.c
	@$(CC) $(C_FLAGS) -I $(DIR_INC) -o $@ -c $< 
	@echo "\033[0;32m✅️   $@ created.\033[0m"

clean:
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ_CHK)
	@rm -f $(OBJ_PSW)
	@echo "\033[38;5;202m🗑️   clean objects.\033[0m" 

fclean: clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME_CHK)
	@rm -f $(NAME_PSW)
	@echo "\033[38;5;196m🗑️   fclean checker.\033[0m"
	@echo "\033[38;5;196m🗑️   fclean push_swap.\033[0m"

re: fclean all
	