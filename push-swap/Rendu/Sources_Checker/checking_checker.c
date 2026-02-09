/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checking_checker.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 18:58:06 by clcreuso     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 18:58:06 by clcreuso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_option(char *line)
{
	if (ft_strcmp(line, OP1) && ft_strcmp(line, OP2) && ft_strcmp(line, OP3) &&
		ft_strcmp(line, OP4) && ft_strcmp(line, OP5) && ft_strcmp(line, OP6) &&
		ft_strcmp(line, OP7) && ft_strcmp(line, OP8) && ft_strcmp(line, OPA) &&
		ft_strcmp(line, OPB) && ft_strcmp(line, OPC))
		return (1);
	else
		return (0);
}

void	ft_edit_stack(int **stack, char *ln)
{
	if (!(ft_strcmp(ln, OP1)) && SB[0] > 1)
		ft_push_a(stack);
	if (!(ft_strcmp(ln, OP2)) && SA[0] > 1)
		ft_push_b(stack);
	if ((!(ft_strcmp(ln, OP3)) || !(ft_strcmp(ln, OPA))) && SA[0] > 2)
		ft_swap_a(stack);
	if ((!(ft_strcmp(ln, OP4)) || !(ft_strcmp(ln, OPA))) && SB[0] > 2)
		ft_swap_b(stack);
	if ((!(ft_strcmp(ln, OP5)) || !(ft_strcmp(ln, OPB))) && SA[0] > 2)
		ft_rot_a(stack);
	if ((!(ft_strcmp(ln, OP6)) || !(ft_strcmp(ln, OPB))) && SB[0] > 2)
		ft_rot_b(stack);
	if ((!(ft_strcmp(ln, OP7)) || !(ft_strcmp(ln, OPC))) && SA[0] > 1)
		ft_revrot_a(stack);
	if ((!(ft_strcmp(ln, OP8)) || !(ft_strcmp(ln, OPC))) && SB[0] > 1)
		ft_revrot_b(stack);
}

char	*ft_checker(int **stack, char **cmd)
{
	int	y;

	y = -1;
	SB = (int *)malloc(sizeof(int) * (SA[0]));
	SB[0] = 1;
	while (cmd && cmd[++y])
	{
		if (ft_check_option(cmd[y]))
			return ("KO");
		ft_edit_stack(stack, cmd[y]);
	}
	if (SB[0] > 1)
		return ("KO");
	y = 0;
	while ((++y + 1) < SA[0])
		if (SA[y] <= SA[y + 1])
			return ("KO");
	return ("OK");
}
