/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:37:22 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/21 21:10:41 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_chk_operator(char *str)
{
	char	c;
	int		a;

	a = 0;
	c = str[0];
	while (str[a])
		a++;
	if (a != 1)
		return (1);
	if (c == '*' || c == '+' || c == '-' || c == '/' || c == '%')
		return (0);
	return (1);
}

int		ft_do_op(int nb1, int nb2, char c)
{
	if (c == '+')
		return (nb1 + nb2);
	if (c == '-')
		return (nb1 - nb2);
	if (c == '*')
		return (nb1 * nb2);
	if (c == '%')
		return (nb1 % nb2);
	if (c == '/')
		return (nb1 / nb2);
	return (0);
}

int		main(int ac, char **av)
{
	int nb;

	if (ac == 4)
	{
		if (ft_chk_operator(av[2]))
		{
			ft_putstr("0\n");
			return (0);
		}
		if (av[2][0] == '%' && ft_atoi(av[3]) == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		if (av[2][0] == '/' && ft_atoi(av[3]) == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		nb = ft_do_op(ft_atoi(av[1]), ft_atoi(av[3]), av[2][0]);
		ft_putnbr(nb);
		ft_putchar('\n');
	}
	return (0);
}
