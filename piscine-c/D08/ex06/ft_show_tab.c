/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:59:45 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/20 18:53:00 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

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

void	ft_print_words_tables(char **tab)
{
	int a;
	int b;

	a = 0;
	while (tab[a])
	{
		b = 0;
		while (tab[a][b])
		{
			ft_putchar(tab[a][b]);
			b++;
		}
		ft_putchar('\n');
		a++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
}

void	ft_show_tab(struct s_stock_par *par)
{
	int a;

	a = 0;
	while (par[a].str)
	{
		ft_putstr(par[a].copy);
		ft_putchar('\n');
		ft_putnbr(par[a].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[a].tab);
		a++;
	}
}
