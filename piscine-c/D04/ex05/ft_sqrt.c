/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 09:12:58 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/12 09:14:22 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long int a;
	long long int nb2;

	a = 0;
	nb2 = nb;
	while (a++ < 1000)
		if (a * a == nb2)
			return (a);
		else if (a * a > nb2)
			return (0);
	a = nb / 1000;
	while ((a * a) > nb2)
		a = a / 2;
	while ((a * a) <= nb2)
		if (a * a == nb2)
			return (a);
		else
			a++;
	return (0);
}
