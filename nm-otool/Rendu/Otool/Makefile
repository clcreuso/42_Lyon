# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 18:11:02 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2019/09/04 11:53:29 by clement     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

BIN = ../ft_otool
		
C_FLAGS = -Wall -Werror -Wextra

DIR_LIB = ../Libft/

DIR_SRC = Sources/

DIR_INC = Includes/

FILES_SRC = dump.c error.c header.c init.c main.c segment.c tools.c parse.c \
			free.c section.c cpu.c swap.c swap_header.c swap_command.c \
			swap_section.c

FILES_INC = ft_otool.h

INC = $(addprefix $(DIR_INC), $(FILES_INC))

SRC = $(addprefix $(DIR_SRC), $(FILES_SRC))

OBJ = $(SRC:.c=.o)

CURSOR = 0

NB_FILES = $(words $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	@$(CC) $(C_FLAGS) $(OBJ) -L $(DIR_LIB) -lft -o $(BIN)
	@printf "\r\033[0;32m✅️   make ft_otool 100%%\033[0m\033[K\n"

./%.o: ./%.c $(INC)
	@$(eval CURSOR=$(shell echo $$(($(CURSOR)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURSOR)*100/$(NB_FILES)))))
	@printf "\033[0;32m⌛️   make ft_otool $(PERCENT)%%\033[0m\033[K\r"
	@$(CC) $(C_FLAGS) -I $(DIR_INC) -o $@ -c $< 

clean:
	@if [ -e Sources/main.o ]; then \
		printf "\r\033[38;5;202m🗑️   clean ft_otool\033[0m\033[K\n";\
	fi;
	@rm -rf $(OBJ)

fclean: clean
	@if [ -e $(BIN) ]; then \
		printf "\r\033[38;5;196m🗑️   fclean ft_otool\033[0m\033[K\n"; \
	fi;
	@rm -rf $(BIN)

re: fclean all
