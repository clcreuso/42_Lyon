# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/05/25 17:12:33 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2019/08/17 19:31:06 by clement     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

GCC_FLAGS = -f macho64

NASM = nasm

NASM_FLAGS = -f macho64

NAME = libfts.a

NAME_TEST = unit_tests

NAME_CAT = ft_cat

DIR_SRC = Sources/

DIR_INC = Includes/

DIR_TESTS = Tests/

FILES_INC = libfts.h

FILES_SRC =	ft_bzero.s ft_isalpha.s ft_isdigit.s ft_strcat.s ft_isalnum.s \
			ft_isascii.s ft_isprint.s ft_toupper.s ft_tolower.s ft_strlen.s \
			ft_puts.s ft_putchar.s ft_putstr.s ft_memset.s ft_memcpy.s \
			ft_strdup.s ft_cat.s
			
FILES_TEST = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			 ft_isprint.c ft_memcpy.c ft_memset.c ft_strcat.c ft_strdup.c \
			 ft_strlen.c ft_tolower.c ft_toupper.c print_functions.c \
			 unit_tests.c

SRC = 	$(addprefix $(DIR_SRC), $(FILES_SRC))

INC =	$(addprefix $(DIR_INC), $(FILES_INC))

TESTS =	$(addprefix $(DIR_TESTS), $(FILES_TEST))

FT_CAT = $(addprefix $(DIR_TESTS), ft_cat.c)

OBJ =	$(SRC:.s=.o)

CURSOR = 0

NB_FILES = $(words $(SRC))

all: $(NAME) test

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "\r\033[0;32m✅️   make $(NAME) 100%%\033[0m\033[K\n"

./%.o: ./%.s $(INC)
	@$(eval CURSOR=$(shell echo $$(($(CURSOR)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURSOR)*100/$(NB_FILES)))))
	@printf "\033[0;32m⌛️   make $(NAME) $(PERCENT)%%\033[0m\033[K\r"
	@$(NASM) $(NASM_FLAGS) $< -o $@

test:
	@$(CC) -I $(DIR_INC) $(NAME) $(TESTS) -o $(NAME_TEST)
	@printf "\r\033[0;32m✅️   make $(NAME_TEST) 100%%\033[0m\033[K\n"
	@$(CC) -I $(DIR_INC) $(NAME) $(FT_CAT) -o $(NAME_CAT)
	@printf "\r\033[0;32m✅️   make $(NAME_CAT) 100%%\033[0m\033[K\n"
	
clean:
	@printf "\r\033[38;5;202m🗑️   clean $(NAME)\033[0m\033[K\n";
	@rm -rf $(OBJ)
	@rm -rf $(NAME_TEST)
	@rm -rf $(NAME_CAT)

fclean: clean
	@printf "\r\033[38;5;196m🗑️   fclean $(NAME)\033[0m\033[K\n";
	@rm -rf $(NAME)
	@rm -rf $(NAME_CAT)
	@rm -rf $(NAME_TEST)

re: fclean all