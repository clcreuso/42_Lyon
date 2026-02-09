/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   short_resolve.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 22:00:08 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 22:00:08 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_tree(int **stack)
{
	if (SA[2] > SA[1] && SA[2] > SA[3])
		ft_modif_stack(stack, 7);
	if (SA[3] > SA[1] && SA[3] > SA[2])
		ft_modif_stack(stack, 5);
	if (SA[ENDA] > SA[ENDA - 1])
		ft_modif_stack(stack, 3);
}

void	ft_clean_four(int **stack)
{
	if (SA[1] < SA[2] && SA[1] < SA[3] && SA[1] < SA[4])
		ft_modif_stack(stack, 7);
	while (SA[4] > SA[1] || SA[4] > SA[2] || SA[4] > SA[3])
		ft_modif_stack(stack, 5);
	ft_modif_stack(stack, 2);
	ft_clean_tree(stack);
	ft_modif_stack(stack, 1);
}

void	ft_clean_five(int **stack)
{
	if (SA[1] == 0 || SA[1] == 1)
		ft_modif_stack(stack, 7);
	while (SA[5] != 0 && SA[5] != 1)
		ft_modif_stack(stack, 5);
	ft_modif_stack(stack, 2);
	ft_clean_four(stack);
	ft_modif_stack(stack, 1);
	if (SA[5] > SA[4])
		ft_modif_stack(stack, 3);
}

void	ft_short_resolve(int **stack)
{
	if (!(ft_check_end(stack)))
		return ;
	if (SA[0] == 3 && SA[ENDA] > SA[ENDA - 1])
		ft_modif_stack(stack, 3);
	if (SA[0] == 4)
		ft_clean_tree(stack);
	if (SA[0] == 5)
		ft_clean_four(stack);
	if (SA[0] == 6)
		ft_clean_five(stack);
}
