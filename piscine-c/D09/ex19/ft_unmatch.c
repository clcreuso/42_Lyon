/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:28:42 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/16 16:41:13 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int a;
	int b;
	int c;

	c = 0;
	b = 0;
	a = 0;
	while (a < length)
	{
		while (b < length)
		{
			if (b == a)
				b++;
			if (tab[a] == tab[b])
				c++;
			b++;
		}
		if (c == 1)
			c = 0;
		else
			return (tab[a]);
		a++;
	}
}
