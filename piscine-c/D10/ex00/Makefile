# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 13:01:14 by clcreuso          #+#    #+#              #
#    Updated: 2017/09/21 13:04:20 by clcreuso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRCS = srcs/

INCLUDES = includes/

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

SRCO = $(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all: create

create:
	$(CC) $(CFLAGS) $(addprefix $(SRCS), $(SRC))
	mv $(SRCO) $(INCLUDES)
	ar rc $(NAME) $(addprefix $(INCLUDES), $(SRCO))
	ranlib $(NAME)
clean:
	rm -rf $(addprefix $(INCLUDES), $(SRCO))
fclean: clean
	rm -rf $(NAME)
re: fclean all
