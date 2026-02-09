/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 10:58:41 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/11 18:44:33 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(int this, int len)
{
	int		a;
	char	*tab;

	a = 0;
	tab = "o-o";
	if (this == 1)
		tab = "| |";
	ft_putchar(tab[0]);
	while (a < len - 2)
	{
		ft_putchar(tab[1]);
		a++;
	}
	if (!(len <= 1))
		ft_putchar(tab[2]);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int a;

	a = 0;
	if (!(x <= 0 || y <= 0))
		ft_print_line(0, x);
	while (a < (y - 2) && !(x <= 0))
	{
		ft_print_line(1, x);
		a++;
	}
	if (!(y <= 1) && !(x <= 0))
		ft_print_line(0, x);
}
