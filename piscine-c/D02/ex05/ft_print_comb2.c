/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:33:30 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/10 09:04:58 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_init_tab(int a, int *str)
{
	int i;

	i = 0;
	while (i < a)
	{
		str[i] = 0;
		i++;
	}
}

void	ft_printtab(int a, int b, int c, int d)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(' ');
	ft_putchar(c + 48);
	ft_putchar(d + 48);
	if (a == 9 && b == 8)
		b = 42;
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_check_comb2(int a, int b, int c, int d)
{
	while (c < 10)
	{
		if (d > 9)
		{
			d = 0;
			c++;
		}
		if (c < 10)
			ft_printtab(a, b, c, d);
		d++;
	}
}

void	ft_print_comb2(void)
{
	int tab[4];

	ft_init_tab(4, tab);
	tab[3] = 1;
	while (tab[0] <= 9)
	{
		ft_check_comb2(tab[0], tab[1], tab[2], tab[3]);
		tab[1]++;
		if (tab[1] == 10)
		{
			tab[0]++;
			tab[1] = 0;
			tab[2] = tab[0];
		}
		if (tab[1] == 9)
		{
			tab[3] = 0;
			tab[2] = tab[0] + 1;
		}
		else
			tab[3] = tab[1] + 1;
	}
}
