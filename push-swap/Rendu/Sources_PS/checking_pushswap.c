/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_algo.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 15:55:42 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 15:55:42 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_order(int **stack)
{
	int cur;

	cur = 0;
	while (SA[++cur])
		if (SA[cur] != (SA[cur + 1] + 1))
			return (1);
	return (0);
}

int		ft_check_num(int **stack)
{
	int cur;

	cur = -1;
	if (SA[ENDA] == 0)
		return (1);
	while (cur++ < 5 && cur < SA[0])
	{
		if (SA[ENDA - cur] == (SA[1] + 1))
			return (1);
	}
	return (0);
}

int		ft_check_end(int **stack)
{
	int cur;

	cur = 1;
	if (SB[0] > 1)
		return (1);
	while (cur++ < SA[0])
		if (SA[cur - 1] != (SA[cur] + 1))
			break ;
	if (cur == SA[0])
		return (0);
	return (1);
}

int		ft_check_end_split(int *stack, t_sa info, int choice)
{
	int cur;

	cur = 0;
	while (++cur < stack[0])
	{
		if (choice == A && stack[cur] >= info.min && stack[cur] < info.mid)
			return (1);
		if (choice == B && stack[cur] > info.mid)
			return (1);
	}
	return (0);
}
