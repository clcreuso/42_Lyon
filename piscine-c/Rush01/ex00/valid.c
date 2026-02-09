/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 21:17:39 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/18 21:17:43 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_chk_square2(char **sudoku, char nb, int y, int x)
{
	int	cp_y;
	int cp_x;
	int chk;

	chk = 0;
	cp_y = y - (y % 3);
	cp_x = x - (x % 3);
	y = cp_y;
	while (y < cp_y + 3)
	{
		x = cp_x;
		while (x < cp_x + 3)
		{
			if (nb == sudoku[y][x])
				chk++;
			x++;
		}
		y++;
	}
	if (chk == 1)
		return (1);
	return (0);
}

int		ft_chk_line2(char **sudoku, char nb, int y)
{
	int cp_x;
	int chk;

	chk = 0;
	cp_x = 0;
	while (cp_x < 9)
	{
		if (nb == sudoku[y][cp_x])
			chk++;
		cp_x++;
	}
	if (chk == 1)
		return (1);
	return (0);
}

int		ft_chk_col2(char **sudoku, char nb, int x)
{
	int cp_y;
	int chk;

	chk = 0;
	cp_y = 0;
	while (cp_y < 9)
	{
		if (nb == sudoku[cp_y][x])
			chk++;
		cp_y++;
	}
	if (chk == 1)
		return (1);
	return (0);
}

int		ft_check_valid1(char **sudoku, char **tab, int p)
{
	char	nb;
	int		val;
	int		y;
	int		x;

	val = 0;
	nb = 0;
	y = p / 9;
	x = p % 9;
	if (y == 9)
		return (0);
	if (tab[y][x] == 0)
		return (ft_check_valid1(sudoku, tab, p + 1));
	nb = sudoku[y][x];
	val += ft_chk_line2(sudoku, nb, y);
	val += ft_chk_col2(sudoku, nb, x);
	val += ft_chk_square2(sudoku, nb, y, x);
	if (val == 3)
		return (ft_check_valid1(sudoku, tab, p + 1));
	else
		return (1);
}

int		ft_resolve_sudoku2(char **sudoku, char **tab, int p)
{
	char	nb;
	int		y;
	int		x;

	y = p / 9;
	x = p % 9;
	nb = '1';
	if (p == -1)
		return (1);
	if (tab[y][x] == 1)
		return (ft_resolve_sudoku2(sudoku, tab, p - 1));
	while (nb <= '9')
	{
		if (ft_chk_line(sudoku, nb, y) && ft_chk_col(sudoku, nb, x) &&
				ft_chk_square(sudoku, nb, y, x))
		{
			sudoku[y][x] = nb;
			if (ft_resolve_sudoku2(sudoku, tab, p - 1))
				return (1);
		}
		nb++;
	}
	sudoku[y][x] = '0';
	return (0);
}
