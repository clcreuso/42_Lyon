/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 15:29:32 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 15:29:32 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MULTI_H
# define MULTI_H

# define MINI -2147483648
# define MAXI 2147483647
# define SA (stack[A])
# define SB (stack[B])
# define A 0
# define B 1

# include "../Libft/Includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             operations_00.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void	ft_push_a(int **stack);
void	ft_push_b(int **stack);
void	ft_swap_a(int **stack);
void	ft_swap_b(int **stack);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             operations_01.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void	ft_rot_a(int **stack);
void	ft_rot_b(int **stack);
void	ft_revrot_a(int **stack);
void	ft_revrot_b(int **stack);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                parsing.c                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		ft_tab_is_numeric(char **tab);
int		ft_error_dup(int *stack, int stop);
int		*ft_atoi_tab(int argc, char **argv);
int		ft_fill_ps(int argc, char **argv, int ***stack);
int		ft_free_exit(int ***stack, char **cmd, int error, int check);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                                 tools.c                                    ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		ft_tablen(char **tab);
int		ft_print_error_ps(void);
void	ft_free_tab(char ***tab);
void	ft_rev_stack(int **stack);
void	ft_free_stack(int **stack);

#endif
