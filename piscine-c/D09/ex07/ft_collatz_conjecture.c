/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 08:23:59 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/16 10:57:54 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_flight_time(unsigned int base, unsigned int time)
{
	if (base == 1)
		return (time);
	if ((base % 2) == 1)
		return (ft_flight_time((base * 3) + 1, time + 1));
	if ((base % 2) == 0)
		return (ft_flight_time((base / 2), time + 1));
	return (0);
}

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	unsigned int flight_t;

	flight_t = ft_flight_time(base, 0);
	return (flight_t);
}
