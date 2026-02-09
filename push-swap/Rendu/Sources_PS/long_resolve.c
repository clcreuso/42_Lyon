/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 16:06:23 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 16:06:23 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_sb(int **stack)
{
	if (SB[ENDB - 2] > SB[ENDB - 1] && SB[ENDB - 2] > SB[ENDB])
		ft_modif_stack(stack, 8);
	if (SB[ENDB - 1] > SB[ENDB - 2] && SB[ENDB - 1] > SB[ENDB])
		ft_modif_stack(stack, 4);
	if (SB[ENDB] > SB[ENDB - 1] && SB[ENDB] > SB[ENDB - 2])
		ft_modif_stack(stack, 1);
}

void	ft_split_sa(int **stack, int *mid)
{
	t_sa	info;
	int		cur;

	cur = 1;
	info = ft_search_not_rank(stack[A], mid, A);
	while (ft_check_end_split(stack[A], info, A))
	{
		if ((SA[ENDA] >= info.min && SA[ENDA] < info.mid) ||
			SA[ENDA] == (SB[ENDB] + 1))
			ft_modif_stack(stack, 2);
		else
			ft_modif_stack(stack, 5);
	}
}

void	ft_split_sb(int **stack)
{
	t_sa	info;
	int		cur;

	cur = 1;
	info = ft_search_not_rank(stack[B], NULL, B);
	if (info.min > 0)
		while (ft_check_order(stack))
			ft_modif_stack(stack, 7);
	while (ft_check_end_split(stack[B], info, B))
	{
		if (SB[0] > 20 && SB[2] > info.mid && SB[2] > SB[ENDB] &&
			SB[2] > SB[ENDB - 1])
			ft_modif_stack(stack, 8);
		if (SB[0] > 3 && SB[1] > info.mid && SB[1] > SB[ENDB] &&
			SB[1] > SB[ENDB - 1])
			ft_modif_stack(stack, 8);
		if (SB[ENDB] > info.mid)
			ft_modif_stack(stack, 1);
		else
			ft_modif_stack(stack, 6);
	}
	if (SB[0] > 4)
		ft_split_sb(stack);
}

void	ft_put_away(int **stack)
{
	if (SB[0] == 4)
		ft_clean_sb(stack);
	if (SB[0] == 3 && SB[ENDB] < SB[ENDB - 1])
		ft_modif_stack(stack, 4);
	while (SB[0] != 1)
		ft_modif_stack(stack, 1);
	while (1)
	{
		if (!(ft_check_num(stack)) || !(ft_check_end(stack)) ||
		(SA[ENDA] == 0 && SB[0] > 1))
			break ;
		if (SA[ENDA - 1] == (SA[1] + 1))
			ft_modif_stack(stack, 3);
		if (SA[1] == (SA[ENDA] - 1) || (SA[ENDA] == 0 && ft_check_end(stack)))
			ft_modif_stack(stack, 5);
		else
			ft_modif_stack(stack, 2);
	}
}

void	ft_long_resolve(int **stack)
{
	int		mid;

	mid = 0;
	while (ft_check_end(stack))
	{
		if (SB[0] == 1)
			ft_split_sa(stack, &mid);
		ft_split_sb(stack);
		ft_put_away(stack);
	}
}
