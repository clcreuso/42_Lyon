/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:32:08 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/18 20:50:24 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_chk_line(char **sudoku, char nb, int y)
{
	int cp_x;

	cp_x = 0;
	while (cp_x < 9)
	{
		if (nb == sudoku[y][cp_x])
			return (0);
		cp_x++;
	}
	return (1);
}

int		ft_chk_col(char **sudoku, char nb, int x)
{
	int cp_y;

	cp_y = 0;
	while (cp_y < 9)
	{
		if (nb == sudoku[cp_y][x])
			return (0);
		cp_y++;
	}
	return (1);
}

int		ft_chk_square(char **sudoku, char nb, int y, int x)
{
	int cp_y;
	int cp_x;

	cp_y = y - (y % 3);
	cp_x = x - (x % 3);
	y = cp_y;
	while (y < cp_y + 3)
	{
		x = cp_x;
		while (x < cp_x + 3)
		{
			if (nb == sudoku[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		ft_resolve_sudoku(char **sudoku, char **tab, int p)
{
	char	nb;
	int		y;
	int		x;

	y = p / 9;
	x = p % 9;
	nb = '1';
	if (p == 81)
		return (1);
	if (tab[y][x] == 1)
		return (ft_resolve_sudoku(sudoku, tab, p + 1));
	while (nb <= '9')
	{
		if (ft_chk_line(sudoku, nb, y) && ft_chk_col(sudoku, nb, x) &&
				ft_chk_square(sudoku, nb, y, x))
		{
			sudoku[y][x] = nb;
			if (ft_resolve_sudoku(sudoku, tab, p + 1))
				return (1);
		}
		nb++;
	}
	sudoku[y][x] = '0';
	return (0);
}

int		ft_check_print(char **sudoku, int y, int x)
{
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (!(sudoku[y][x] <= '9' && sudoku[y][x] >= '1'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
