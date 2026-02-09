/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Operations_00.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 22:07:59 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 22:07:59 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_a(int **stack)
{
	int	end;

	stack[B][0] -= 1;
	end = stack[B][0];
	stack[A][stack[A][0]] = stack[B][end];
	stack[A][0] += 1;
}

void	ft_push_b(int **stack)
{
	int	end;

	stack[A][0] -= 1;
	end = stack[A][0];
	stack[B][stack[B][0]] = stack[A][end];
	stack[B][0] += 1;
}

void	ft_swap_a(int **stack)
{
	int swap;
	int	end;

	end = (stack[A][0] - 1);
	swap = stack[A][end];
	stack[A][end] = stack[A][end - 1];
	stack[A][end - 1] = swap;
}

void	ft_swap_b(int **stack)
{
	int swap;
	int	end;

	end = (stack[B][0] - 1);
	swap = stack[B][end];
	stack[B][end] = stack[B][end - 1];
	stack[B][end - 1] = swap;
}
