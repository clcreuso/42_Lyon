# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 18:11:02 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2019/08/08 13:28:51 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

BIN = ../ft_nm
		
C_FLAGS = -Wall -Werror -Wextra

DIR_LIB = ../Libft/

DIR_SRC = Sources/

DIR_INC = Includes/

FILES_SRC = dump.c error.c free.c init.c parse.c segment.c symbol.c symtab.c \
			tools.c header.c main.c cpu.c swap_header.c swap_command.c swap.c \
			swap_section.c swap_nlist.c

FILES_INC = ft_nm.h

INC = $(addprefix $(DIR_INC), $(FILES_INC))

SRC = $(addprefix $(DIR_SRC), $(FILES_SRC))

OBJ = $(SRC:.c=.o)

CURSOR = 0

NB_FILES = $(words $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	@$(CC) $(C_FLAGS) $(OBJ) -L $(DIR_LIB) -lft -o $(BIN)
	@printf "\r\033[0;32m✅️   make ft_nm 100%%\033[0m\033[K\n"

./%.o: ./%.c $(INC)
	@$(eval CURSOR=$(shell echo $$(($(CURSOR)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURSOR)*100/$(NB_FILES)))))
	@printf "\033[0;32m⌛️   make ft_nm $(PERCENT)%%\033[0m\033[K\r"
	@$(CC) $(C_FLAGS) -I $(DIR_INC) -o $@ -c $< 

clean:
	@if [ -e Sources/main.o ]; then \
		printf "\r\033[38;5;202m🗑️   clean ft_nm\033[0m\033[K\n";\
	fi;
	@rm -rf $(OBJ)

fclean: clean
	@if [ -e $(BIN) ]; then \
		printf "\r\033[38;5;196m🗑️   fclean ft_nm\033[0m\033[K\n"; \
	fi;
	@rm -rf $(BIN)

re: fclean all
