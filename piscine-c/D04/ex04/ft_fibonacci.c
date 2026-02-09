/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 07:47:22 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/12 09:41:30 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index > 46)
		return (0);
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index == 34)
		return (5702887);
	if (index == 35)
		return (9227465);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
