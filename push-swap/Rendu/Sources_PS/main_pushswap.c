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

#include "push_swap.h"

int		ft_usage_ps(int **stack)
{
	ft_putendl_fd("checker: need two or more arguments", 2);
	ft_putendl_fd("usage1: ./push_swap \"nb1 nb2 nb3 ...\"", 2);
	ft_putendl_fd("usage2: ./push_swap nb1 nb2 nb3 ...", 2);
	free(stack);
	return (0);
}

void	ft_print_opt(int **stack, int opt)
{
	if (opt == 1 && SB[0] > 1)
		ft_putstr("pa\n");
	else if (opt == 2 && SA[0] > 1)
		ft_putstr("pb\n");
	else if (opt == 3 && SA[0] > 2)
		ft_putstr("sa\n");
	else if (opt == 4 && SB[0] > 2)
		ft_putstr("sb\n");
	else if (opt == 9 && SB[0] > 2 && SA[0] > 2)
		ft_putstr("ss\n");
	else if (opt == 5 && SA[0] > 2)
		ft_putstr("ra\n");
	else if (opt == 6 && SB[0] > 2)
		ft_putstr("rb\n");
	else if (opt == 10 && SB[0] > 2 && SA[0] > 2)
		ft_putstr("rr\n");
	else if (opt == 7 && SA[0] > 2)
		ft_putstr("rra\n");
	else if (opt == 8 && SB[0] > 2)
		ft_putstr("rrb\n");
	else if (opt == 11 && SB[0] > 2 && SA[0] > 2)
		ft_putstr("rrr\n");
}

void	ft_modif_stack(int **stack, int opt)
{
	ft_print_opt(stack, opt);
	if (opt == 1 && SB[0] > 1)
		ft_push_a(stack);
	if (opt == 2 && SA[0] > 1)
		ft_push_b(stack);
	if ((opt == 3 || opt == 9) && SA[0] > 2)
		ft_swap_a(stack);
	if ((opt == 4 || opt == 9) && SB[0] > 2)
		ft_swap_b(stack);
	if ((opt == 5 || opt == 10) && SA[0] > 2)
		ft_rot_a(stack);
	if ((opt == 6 || opt == 10) && SB[0] > 2)
		ft_rot_b(stack);
	if ((opt == 7 || opt == 11) && SA[0] > 1)
		ft_revrot_a(stack);
	if ((opt == 8 || opt == 11) && SB[0] > 1)
		ft_revrot_b(stack);
}

int		main(int argc, char *argv[])
{
	int		**stack;
	int		**test;

	stack = (int **)malloc(sizeof(int *) * (2));
	if (argc == 1)
		return (ft_usage_ps(stack));
	if (ft_fill_ps(argc, argv, &stack))
		return (0);
	stack = ft_params_push_swap(stack);
	test = stack;
	if (SA[0] > 6)
		ft_long_resolve(stack);
	else
		ft_short_resolve(stack);
	ft_free_stack(test);
	ft_putchar(0);
	return (0);
}
