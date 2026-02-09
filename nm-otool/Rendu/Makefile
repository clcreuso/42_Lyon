# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clement <clement@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/08 18:11:02 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2019/06/08 14:57:16 by clement     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all libft ft_nm ft_otool clean fclean re

CC = gcc

BIN_NM = ft_nm

BIN_OTOOL = ft_otool
		
C_FLAGS = -Wall -Wextra -Werror

DIR_ROOT = ./

DIR_LIB = Libft/

DIR_NM = Nm/

DIR_OTOOL = Otool/

all: libft ft_otool ft_nm

ft_nm: libft 
	@if !(make -q -C $(DIR_NM)); then \
		rm -rf $(BIN_NM);\
		make -C $(DIR_NM);\
	fi;

ft_otool: libft
	@if !(make -q -C $(DIR_OTOOL)); then \
		rm -rf $(BIN_OTOOL);\
		make -C $(DIR_OTOOL);\
	fi;

libft: 
	@if !(make -q -C $(DIR_LIB)); then \
		rm -f $(BIN_OTOOL); \
		rm -f $(BIN_NM); \
		make -C $(DIR_LIB);\
	fi;

clean:
	@make clean -C $(DIR_LIB)
	@make clean -C $(DIR_OTOOL)
	@make clean -C $(DIR_NM)

fclean: clean
	@make fclean -C $(DIR_LIB)
	@make fclean -C $(DIR_OTOOL)
	@make fclean -C $(DIR_NM)

re: fclean all
