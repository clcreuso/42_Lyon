/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 20:11:00 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/12 10:34:49 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_param(char a, char b)
{
	if (a == ' ')
		return (0);
	if ((a == '-' || a == '+') && !(b <= '9' && b >= '0'))
		return (1);
	if (a == '-' || a == '+')
		return (0);
	return (1);
}

int		ft_atoi(char *str)
{
	int		a;
	int		nb;
	float	neg;

	a = 0;
	nb = 0;
	neg = 0;
	while (!(str[a] <= '9' && str[a] >= '0'))
		if (ft_check_param(str[a], str[a + 1]))
			return (nb);
		else
			a++;
	if (str[a - 1] == '-')
		neg = -1;
	while (str[a] <= '9' && str[a] >= '0' && str[a] != '\0')
		nb = (nb * 10) + (str[a++] - '0');
	if (neg < 0)
		return (nb * neg);
	return (nb);
}
