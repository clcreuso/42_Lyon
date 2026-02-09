/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_push_swap.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 16:39:50 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/18 16:39:50 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		ft_usage_checker(int **stack)
{
	ft_putendl_fd("checker: need two or more arguments", 2);
	ft_putendl_fd("usage1: ./checker \"nb1 nb2 nb3 ...\"", 2);
	ft_putendl_fd("usage2: ./checker nb1 nb2 nb3 ...", 2);
	free(stack);
	return (0);
}

void	ft_norm_free(int **stack, char **cmd, char *line)
{
	free(SA);
	free(line);
	free(stack);
	ft_free_tab(&cmd);
	ft_putendl_fd("Error", 2);
}

int		ft_check_line(char *line)
{
	if (ft_strcmp(line, "pa") && ft_strcmp(line, "pb") &&
		ft_strcmp(line, "sa") && ft_strcmp(line, "sb") &&
		ft_strcmp(line, "ss") && ft_strcmp(line, "ra") &&
		ft_strcmp(line, "rb") && ft_strcmp(line, "rr") &&
		ft_strcmp(line, "rra") && ft_strcmp(line, "rrb") &&
		ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

char	**ft_fill_all_options(char **cmd, char *line)
{
	char	**ret;
	int		y;

	y = -1;
	if (!cmd)
		y = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_tablen(cmd) + 2));
	while (cmd && cmd[++y])
		ret[y] = ft_strdup(cmd[y]);
	ret[y++] = ft_strdup(line);
	ret[y] = NULL;
	ft_free_tab(&cmd);
	ft_strdel(&line);
	return (ret);
}

int		main(int argc, char **argv)
{
	int		**stack;
	char	**cmd;
	char	*line;

	stack = (int **)malloc(sizeof(int *) * (2));
	if (argc == 1)
		return (ft_usage_checker(stack));
	if (ft_fill_ps(argc, argv, &stack))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_check_line(line))
		{
			ft_norm_free(stack, cmd, line);
			return (0);
		}
		cmd = ft_fill_all_options(cmd, line);
	}
	ft_printf("%s\n", ft_checker(stack, cmd));
	ft_free_stack(stack);
	ft_free_tab(&cmd);
	return (0);
}
