# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 13:01:14 by clcreuso          #+#    #+#              #
#    Updated: 2017/09/21 21:02:43 by clcreuso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC = do_op.c tools.c

NAME = do-op

CFLAGS = -Wall -Wextra -Werror

all: create

create:
	$(CC) -o $(NAME) $(CFLAGS) $(SRC)
clean:
	rm -rf $(NAME)
