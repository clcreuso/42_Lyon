/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:55:55 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/18 20:51:59 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_rev_sudoku(char **sudoku);
void	ft_print_sudoku(char **sudoku);
void	ft_print_rev_sudoku(char **sudoku);
char	**ft_make_sudoku(char **sudoku1, char **sudoku2, int y, int x);
char	**ft_init_sudoku2(char **sudoku1, char **sudoku2);
int		ft_cmp_sudoku(char **sudoku1, char **sudoku2);
int		ft_resolve_sudoku(char **sudoku, char **tab, int p);
int		ft_resolve_sudoku2(char **sudoku, char **tab, int p);
int		ft_chk_square(char **sudoku, char nb, int y, int x);
int		ft_chk_square2(char **sudoku, char nb, int y, int x);
int		ft_chk_col(char **sudoku, char nb, int x);
int		ft_chk_col2(char **sudoku, char nb, int x);
int		ft_chk_line(char **sudoku, char nb, int y);
int		ft_chk_line2(char **sudoku, char nb, int y);
int		ft_chk_args(char **arg);
int		ft_strlen(char *str);
int		ft_check_valid1(char **sudoku, char **tab, int p);
int		ft_first_line(char *str);
int		ft_check_valid2(char **sudoku);
int		ft_check_print(char **sudoku, int y, int x);

#endif
