/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checker.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 19:02:53 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 19:02:53 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "multi.h"
# define OP1 "pa"
# define OP2 "pb"
# define OP3 "sa"
# define OP4 "sb"
# define OP5 "ra"
# define OP6 "rb"
# define OP7 "rra"
# define OP8 "rrb"
# define OPA "ss"
# define OPB "rr"
# define OPC "rrr"

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                              main_checker.c                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		ft_usage_checker(int **stack);
char	**ft_fill_all_options(char **cmd, char *line);
void	ft_norm_free(int **stack, char **cmd, char *line);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                             checking_checker.c                             ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int		ft_check_option(char *line);
void	ft_edit_stack(int **stack, char *ln);
char	*ft_checker(int **stack, char **cmd);

#endif
