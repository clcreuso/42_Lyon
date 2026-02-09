/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unit_tests.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:56:48 by clement      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:37:40 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "unit_tests.h"

int	main(int argc, char const *argv[])
{
	srand(time(NULL));
	GENDER = rand() % 2;
	print_result(ft_bzero_tests(), "ft_bzero_tests");
	print_result(ft_strcat_tests(), "ft_strcat_tests");
	print_result(ft_isalnum_tests(), "ft_isalnum_tests");
	print_result(ft_isalpha_tests(), "ft_isalpha_tests");
	print_result(ft_isascii_tests(), "ft_isascii_tests");
	print_result(ft_isdigit_tests(), "ft_isdigit_tests");
	print_result(ft_isprint_tests(), "ft_isprint_tests");
	print_result(ft_tolower_tests(), "ft_tolower_tests");
	print_result(ft_toupper_tests(), "ft_toupper_tests");
	print_result(ft_strlen_tests(), "ft_strlen_tests");
	print_result(ft_memset_tests(), "ft_memset_tests");
	print_result(ft_memcpy_tests(), "ft_memcpy_tests");
	print_result(ft_strdup_tests(), "ft_strdup_tests");
	return (0);
}
