/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Operations_01.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 22:08:20 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 22:08:20 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	ft_rot_a(int **stack)
{
	int swap1;
	int swap2;
	int x;

	x = 1;
	swap1 = stack[A][x];
	swap2 = stack[A][x + 1];
	while (++x < stack[A][0])
	{
		stack[A][x] = swap1;
		swap1 = swap2;
		swap2 = stack[A][x + 1];
	}
	stack[A][1] = swap1;
}

void	ft_rot_b(int **stack)
{
	int swap1;
	int swap2;
	int x;

	x = 1;
	swap1 = stack[B][x];
	swap2 = stack[B][x + 1];
	while (++x < stack[B][0])
	{
		stack[B][x] = swap1;
		swap1 = swap2;
		swap2 = stack[B][x + 1];
	}
	stack[B][1] = swap1;
}

void	ft_revrot_a(int **stack)
{
	int swap1;
	int swap2;
	int x;

	x = (stack[A][0] - 1);
	swap1 = stack[A][x];
	swap2 = stack[A][x - 1];
	stack[A][x] = stack[A][1];
	while (--x > 1)
	{
		stack[A][x] = swap1;
		swap1 = swap2;
		swap2 = stack[A][x - 1];
	}
	stack[A][1] = swap1;
}

void	ft_revrot_b(int **stack)
{
	int swap1;
	int swap2;
	int x;

	x = (stack[B][0] - 1);
	swap1 = stack[B][x];
	swap2 = stack[B][x - 1];
	stack[B][x] = stack[B][1];
	while (--x > 1)
	{
		stack[B][x] = swap1;
		swap1 = swap2;
		swap2 = stack[B][x - 1];
	}
	stack[B][1] = swap1;
}
