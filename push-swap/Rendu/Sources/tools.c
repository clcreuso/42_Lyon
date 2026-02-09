/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 22:06:37 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 22:06:37 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		ft_print_error_ps(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

void	ft_free_stack(int **stack)
{
	free(SA);
	free(SB);
	free(stack);
}

int		ft_tablen(char **tab)
{
	int	ret;

	ret = 0;
	if (!tab)
		return (0);
	while (tab[ret])
		ret++;
	return (ret);
}

void	ft_free_tab(char ***tab)
{
	int y;

	y = -1;
	if (!(*tab))
		return ;
	while ((*tab)[++y])
		ft_strdel(&(*tab)[y]);
	if ((*tab))
		free(*tab);
}

void	ft_rev_stack(int **stack)
{
	int swap;
	int start;
	int	end;

	start = 1;
	end = stack[A][0] - 1;
	while (end > start)
	{
		swap = stack[A][end];
		stack[A][end] = stack[A][start];
		stack[A][start] = swap;
		start++;
		end--;
	}
}
