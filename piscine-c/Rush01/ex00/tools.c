/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 20:50:48 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/18 20:52:33 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

int		ft_chk_args(char **arg)
{
	int y;
	int x;

	y = 0;
	while (y <= 8)
	{
		if ((ft_strlen(arg[y])) != 9)
			return (1);
		x = 0;
		while (x <= 8)
		{
			if (!(arg[y][x] == '0' || (arg[y][x] <= '9' && arg[y][x] >= '1')))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

char	**ft_make_sudoku(char **sudoku1, char **sudoku2, int y, int x)
{
	sudoku2 = malloc(sizeof(char *) * 10);
	while (y <= 8)
	{
		x = 0;
		sudoku2[y] = malloc(sizeof(char *) * 10);
		while (x <= 8)
		{
			if (sudoku1[y][x] == '.')
			{
				sudoku1[y][x] = '0';
				sudoku2[y][x] = 0;
			}
			else
				sudoku2[y][x] = 1;
			x++;
		}
		y++;
	}
	return (sudoku2);
}

char	**ft_init_sudoku2(char **sudoku, char **sudoku2)
{
	int x;
	int y;

	y = 0;
	sudoku2 = malloc(sizeof(char *) * 10);
	while (y < 9)
	{
		x = 0;
		sudoku2[y] = malloc(sizeof(char) * 10);
		while (x < 9)
		{
			sudoku2[y][x] = sudoku[y][x];
			x++;
		}
		y++;
	}
	return (sudoku2);
}

int		ft_cmp_sudoku(char **sudoku1, char **sudoku2)
{
	int y;
	int x;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			if (sudoku1[y][x] != sudoku2[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
