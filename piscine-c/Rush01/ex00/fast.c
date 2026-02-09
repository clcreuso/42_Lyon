/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:36:07 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/18 20:46:16 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_first_line(char *str)
{
	int a;
	int b;

	b = 0;
	a = 0;
	while (str[a])
	{
		if (str[a] == '.')
			b++;
		a++;
	}
	if (b == 9)
		return (1);
	return (0);
}

void	ft_rev_sudoku(char **sudoku)
{
	char	swap;
	int		a;
	int		b;

	a = 0;
	b = 80;
	while (a != 40 && b != 41)
	{
		swap = sudoku[a / 9][a % 9];
		sudoku[a / 9][a % 9] = sudoku[b / 9][b % 9];
		sudoku[b / 9][b % 9] = swap;
		a++;
		b--;
	}
}
