/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:10:20 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/15 16:06:36 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

void	ft_print_base(char *str, int neg)
{
	int a;

	if (neg < 0)
		ft_putchar('-');
	a = ft_strlen(str);
	a--;
	while (str[a])
	{
		ft_putchar(str[a]);
		a--;
	}
}

int		ft_check_base(char *base, int a, int b)
{
	if (ft_strlen(base) == 1)
		return (0);
	while (base[b])
	{
		if (base[a] == base[b])
			return (0);
		if (base[b] == '+' || base[b] == '-')
			return (0);	
		b++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char str[105];
	int neg;
	int a;
	int b;

	b = 0;
	neg = 1;
	a = ft_strlen(base);
	if (nbr < 0)
	{	
		nbr = -nbr;
		neg = -1;
	}
	while (nbr >= 1)
	{
		str[b] = base[nbr % a];
		nbr /= a;
		b++;
	}
	str[b] = '\0';
	if (ft_check_base(base, 0, 1))
		ft_print_base(str, neg);
}
