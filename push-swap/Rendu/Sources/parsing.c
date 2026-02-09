/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 22:12:24 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 22:12:24 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		ft_error_dup(int *stack, int stop)
{
	int	x;

	x = 0;
	while (++x < stop)
		if (stack[x] == stack[stop])
			return (1);
	return (0);
}

int		ft_free_exit(int ***stack, char **cmd, int error, int check)
{
	if (check == 1 || check == 2)
		free((*stack));
	if (check == 2)
		ft_free_tab(&cmd);
	if (error)
		return (ft_print_error_ps());
	return (1);
}

int		ft_tab_is_numeric(char **tab)
{
	int x;
	int	y;

	y = -1;
	while (tab[++y])
	{
		x = -1;
		if (ft_strstr(tab[y], "  "))
			return (0);
		while (tab[y][++x])
			if (!(ft_isdigit(tab[y][x])))
				if ((tab[y][0] != '-' && tab[y][0] != '+') || x != 0)
					return (0);
	}
	if (tab[0])
		return (1);
	return (0);
}

int		*ft_atoi_tab(int argc, char **argv)
{
	intmax_t	max;
	int			*stack;
	int			y;

	y = -1;
	stack = (int *)malloc(sizeof(int) * (argc + 2));
	while (argv[++y])
	{
		max = ft_atoimax(argv[y]);
		stack[y + 1] = ft_atoi(argv[y]);
		if ((max > MAXI || max < MINI) || ft_error_dup(stack, (y + 1)))
		{
			free(stack);
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
	}
	stack[0] = (argc + 1);
	return (stack);
}

int		ft_fill_ps(int argc, char **argv, int ***stack)
{
	char	**cmd;

	if (argc == 2 && (cmd = ft_strsplit(argv[1], 32)))
	{
		if (!(ft_tab_is_numeric(cmd)))
			return (ft_free_exit(stack, cmd, 1, 2));
		(*stack)[A] = ft_atoi_tab(ft_tablen(cmd), cmd);
		ft_free_tab(&cmd);
	}
	else if (argc > 2 && !(ft_tab_is_numeric(argv + 1)))
		return (ft_free_exit(stack, cmd, 1, 1));
	if (argc > 2)
		(*stack)[A] = ft_atoi_tab(ft_tablen(argv + 1), argv + 1);
	if ((*stack)[A] == NULL)
		return (ft_free_exit(stack, cmd, 0, 1));
	ft_rev_stack(*stack);
	return (0);
}
