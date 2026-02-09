/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:05:10 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/15 19:34:57 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_hour(int hour1, int hour2, char h1, char h2)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %c.M. AND %d.00 %c.M.\n", hour1, h1, hour2, h2);
}

void	ft_takes_place(int hour)
{
	if (hour == 24 || hour == 0)
		ft_print_hour(12, 1, 'A', 'A');
	if (hour == 12)
		ft_print_hour(12, 1, 'P', 'P');
	if (hour == 11)
		ft_print_hour(11, 12, 'A', 'P');
	if (hour == 23)
		ft_print_hour(11, 12, 'P', 'A');
	if (hour >= 1 && hour <= 10)
		ft_print_hour(hour, hour + 1, 'A', 'A');
	if (hour >= 13 && hour <= 22)
		ft_print_hour(hour % 12, (hour % 12) + 1, 'P', 'P');
}
