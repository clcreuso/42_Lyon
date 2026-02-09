/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unit_tests.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/16 15:16:18 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 10:41:50 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UNIT_TESTS_H
# define UNIT_TESTS_H

# include <time.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libfts.h"

# define ANOMALY	0
# define SUCCESS	1
# define FAILURE	2

# define RED		"\033[1;31m"
# define GREEN	    "\033[1;32m"
# define ORANGE	    "\033[1;33m"
# define STOP	    "\033[m"

# define MAN		1
# define WOMAN	    0

int		GENDER;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                Tests Part 1                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		ft_bzero_tests(void);
int		ft_strcat_tests(void);
int		ft_isalpha_tests(void);
int		ft_isdigit_tests(void);
int		ft_isalnum_tests(void);
int		ft_isascii_tests(void);
int		ft_isprint_tests(void);
int		ft_tolower_tests(void);
int		ft_toupper_tests(void);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                Tests Part 2                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		ft_strlen_tests(void);
int		ft_memset_tests(void);
int		ft_memcpy_tests(void);
int		ft_strdup_tests(void);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              Print functions                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void	print_avtar(int code);
void	print_result(int code, char *tests_name);

#endif
