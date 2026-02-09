/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:46:35 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/21 21:07:45 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_atoi(char *s1)
{
	int neg;
	int nb;
	int a;

	a = 0;
	nb = 0;
	neg = 1;
	while (s1[a] == ' ')
		a++;
	if (s1[a] == '-' || s1[a] == '+')
		a++;
	if (s1[a - 1] == '-')
		neg = -1;
	while (s1[a] >= '0' && s1[a] <= '9')
		nb = (nb * 10) + (s1[a++] - '0');
	return (nb * neg);
}

void	ft_putnbr(int nb)
{
	int	a;

	a = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		a = 1;
	}
	if (nb < 0 && a != 1)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && a != 1)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	if (nb < 10 && a != 1)
		ft_putchar(nb + '0');
}
