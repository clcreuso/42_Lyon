/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:32:27 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/18 20:27:14 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
}

void	ft_print_sudoku(char **sudoku)
{
	int y;
	int x;

	y = 0;
	while (y <= 8)
	{
		x = 0;
		while (x <= 8)
		{
			ft_putchar(sudoku[y][x]);
			if (x < 8)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	ft_print_rev_sudoku(char **sudoku)
{
	int y;
	int x;

	y = 8;
	while (y >= 0)
	{
		x = 8;
		while (x >= 0)
		{
			ft_putchar(sudoku[y][x]);
			if (x > 0)
				ft_putchar(' ');
			x--;
		}
		ft_putchar('\n');
		y--;
	}
}
