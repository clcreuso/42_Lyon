/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:25:41 by clcreuso          #+#    #+#             */
/*   Updated: 2017/09/22 19:48:20 by clcreuso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*tab2;
	int	a;

	a = 0;
	tab2 = malloc(sizeof(int) * (length + 1));
	if (tab2 == NULL)
		return (NULL);
	while (a < length)
	{
		tab2[a] = f(tab[a]);
		a++;
	}
	return (tab2);
}
