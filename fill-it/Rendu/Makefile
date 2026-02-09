# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 14:12:42 by lotoussa          #+#    #+#              #
#    Updated: 2017/11/22 15:18:57 by clcreuso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Werror -Wextra -Wall

NAME = fillit

D_SRC = src/

D_LIBFT = libft/

SRC1 = 	check_tms.c convert_tms.c fillit_tools.c forced_solve.c main.c \
		init_struct.c tms_tools.c

SRC2= 	ft_bzero.c ft_next_sqrt.c ft_putendl.c ft_sqrt.c ft_strnew.c \
		ft_memalloc.c ft_putchar.c ft_putstr.c ft_strcmp.c ft_memset.c \
		ft_strlen.c

SRC_FILL = $(addprefix $(D_SRC), $(SRC1))

SRC_LIB = $(addprefix $(D_LIBFT), $(SRC2))

OBJ = $(SRC_FILL:.c=.o) $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "\033[0;32m✅️    Fillit executable created."

./%.o: ./%.c
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "\033[0;32m✅️    $@ created."

clean:
	@rm -f $(OBJ)
	@echo "\033[0;31m🗑️    Deleting object files." 

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m🗑️    Deleting fillit executable." 

re: fclean all
