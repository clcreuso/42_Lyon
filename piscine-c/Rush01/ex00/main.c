/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:32:44 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/18 20:45:32 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_job(char **sudoku1, char **tab2, int rev)
{
	char **sudoku2;

	sudoku2 = 0;
	sudoku2 = ft_init_sudoku2(sudoku1, sudoku2);
	ft_resolve_sudoku2(sudoku2, tab2, 80);
	ft_resolve_sudoku(sudoku1, tab2, 0);
	if (ft_cmp_sudoku(sudoku1, sudoku2) && ft_check_print(sudoku1, 0, 0))
	{
		if (rev == 1)
			ft_print_rev_sudoku(sudoku1);
		else
			ft_print_sudoku(sudoku1);
	}
	else
		ft_putstr("Error\n");
}

int		main(int argc, char **argv)
{
	char	**tab2;
	int		rev;

	rev = 0;
	tab2 = 0;
	if (argc == 10)
	{
		if ((rev = ft_first_line(argv[1])))
			ft_rev_sudoku(argv + 1);
		tab2 = ft_make_sudoku(argv + 1, tab2, 0, 0);
		if (ft_chk_args(argv + 1) || ft_check_valid1(argv + 1, tab2, 0))
			ft_putstr("Error\n");
		else
			ft_job(argv + 1, tab2, rev);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
